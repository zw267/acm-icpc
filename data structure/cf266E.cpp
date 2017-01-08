                                            
  //File Name: cf266E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月07日 星期六 11时33分49秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>

#define LL long long

using namespace std;

const int MAXN = 100000 + 5;
const int MOD = (int)1e9 + 7;

LL p[MAXN][6];

void init_p(int n){
	for(int j=0;j<6;j++) p[0][j] = 0;
	for(int i=1;i<=n;i++){
		p[i][0] = 1;
		for(int j=1;j<=5;j++)
			p[i][j] = p[i][j - 1] * i % MOD;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<6;j++)
			(p[i][j] += p[i - 1][j]) %= MOD;
	}
}

LL a[MAXN];

struct Segtree{
	LL w[6],tag;
	int l,r;
}seg[MAXN << 2];

void pushup(int rt){
	for(int i=0;i<6;i++)
		seg[rt].w[i] = (seg[rt<<1].w[i] + seg[rt<<1|1].w[i]) % MOD;
}

void pushdown(int rt){
	if(seg[rt].tag >= 0){
		seg[rt<<1].tag = seg[rt<<1|1].tag = seg[rt].tag;
		for(int j=0;j<6;j++){
			seg[rt<<1].w[j] = seg[rt].tag * (p[seg[rt<<1].r][j] -
					p[seg[rt<<1].l - 1][j] + MOD) % MOD;
			seg[rt<<1|1].w[j] = seg[rt].tag * (p[seg[rt<<1|1].r][j] - 
					p[seg[rt<<1|1].l - 1][j] + MOD) % MOD;
		}
		seg[rt].tag = -1;
	}
}
void build(int l,int r,int rt){
	seg[rt].l = l,seg[rt].r = r,seg[rt].tag = -1;
	if(l == r){
		for(int j=0;j<6;j++){
			seg[rt].w[j] = a[l] * (p[l][j] - p[l - 1][j] + MOD) % MOD;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void update(int L,int R,LL x,int rt){
	if(L <= seg[rt].l && R >= seg[rt].r){
		seg[rt].tag = x;
		for(int j=0;j<6;j++){
			seg[rt].w[j] = x * (p[seg[rt].r][j] - p[seg[rt].l - 1][j] 
					+ MOD) % MOD;
		}
		return ;
	}
	pushdown(rt);
	int mid = (seg[rt].l + seg[rt].r) >> 1;
	if(L <= mid)
		update(L,R,x,rt<<1);
	if(R > mid)
		update(L,R,x,rt<<1|1);
	pushup(rt);
}

LL query(int L,int R,int k,int rt){
	if(L <= seg[rt].l && R >= seg[rt].r)
		return seg[rt].w[k];
	pushdown(rt);
	int mid = (seg[rt].l + seg[rt].r) >> 1;
	LL res = 0;
	if(L <= mid)
		res += query(L,R,k,rt<<1);
	if(R > mid)
		res = (res + query(L,R,k,rt<<1|1)) % MOD;
	pushup(rt);
	return res;
}

LL query(int l,int r,int k){
	LL res = 0;
	if(k == 0){
		res = query(l,r,k,1);
	}
	else if(k == 1){
		res = query(l,r,1,1) - (l - 1) * query(l,r,0,1) % MOD;
	}
	else if(k == 2){
		res = query(l,r,2,1) + (2 - 2 * l) * query(l,r,1,1) % MOD +
			(l - 1) * (l - 1) % MOD * query(l,r,0,1) % MOD;
	}
	else if(k == 3){
		res = query(l,r,3,1) + (3 - 3 * l) * query(l,r,2,1) % MOD +
			3 * (l - 1) * (l - 1) % MOD * query(l,r,1,1) % MOD + 
			(l - 1) * (l - 1) % MOD * (1 - l) % MOD * query(l,r,0,1) % MOD;
	}
	else if(k == 4){
		res = query(l,r,4,1) + (4 - 4 * l) * query(l,r,3,1) % MOD + 
			6 * (l - 1) * (l - 1) % MOD * query(l,r,2,1) % MOD -
			4 * (l - 1) * (l - 1) % MOD * (l - 1) % MOD * query(l,r,1,1) % MOD +
			(l - 1) * (l - 1) % MOD * (l - 1) % MOD * (l - 1) % MOD * 
			query(l,r,0,1) % MOD;
	}
	else{
		res = query(l,r,5,1);
		res = (res + (5 - 5 * l) * query(l,r,4,1)) % MOD;
		res = (res + 10 * (l - 1) * (l - 1) % MOD * query(l,r,3,1) % MOD) % MOD;
		LL cur = 10 * (l - 1) % MOD * (l - 1) % MOD * (l - 1) % MOD;
		res = (res - cur * query(l,r,2,1) % MOD + MOD) % MOD;
		cur = 5 * (l - 1) % MOD * (l - 1) % MOD * (l - 1) % MOD * (l - 1) % MOD;
		res = (res + cur * query(l,r,1,1) % MOD) % MOD;
		cur = (l - 1) * (l - 1) % MOD * (l - 1) % MOD* (l - 1) % MOD * (l - 1) % MOD;
		res = (res - cur * query(l,r,0,1) % MOD + MOD) % MOD;
	}
	res = (res % MOD + MOD) % MOD;
	return res;
}

char ch[3];

void solve(int n,int q){
	init_p(n);
	build(1,n,1);
	for(int i=1,l,r,x;i<=q;i++){
		scanf("%s %d %d %d",ch,&l,&r,&x);
		if(ch[0] == '?'){
			printf("%d\n",(int)query(l,r,x));
		}
		else{
			update(l,r,x,1);
		}
	}
	return ;
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	solve(n,q);
	return 0;
}
