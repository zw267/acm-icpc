                                            
  //File Name: cf293E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月26日 星期二 22时38分15秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>

#define LL long long
#define fir first
#define sec second

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

struct Edge
{
	int to,next,cost;
};
Edge edge[MAXN << 1];
int head[MAXN],tot;
int c[MAXN];
int N,L,W;
LL ans;
int sub_size[MAXN];
bool cen[MAXN];
vector< pair<int,int> > ds,tds;

void init()
{
	memset(head,-1,sizeof head);
	memset(c,0,sizeof c);
	tot = 0;
	ans = 0;
	memset(cen,false,sizeof cen);
}

void addedge(int u,int v,int cost)
{
	edge[tot].to = v;
	edge[tot].cost = cost;
	edge[tot].next = head[u];
	head[u] = tot++;
}

inline int lb(int x)
{
	return x & (-x);
}

void update(int x,int add)
{
	while(x <= N){
		c[x] += add;
		x += lb(x);
	}
}

int query(int x)
{
	int res = 0;
	while(x > 0){
		res += c[x];
		x -= lb(x);
	}
	return res;
}

int get_sub_size(int u,int p)
{
	int tmp = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		tmp += get_sub_size(v,u);
	}
	sub_size[u] = tmp;
	return tmp;
}

pair<int,int> get_cen(int u,int p,int sum)
{
	pair<int,int> res = make_pair(INF,-1);
	int s = 1, m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	res = min(res ,make_pair(m,u));
	return res;
}

void dfs(int u,int p,int sumw,int suml,vector< pair<int,int> >& ds)
{
	if(sumw <= W && suml <= L){
		ans++;
	}
	else
		return ;
	ds.push_back(make_pair(sumw,suml));
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		if(sumw + edge[i].cost > W || suml + 1 > L)
			continue;
		dfs(v,u,sumw+edge[i].cost,suml+1,ds);
	}
}

LL get_pair(vector< pair<int,int> > & ds)
{
	LL res = 0;
	sort(ds.begin(),ds.end());
	//memset(c,0,sizeof c);
	for(int i=0;i<ds.size();i++){
		update(ds[i].sec,1);
	}
	int l = 0;
	int r = ds.size() - 1;
	while(l < r){
		update(ds[l].sec,-1);
		while(r > l && ds[l].fir + ds[r].fir > W){
			update(ds[r].sec,-1);
			r--;
		}
		if(l >= r)
			break;
		res += (LL)query(min(N,L - ds[l].sec));
		//puts("aaaaaaaaaaaaaaaa");
		l++;
	}
	if(l < ds.size() && query(ds[l].sec) - query(ds[l].sec - 1) == 1)
		update(ds[l].sec,-1);
	//for(int i=1;i<=N;i++){
	//	printf("%d ",query(i));
	//}
	//puts("");
	return res;
}

void solve_sub(int root)
{
	get_sub_size(root,root);
	if(sub_size[root] == 1)
		return ;
	int s = get_cen(root,root,sub_size[root]).sec;
	//printf("s = %d\n",s);
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve_sub(v);
	}

	ds.clear();

	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		tds.clear();
		//printf("ans = %d\n",ans);
		dfs(v,s,edge[i].cost,1,tds);
		//printf("ans = %d\n",ans);
		ans -= get_pair(tds);
		ds.insert(ds.end(),tds.begin(),tds.end());
	}
	ans += get_pair(ds);

	cen[s] = false;
}

int main()
{
	init();
	scanf("%d %d %d",&N,&L,&W);
	int p,tmp;
	for(int i=2;i<=N;i++){
		scanf("%d %d",&p,&tmp);
		addedge(p,i,tmp);
		addedge(i,p,tmp);
	}
	solve_sub(1);
	cout <<  ans << endl;

	return 0;
}
