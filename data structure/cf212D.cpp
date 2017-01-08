                                            
  //File Name: cf212D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月07日 星期日 15时39分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int MAXN = 1000000 + 10;
const int INF = 0x3f3f3f3f;
int a[MAXN],K[MAXN];
LL ans[MAXN];
struct Node{
	int l,r;
}ran[MAXN];
struct Seg{
	LL v,s;
}seg[MAXN << 2];
void pushdown(int rt){
	if(seg[rt].s){
		LL s = seg[rt].s;
		seg[rt<<1].s += s;
		seg[rt<<1|1].s += s;
		seg[rt].s = 0;
	}
	if(seg[rt].v){
		LL v = seg[rt].v;
		seg[rt<<1].v += v;
		seg[rt<<1|1].v += v;
		seg[rt].v = 0;
	}
}
void build(int l,int r,int rt){
	if(l == r){
		seg[rt].v = seg[rt].s = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}
void update(int L,int R,int c,LL add,int l,int r,int rt){
	if(L <= l && R >= r){
		if(c) seg[rt].s += add;
		else seg[rt].v += add;
		return ;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(L <= mid) update(L,R,c,add,lson);
	if(R > mid) update(L,R,c,add,rson);
}
LL query(int p,int l,int r,int rt){
	if(l == r) return seg[rt].s + seg[rt].v * l;
	pushdown(rt);
	int mid = l + r >> 1;
	if(p <= mid) return query(p,lson);
	else return query(p,rson);
}
void cal_ran(int n){
	for(int i=1;i<=n;i++) ran[i].l = ran[i].r = i;
	for(int i=1;i<=n;i++){
		while(a[ran[i].l-1] > a[i]){
			ran[i].l = ran[ran[i].l-1].l;
		}
	}
	for(int i=n;i>0;i--){
		while(a[ran[i].r+1] >= a[i]){
			ran[i].r = ran[ran[i].r+1].r;
		}
	}
	//for(int i=1;i<=n;i++)
	//	printf("i = %d l = %d r = %d\n",i,ran[i].l,ran[i].r);
}
void solve(const int n,const int m){
	cal_ran(n);
	build(1,n,1);
	for(int i=1,L,R;i<=n;i++){
		L = 1;
		R = min(ran[i].r-i+1,i-ran[i].l+1);
		if(L <= R) update(L,R,0,a[i],1,n,1);
		L = R + 1;
		R = max(ran[i].r-i+1,i-ran[i].l+1);
		if(L <= R) update(L,R,1,(LL)a[i]*(L-1),1,n,1);
		L = R + 1;
		R = ran[i].r - ran[i].l + 1;
		if(L <= R){
			update(L,R,1,(LL)a[i]*(ran[i].r-ran[i].l+2),1,n,1);
			update(L,R,0,-a[i],1,n,1);
		}
	}
	for(int i=1;i<=n;i++)
		ans[i] = query(i,1,n,1);
	for(int i=1;i<=m;i++)
		printf("%.15f\n",(ans[K[i]]+0.0) / (n-K[i]+1.0));
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",K+i);
	a[0] = a[n+1] = -INF;
	solve(n,m);
	return 0;
}
