                                            
  //File Name: cf633G.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月05日 星期一 14时02分29秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <bitset>
#define LL long long 
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int MAXN = 100000 + 10;
const int N = 1000;
struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot,m;
int st[MAXN],en[MAXN],rev[MAXN],ly[MAXN << 2],val[MAXN];
bitset<N> bit[MAXN << 2],prime,ans;
void init(){
	prime.reset();
	for(int i=2;i<m;i++){
		bool flag = true;
		for(int j=2;j*j<=i;j++){
			if(i % j == 0){
				flag = false;
				break;
			}
		}
		if(flag) prime[i] = 1;
	}
}
void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs(int u,int p){
	st[u] = ++tot;
	rev[tot] = u;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dfs(v,u);
	}
	en[u] = tot;
}
void pushup(int rt){
	bit[rt] = bit[rt<<1] | bit[rt<<1|1];
}
void pushdown(int rt){
	if(ly[rt]){
		int &u = ly[rt];
		(ly[rt<<1] += u) %= m;
		(ly[rt<<1|1] += u) %= m;
		bit[rt<<1] = (bit[rt<<1] << u) | (bit[rt<<1] >> (m - u));
		bit[rt<<1|1] = (bit[rt<<1|1] << u) | (bit[rt<<1|1] >> (m - u));
		bit[rt].reset();
		u = 0;
	}
}
void build(int l,int r,int rt){
	if(l == r){
		bit[rt][val[rev[l]]] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		(ly[rt] += add) %= m;
		bit[rt] = (bit[rt] << add) | (bit[rt] >> (m - add));
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) update(L,R,add,lson);
	if(R > mid) update(L,R,add,rson);
	pushup(rt);
}
void query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		ans |= bit[rt];
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) query(L,R,lson);
	if(R > mid) query(L,R,rson);
	pushup(rt);
}
void solve(int n){
	init();
	tot = 0;
	dfs(1,1);
	build(1,n,1);
	int q;
	scanf("%d",&q);
	for(int i=0,op,u,v;i<q;i++){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d %d",&u,&v);
			update(st[u],en[u],v % m,1,n,1);
		}
		else{
			scanf("%d",&u);
			ans.reset();
			query(st[u],en[u],1,n,1);
			ans &= prime;
			printf("%d\n",ans.count());
		}
	}
}
int main(){
	memset(head,-1,sizeof head);
	tot = 0;
	int n;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]),val[i] %= m;
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	solve(n);
	return 0;
}
