                                            
  //File Name: hdu5016.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月09日 星期三 19时56分42秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>

#define LL long long
#define d first
#define id second
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,w,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;
pair<int,int> ds[MAXN],tds[MAXN];
pair<int,int> pre[MAXN];
pair<int,int> f[MAXN][3];
pair<int,int> dis[MAXN];
int init_id[MAXN];
int ans[MAXN];
int son[MAXN];
int sub_size[MAXN];
bool cen[MAXN];
int is[MAXN];
int tot_tds,tot_ds;

void init(int n)
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
}

void addedge(int u,int v,int w)
{
	edge[total].to = v;
	edge[total].w = w;
	edge[total].next = head[u];
	head[u] = total++;
}

void dfs1(int u,int p)
{
	if(is[u]){
		f[u][1] = mp(0,u);
		son[u] = u;
	}
	else
		f[u][1] = mp(INF,-1);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)
			continue;
		dfs1(v,u);
		pair<int,int> cur = mp(f[v][1].d + edge[i].w,f[v][1].id);
		if(cur < f[u][1] || son[u] == -1){
			f[u][1] = cur;
			son[u] = v;
		}
	}
}

void dfs2(int u,int p)
{
	f[u][2] = mp(INF,-1);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)
			continue;
		dfs2(v,u);
		if(v == son[u])
			continue;
		pair<int,int> cur = mp(f[v][1].d + edge[i].w,f[v][1].id);
		if(cur < f[u][2])
			f[u][2] = cur;
	}
}

void dfs0(int u,int p)
{
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)
			continue;
		if(v == son[u]){
			f[v][0] = min(f[u][0],f[u][2]);
			f[v][0].d += edge[i].w;
		}
		else{
			f[v][0] = min(f[u][1],f[u][0]);
			f[v][0].d += edge[i].w;
		}
		dfs0(v,u);
	}
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
	pair<int,int> res = mp(INF,-1);
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
	return res = min(res,mp(m,u));
}

void dfs_tds(int u,int p,int cost)
{
	if(is[u])
		return ;
	dis[tot_tds] = mp(cost,u);
	tds[tot_tds++] = mp(pre[u].d - cost, pre[u].id);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs_tds(v,u,cost + edge[i].w);
	}
}

int bs(int ,int ,pair<int,int> ,pair<int,int> *);

void dfs_ds(int u,int p,int cost)
{
	if(is[u])
		return ;
	ans[u] += bs(0,tot_ds - 1,mp(cost,u),ds);	
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs_ds(v,u,cost + edge[i].w);
	}
}

int bs(int l,int r,pair<int,int> cur, pair<int,int> *ds)
{
	if(r < l)
		return 0;
	if(ds[r] <= cur)
		return 0;
	if(ds[l] > cur)
		return r + 1;
	int init_r = r;
	int mid;
	while(r  - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] <= cur)
			l = mid;
		else
			r = mid;
	}
	if(ds[l] > cur)
		return init_r - l + 1;
	return init_r - r + 1;
}

void divide(int u)
{
	get_sub_size(u,-1);
	int s = get_cen(u,-1,sub_size[u]).second;
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		divide(v);
	}
	if(is[s]){
		cen[s] = false;
		return ;
	}
	tot_ds = 0;
	ds[tot_ds++] = mp(pre[s].d,pre[s].id);
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		tot_tds = 0;
		dfs_tds(v,s,edge[j].w);
		sort(tds,tds + tot_tds);
		for(int i=0;i<tot_tds;i++){
			ans[dis[i].id] -= bs(0,tot_tds - 1,dis[i],tds);
		}
		for(int i=0;i<tot_tds;i++){
			ds[tot_ds++] = tds[i];
		}
	}
	sort(ds,ds + tot_ds);
	ans[s] += bs(0,tot_ds-1,mp(0,s),ds);
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		dfs_ds(v,s,edge[j].w);
	}
	cen[s] = false;
}

void solve(int n)
{
	memset(ans,0,sizeof ans);
	memset(son,-1,sizeof son);
	dfs1(1,-1);
	dfs2(1,-1);
	f[1][0] = mp(INF,-1);
	dfs0(1,-1);
	for(int i=1;i<=n;i++){
		pre[i] = min(f[i][0],f[i][1]);
	}
	//for(int i=1;i<=n;i++){
	//	printf("i = %d id = %d dis = %d\n",i,pre[i].id,pre[i].d);
	//}
	divide(1);
	//for(int i=1;i<=n;i++)
	//	printf("%d  ",ans[i]);
	int res = 0;
	for(int i=1;i<=n;i++)
		res = max(res,ans[i]);

	printf("%d\n",res);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		init(n);
		for(int i=1,u,v,w;i<n;i++){
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&is[i]);
		solve(n);
	}
	return 0;
}
