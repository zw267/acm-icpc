                                            
  //File Name: spoj_free_tour_2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月28日 星期四 23时21分12秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

#define fir first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 200000+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,next,cost;
};
Edge edge[MAXN << 1];
int head[MAXN],tot;

struct Seg
{
	int ma,ly;
};
Seg seg[MAXN << 2];

int ans;
int is[MAXN];
int sub_size[MAXN];
bool cen[MAXN];
int N,K,M;

void init()
{
	memset(head,-1,sizeof head);
	tot = 0;
	memset(cen,false,sizeof cen);
	ans = 0;
	memset(is,0,sizeof is);
}

void addedge(int u,int v,int w)
{
	edge[tot].to = v;
	edge[tot].cost = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void pushup(int rt)
{
	seg[rt].ma = max(seg[rt<<1].ma,seg[rt<<1|1].ma);
}

void pushdown(int rt)
{
	if(seg[rt].ly != 0){
		seg[rt<<1].ma = seg[rt<<1|1].ma = seg[rt].ly;
		seg[rt<<1].ly = seg[rt<<1|1].ly = seg[rt].ly;
		seg[rt].ly = 0;
	}
}

void build(int l,int r,int rt)
{
	seg[rt].ma = -INF;
	seg[rt].ly = 0;
	if(l == r)
		return ;
	int m =(l+r) >> 1;
	build(lson);
	build(rson);
}

void update1(int L,int R,int add,int l,int r,int rt)
{
	if(L <= l && R >= r){
		seg[rt].ly = add;
		seg[rt].ma = add;
		return ;
	}
	int m = (l +r ) >> 1;
	pushdown(rt);
	if(L <= m)
		update1(L,R,add,lson);
	if(R > m)
		update1(L,R,add,rson);
	pushup(rt);
}

void update2(int p,int add,int l,int r,int rt)
{
	if(l == r){
		seg[rt].ma = max(seg[rt].ma,add);
		seg[rt].ly = 0;
		return ;
	}
	int m = (l+r)>>1;
	pushdown(rt);
	if(p <= m)
		update2(p,add,lson);
	else
		update2(p,add,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r){
		return seg[rt].ma;
	}
	int m=(l+r)>>1;
	pushdown(rt);
	int res = -INF;
	if(L <= m)
		res = max(res,query(L,R,lson));
	if(R > m)
		res = max(res,query(L,R,rson));
	pushup(rt);
	return res;
}

int get_sub_size(int u,int p)
{
	int res = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res += get_sub_size(v,u);
	}
	return res;
}

pair<int,int> get_cen(int u,int p,int sum)
{
	pair<int,int> res = make_pair(INF,-1);
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
	res = min(res,make_pair(m,u));
	return res;
}

void dfs(int u,int p,int cost,int num,vector< pair<int,int> >& ds)
{
	int cnt = num + is[u];
	ds.push_back(make_pair(cost,cnt));
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		if(cnt + is[v] > K)
			continue;
		dfs(v,u,cost + edge[i].cost,cnt,ds);
	}
}

void solve_sub(int root)
{
	get_sub_size(root,root);
	if(sub_size[root] == 1)
		return ;
	int s = get_cen(root,root,sub_size[root]).sec;
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int  v = edge[i].to;
		if(cen[v])
			continue;
		solve_sub(v);
	}
	update1(1,M+1,-INF,1,M+1,1);
	if(is[s]){
		update2(2,0,1,M+1,1);
	}
	else{
		update2(1,0,1,M+1,1);
	}
	int cnt;
	vector< pair<int,int> > ds;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		ds.clear();
		dfs(v,s,edge[i].cost,0,ds);
		for(int j=0;j<ds.size();j++){
			cnt = K - ds[j].sec - is[s];
			if(cnt < 0 || cnt > M)
				continue;
			int ma = query(1,cnt+1,1,M+1,1);
			if(ma > -INF)
				ans = max(ans,ds[j].fir + ma);
		}
		for(int j=0;j<ds.size();j++){
			update2(ds[j].sec+1,ds[j].fir,1,M+1,1);
		}
	}
	//update1(1,N+1,-INF,1,N+1,1);
	cen[s] = false;
}

int main()
{
	while(~scanf("%d %d %d",&N,&K,&M)){
		init();
		int u,v,w;
		for(int i=1;i<=M;i++){
			scanf("%d",&u);
			is[u] = 1;
		}
		for(int i=1;i<N;i++){
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		build(1,M+1,1);

		solve_sub(1);
		printf("%d\n",ans);
	}
	return 0;
}
