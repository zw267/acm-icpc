                                            
  //File Name: hdu4918.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月11日 星期五 22时37分57秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>

#define LL long long
#define d first
#define id second
#define fir first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;
vector<int> bit_1[MAXN],bit_2[MAXN];
int dis[MAXN];
int len_1[MAXN];
int len_2[MAXN];
int val[MAXN];
int sub_size[MAXN];
bool cen[MAXN];
vector< pair<int,int> > pre[MAXN];

void init(int n)
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
	for(int i=0;i<=n;i++){
		bit_1[i].clear();
		bit_2[i].clear();
		pre[i].clear();
		len_1[i] = 0;
		len_2[i] = 0;
	}
}

void addedge(int u,int v)
{
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

inline int lb(int x)
{
	return x & (-x);
}

void update(int x,int add,int len,vector<int> &bit)
{
	while(x <= len){
		bit[x] += add;
		x += lb(x);
	}
}

int query(int s,int x,int on,vector<int> &bit)
{
	if(on == 1 && x > len_1[s])
		x = len_1[s];
	if(on == 2 && x > len_2[s])
		x = len_2[s];
	int res = 0;
	while(x > 0){
		res += bit[x];
		x -= lb(x);
	}
	return res;
}

void get_sub_size(int u,int p)
{
	sub_size[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		get_sub_size(v,u);
		sub_size[u] += sub_size[v];
	}
}

pair<int,int> get_cen(int u,int p,int sum)
{
	pair<int,int> res = mp(MAXN,-1);
	int s = 1,m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	return min(res,mp(m,u));
}

void dfs1(int u,int p,int &ma)
{
	ma = max(ma,dis[u]);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs1(v,u,ma);
	}
}

void dfs2(int s,int u,int p,int on)
{
	if(on == 2){
		update(dis[u]+1,val[u],len_2[s],bit_2[s]);
	}
	else{
		update(dis[u]+1,val[u],len_1[s],bit_1[s]);
	}
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs2(s,v,u,on);
	}
}

void dfs3(int s,int u,int p,int cost)
{
	dis[u] = cost;
	pre[u].pb(mp(cost,s));
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs3(s,v,u,cost+1);
	}
}

void divide(int u,int pre_s)
{
	get_sub_size(u,-1);
	int s = get_cen(u,-1,sub_size[u]).sec;
	cen[s] = true;
	if(pre_s != -1){
		int ma = dis[s];
		dfs1(s,-1,ma);
		len_2[s] = ma + 1;
		for(int i=0;i<=ma+1;i++)
			bit_2[s].pb(0);
		dfs2(s,s,-1,2);
	}
	dfs3(s,s,0,0);
	int ma = 0;
	dfs1(s,-1,ma);
	len_1[s] = ma + 1;
	for(int i=0;i<=len_1[s];i++)
		bit_1[s].pb(0);
	dfs2(s,s,-1,1);
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		divide(v,s);
	}
}

void solve(int n,int q)
{
	divide(1,-1);
	char ch[3];
	for(int i=1;i<=q;i++){
		scanf("%s",ch);
		if(ch[0] == '!'){
			int v,x;
			scanf("%d %d",&v,&x);
			int cur = x - val[v];
			for(int i=0;i!=pre[v].size();i++){
				int id = pre[v][i].id;
				int d = pre[v][i].d;
				update(d+1,cur,len_1[id],bit_1[id]);
				if(i >= 1)
					update(pre[v][i-1].d+1,cur,len_2[id],bit_2[id]);
			}
			val[v] = x;
		}
		else{
			int v,dist;
			scanf("%d %d",&v,&dist);
			int ans = query(v,dist+1,1,bit_1[v]);
			for(int i=pre[v].size() - 2;i>=0;i--){
				int id = pre[v][i].id;
				int d = pre[v][i].d;
				ans += query(id,dist-d+1,1,bit_1[id]) - query(pre[v][i+1].id,dist-d+1,2,bit_2[pre[v][i+1].id]);
			}
			printf("%d\n",ans);
		}
	}
	return ;
}

int main()
{
	int n,q;
	while(~scanf("%d %d",&n,&q)){
		init(n);
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve(n,q);
	}
	return 0;
}
