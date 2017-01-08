                                            
  //File Name: spoj_ftour2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月12日 星期六 14时47分52秒
                           

//wa

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mp make_pair
#define num first
#define cost second

using namespace std;

const int MAXN = 200000+5;
const LL INF = 0x3f3f3f3f3f3f3f;

struct Seg{
	int ma,ly;
};
Seg seg[MAXN << 2];

struct Edge{
	int to,next,w;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;
int K,ans;
pair<int,int> ds[MAXN];
int tot_ds;
int sub_size[MAXN];
int is[MAXN];
bool cen[MAXN];

void init()
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
	memset(is,0,sizeof is);
}

void addedge(int u,int v,int w)
{
	edge[total].to = v;
	edge[total].w = w;
	edge[total].next = head[u];
	head[u] = total++;
}

void pushup(int rt)
{
	seg[rt].ma = max(seg[rt<<1].ma,seg[rt<<1|1].ma);
}

void pushdown(int rt)
{
	if(seg[rt].ly == 0){
		seg[rt<<1].ly = seg[rt<<1|1].ly = 0;
		seg[rt<<1].ma = seg[rt<<1|1].ma = 0;
		seg[rt].ly = -1;
	}
}

void update1(int p,int add,int l,int r,int rt)
{
	if(l == r){
		seg[rt].ma = max(seg[rt].ma,add);
		seg[rt].ly = -1;
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(rt);
	if(p <= m)
		update1(p,add,lson);
	else
		update1(p,add,rson);
	pushup(rt);
}

void update2(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r){
		seg[rt].ly = 0;
		seg[rt].ma = 0;
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(rt);
	if(L <= m)
		update2(L,R,lson);
	if(R > m)
		update2(L,R,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r)
		return seg[rt].ma;
	int m = (l + r) >> 1;
	pushdown(rt);
	int res = 0;
	if(L <= m)
		res =max(res,query(L,R,lson));
	if(R > m)
		res =max(res,query(L,R,rson));
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
	int s = 1, m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res, get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m ,sum - s);
	return res = min(res,mp(m,u));
}

void dfs(int u,int p,int num,int cost)
{
	if(num + is[u] > K)
		return ;
	ds[tot_ds++] = mp(num+is[u],cost);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs(v,u,num+is[u],cost+edge[i].w);
	}
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
	update2(1,K+1,1,K+1,1);
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		tot_ds = 0;
		dfs(v,s,0,edge[j].w);
		for(int i=0;i<tot_ds;i++){
			if(K - ds[i].num+1 < 1)
				continue;
			int cur = query(1,K-ds[i].num+1,1,K+1,1);
			ans = max(ans,cur + ds[i].cost);
		}
		for(int i=0;i<tot_ds;i++){
			if(ds[i].num > K)
				continue;
			update1(ds[i].num+1,ds[i].cost,1,K+1,1);
		}
	}
	update1(is[s]+1,0,1,K+1,1);
	ans = max(ans,query(1,K-is[s] + 1,1,K+1,1));
	cen[s] = false;
}

void solve(int n,int m)
{
	ans = 0;
	divide(1);
	update2(1,K+1,1,K+1,1);
	printf("%d\n",ans);
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d %d",&n,&K,&m);
	init();
	for(int i=1,u;i<=m;i++){
		scanf("%d",&u);
		is[u] = 1;
	}
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	solve(n,m);
	return 0;
}
