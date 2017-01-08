                                            
  //File Name: uvalive7148.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月12日 星期六 17时16分35秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

#define LL long long
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define len first
#define dif second
#define fir first
#define sec second

using namespace std;

const int MAXN = 100000+5;

struct Seg{
	int ma,ly;
};
Seg seg_1[MAXN << 2];
Seg seg_2[MAXN << 2];

struct Edge{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;
int val[MAXN];
int ans,D;
pair<int,int> ds_1[MAXN],ds_2[MAXN];
int tot_ds1,tot_ds2;
int sub_size[MAXN];
bool cen[MAXN];

void init(int n)
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
}

void addedge(int u,int v)
{
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void update2(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r){
		seg_1[rt].ma = seg_1[rt].ly = 0;
		seg_2[rt].ma = seg_2[rt].ly = 0;
		return ;
	}
}

void pushup(int rt,Seg *seg)
{
	seg[rt].ma = max(seg[rt<<1].ma,seg[rt<<1|1].ma);
}

void pushdown(int rt,Seg *seg)
{
	if(seg[rt].ly == 0){
		seg[rt<<1].ly = seg[rt<<1|1].ly = 0;
		seg[rt<<1].ma = seg[rt<<1|1].ma = 0;
		seg[rt].ly = -1;
	}
}

void update1(int p,int add,int l,int r,int rt,Seg *seg)
{
	if(l == r){
		seg[rt].ma = max(seg[rt].ma,add);
		seg[rt].ly = -1;
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(rt,seg);
	if(p <= m)
		update1(p,add,lson,seg);
	else
		update1(p,add,rson,seg);
	pushup(rt,seg);
}

int query(int L,int R,int l,int r,int rt,Seg *seg)
{
	if(L <= l && R >= r){
		return seg[rt].ma;
	}
	int m = (l + r) >> 1;
	pushdown(rt,seg);
	int res = 0;
	if(L <= m)
		res = max(res,query(L,R,lson,seg));
	if(R > m)
		res = max(res,query(L,R,rson,seg));
	pushup(rt,seg);
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
	return res = min(res,mp(m,u));
}

void dfs1(int u,int p,int len,int dif)
{
	if(dif > D || dif < 0)
		return ;
	ds_1[tot_ds1++] = mp(len+1,dif);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v] || v == p)
			continue;
		if(val[v] > val[u])
			continue;
		dfs1(v,u,len+1,dif + val[u] - val[v]);
	}
}

void dfs2(int u,int p,int len,int dif)
{
	if(dif > D || dif < 0)
		return ;
	ds_2[tot_ds2++] = mp(len+1,dif);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		if(val[v] < val[u])
			continue;
		dfs2(v,u,len+1,val[v] - val[u] + dif);
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
	update2(1,D+1,1,D+1,1);
	update1(1,1,1,D+1,1,seg_1);
	update1(1,1,1,D+1,1,seg_2);
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		tot_ds1 = tot_ds2 = 0;
		dfs1(v,s,1,val[s] - val[v]);
		dfs2(v,s,1,val[v] - val[s]);
		for(int i=0;i<tot_ds1;i++){
			int cur = query(1,D-ds_1[i].dif+1,1,D+1,1,seg_2);
			ans = max(ans,ds_1[i].len + cur - 1);
		}
		for(int i=0;i<tot_ds2;i++){
			int cur = query(1,D-ds_2[i].dif+1,1,D+1,1,seg_1);
			ans = max(ans,ds_2[i].len + cur - 1);
		}
		for(int i=0;i<tot_ds1;i++){
			update1(ds_1[i].dif+1,ds_1[i].len,1,D+1,1,seg_1);
		}
		for(int i=0;i<tot_ds2;i++){
			update1(ds_2[i].dif+1,ds_2[i].len,1,D+1,1,seg_2);
		}
	}
	cen[s] = false;
}	

void solve(int n)
{
	ans = 1;
	divide(1);
	printf("%d\n",ans);
	return ;
}

int main()
{
	int test;
	int cas = 1;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d %d",&n,&D);
		init(n);
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		printf("Case #%d: ",cas++);
		solve(n);
	}
	return 0;
}
