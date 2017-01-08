                                            
  //File Name: cf396C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月20日 星期三 12时44分30秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define LL long long

using namespace std;

const int MAXN = 300000 + 5;
const int MOD = (int)1e9 + 7;
int dis[MAXN];
int siz[MAXN];
int in[MAXN];
int rev[MAXN];

struct Seg{
	LL w,k;
};
Seg seg[MAXN << 2];

struct Edge{
	int to,next;
};
Edge edge[MAXN];
int head[MAXN];
int total;

void init_edge(){
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v){
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void M(LL &x){
	x = (x + MOD) % MOD;
}

void dfs(int u,int d){
	dis[u] = d;
	in[u] = ++total;
	rev[total] = u;
	siz[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		dfs(v,d + 1);
		siz[u] += siz[v];
	}
}

void pushdown(int rt){
	M(seg[rt<<1].w += seg[rt].w);
	M(seg[rt<<1|1].w += seg[rt].w);
	M(seg[rt<<1].k += seg[rt].k);
	M(seg[rt<<1|1].k += seg[rt].k);
	seg[rt].w = seg[rt].k = 0;
}

void build(int l,int r,int rt){
	seg[rt].w = seg[rt].k = 0;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int L,int R,LL W,LL K,int l,int r,int rt){
	if(L <= l && R >= r){
		M(seg[rt].w += W);
		M(seg[rt].k += K);
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(L <= mid)
		update(L,R,W,K,lson);
	if(R > mid)
		update(L,R,W,K,rson);
}

LL query(int p,int l,int r,int rt){
	if(l == r){
		LL ans = (seg[rt].w - (LL)dis[rev[l]] * seg[rt].k) % MOD;
		M(ans);
		return ans;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(p <= mid)
		return query(p,lson);
	else
		return query(p,rson);
}

void solve(int n){
	total = 0;
	dfs(1,0);
	build(1,n,1);
	int q;
	scanf("%d",&q);
	for(int i=1,op,u,x,k;i<=q;i++){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d %d %d",&u,&x,&k);
			update(in[u],in[u] + siz[u] - 1,(LL)x + (LL)dis[u] * k,k,1,n,1);
		}
		else{
			scanf("%d",&u);
			printf("%d\n",(int)query(in[u],1,n,1));
		}
	}
	return ;
}

int main(){
	init_edge();
	int n;
	scanf("%d",&n);
	for(int i=2,p;i<=n;i++){
		scanf("%d",&p);
		addedge(p,i);
	}
	solve(n);
	return 0;
}
