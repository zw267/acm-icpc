                                            
  //File Name: cf444C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月29日 星期二 19时39分14秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 5;

struct Seg{
	int col;
	LL sum,ly;
};
Seg seg[MAXN << 2];

LL fab(LL x){
	if(x >= 0)
		return x;
	return -x;
}

void pushup(int rt){
	if(seg[rt<<1].col == seg[rt<<1|1].col){
		seg[rt].col = seg[rt<<1].col;
	}
	else
		seg[rt].col = 0;
	seg[rt].ly = 0;
	seg[rt].sum = seg[rt<<1].sum + seg[rt<<1|1].sum;
}

void pushdown(int l,int r,int rt){
	if(seg[rt].ly){
		LL cur = seg[rt].ly;
		int m = (l + r) >> 1;
		seg[rt<<1].sum += cur * (m - l + 1LL);
		seg[rt<<1|1].sum += cur * (r - m + 0LL);
		seg[rt<<1].col = seg[rt<<1|1].col = seg[rt].col;
		seg[rt<<1].ly += seg[rt].ly;
		seg[rt<<1|1].ly += seg[rt].ly;
		seg[rt].ly = 0;
	}
}

void build(int l,int r,int rt){
	seg[rt].sum = 0;
	seg[rt].col = 0;
	seg[rt].ly = 0;
	if(l == r){
		seg[rt].col = l;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int L,int R,LL add,int l,int r,int rt){
	if(L <= l && R >= r && seg[rt].col){
		seg[rt].sum += fab(add - seg[rt].col) * (r - l + 1LL);
		seg[rt].ly += fab(add - seg[rt].col);
		seg[rt].col = add;
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(l,r,rt);
	if(L <= m)
		update(L,R,add,lson);
	if(R > m)
		update(L,R,add,rson);
	pushup(rt);
}

LL query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt].sum;
	LL ret = 0;
	int m = (l + r) >> 1;
	pushdown(l,r,rt);
	if(L <= m)
		ret += query(L,R,lson);
	if(R > m)
		ret += query(L,R,rson);
	pushup(rt);
	return ret;
}

void solve(int N,int Q){
	build(1,N,1);
	for(int i=0,op,l,r,x;i<Q;i++){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d %d %d",&l,&r,&x);
			update(l,r,x,1,N,1);
		}
		else{
			scanf("%d %d",&l,&r);
			cout << query(l,r,1,N,1) << endl;
		}
	}
	return ;
}

int main(){
	int N,Q;
	while(~scanf("%d %d",&N,&Q)){
		solve(N,Q);
	}
	return 0;
}
