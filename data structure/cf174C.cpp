                                            
  //File Name: cf174C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月02日 星期四 22时16分51秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int MAXN = 100000 + 3;

struct Seg{
	int l,r,ma,ly;
}seg[MAXN << 2];

struct Ans{
	int l,r,t;
	Ans(){}
	Ans(int _l,int _r,int _t){
		l = _l,r = _r,t = _t;
	}
}ans[MAXN];

int a[MAXN],tot,N;

void pushup(int m,int rt){
	if(seg[rt<<1].ma != seg[rt<<1|1].ma){
		int now;
		if(seg[rt<<1].ma > seg[rt<<1|1].ma)
			now = rt<<1;
		else
			now = rt<<1|1;
		seg[rt].ma = seg[now].ma;
		seg[rt].l = seg[now].l;
		seg[rt].r = seg[now].r;
	}
	else{
		seg[rt].ma = seg[rt<<1].ma;
		if(seg[rt<<1].r == m && seg[rt<<1|1].l == m + 1){
			seg[rt].l = seg[rt<<1].l,seg[rt].r = seg[rt<<1|1].r;
		}
		else{
			seg[rt].l = seg[rt<<1].l,seg[rt].r = seg[rt<<1].r;
		}
	}
}

void pushdown(int rt){
	if(seg[rt].ly){
		seg[rt<<1].ly += seg[rt].ly;
		seg[rt<<1|1].ly += seg[rt].ly;
		seg[rt<<1].ma += seg[rt].ly;
		seg[rt<<1|1].ma += seg[rt].ly;
		seg[rt].ly = 0;
	}
}

void build(int l,int r,int rt){
	seg[rt].ly = 0;
	if(l == r){
		seg[rt].l = seg[rt].r = l;
		seg[rt].ma = a[l];
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(m,rt);
}

void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		seg[rt].ma += add;
		seg[rt].ly += add;
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(rt);
	if(L <= m)
		update(L,R,add,lson);
	if(R > m)
		update(L,R,add,rson);
	pushup(m,rt);
}

int query(int L,int l,int r,int rt){
	if(L == 0 || L == N + 1)
		return 0;
	if(l == r)
		return seg[rt].ma;
	int m = (l + r) >> 1;
	pushdown(rt);
	int res;
	if(L <= m) 
		res = query(L,lson);
	else
		res = query(L,rson);
	pushup(m,rt);
	return res;
}

void solve(int n){
	tot = 0;
	N = n;
	int total = 0;
	build(1,n,1);
	int ma,l,r,dif;
	while(seg[1].ma > 0){
		ma = seg[1].ma,l = seg[1].l,r = seg[1].r;
		dif = ma - max(query(l-1,1,n,1),query(r+1,1,n,1));
		//printf("l = %d r = %d ma = %d dif = %d\n",l,r,ma,dif);
		ans[tot++] = Ans(l,r,dif);
		total += dif;
		update(l,r,-dif,1,n,1);
	}	
	printf("%d\n",total);
	for(int i=0;i<tot;i++){
		for(int j=0;j<ans[i].t;j++){
			printf("%d %d\n",ans[i].l,ans[i].r);
		}
		//printf("l = %d r = %d t = %d\n",ans[i].l,ans[i].r,ans[i].t);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
