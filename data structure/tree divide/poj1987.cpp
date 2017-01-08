                                            
  //File Name: poj1987.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月08日 星期二 17时59分53秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 40000+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,w,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;

bool cen[MAXN];
int sub_size[MAXN];
int ds[MAXN],tds[MAXN];
int tot_ds,tot_tds;
int K;
LL ans;

void init()
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
	ans = 0;
}

void addedge(int u,int v,int w)
{
	edge[total].to = v;
	edge[total].w = w;
	edge[total].next = head[u];
	head[u] = total++;
}

void init_sub_size(int u,int p)
{
	sub_size[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		init_sub_size(v,u);
		sub_size[u] += sub_size[v];
	}
}

pair<int,int> find_cen(int u,int p,int sum)
{
 	pair<int,int> res = make_pair(INF,-1);
	int s = 1,m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,find_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	res = min(res,make_pair(m,u));
	return res;
}

void dfs(int u,int p,int cost)
{
	tds[tot_tds++] = cost;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v] || v == p)
			continue;
		dfs(v,u,cost+edge[i].w);
	}
}

int bs(int cur,int r)
{
	int l = 0,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] > cur)
			r = mid;
		else
			l = mid;
	}
	if(ds[r] <= cur)
		return r + 1;
	return l + 1;
}

void solve(int u)
{
	init_sub_size(u,-1);
	if(sub_size[u] <= 1)
		return ;
	int s = find_cen(u,-1,sub_size[u]).second;
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve(v);
	}
	tot_ds = 0;
	ds[tot_ds++] = 0;
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		tot_tds = 0;
		dfs(v,s,edge[j].w);
		for(int i=0;i<tot_tds;i++){
			int cur = K - tds[i];
			//printf("s = %d  cur = %d  tds[i] = %d\n",s,cur,tds[i]);
			if(cur < 0)
				continue;
			ans += (LL)bs(cur,tot_ds-1);
		}
		for(int i=0;i<tot_tds;i++){
			ds[tot_ds++] = tds[i];
		}
		sort(ds,ds+tot_ds);
	}
	cen[s] = false;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		int u,v,w;
		char ch[3];
		init();
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %s",&u,&v,&w,ch);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		scanf("%d",&K);
		solve(1);
		cout << ans << endl;
	}
	return 0;
}
