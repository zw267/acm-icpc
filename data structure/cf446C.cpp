                                            
  //File Name: cf446C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月29日 星期二 22时26分51秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 300000 + 20;
const int MOD = (int)1e9 + 7;

struct Seg{
	LL a,b,sum;
};
Seg seg[MAXN << 2];
LL a[MAXN];
LL pre_sum[MAXN];
LL fib[MAXN];

void init_fib(int N){
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2;i<=N;i++){
		fib[i] = (fib[i-2] + fib[i-1]) % MOD;
	}
}

LL get(int i,LL x,LL y,int is){
	if(i == 1)
		return x;
	if(i == 2)
		return y;
	LL res =  (x * fib[i-2] + y * fib[i-1]) % MOD;
	if(is)
		res = (res - y + MOD) % MOD;
	return res;
}

void pushup(int l,int r,int rt){
	seg[rt].sum = (seg[rt<<1].sum + seg[rt<<1|1].sum) % MOD;
	int m = (l + r) >> 1;
	if(m > l)
		seg[rt].sum = (seg[rt].sum + get(m-l+3,seg[rt<<1].a,seg[rt<<1].b,1)) % MOD;
	if( r > m + 1)
		seg[rt].sum = (seg[rt].sum + get(r-m+2,seg[rt<<1|1].a,seg[rt<<1|1].b,1)) % MOD;
	seg[rt].a = seg[rt].b = 0;
}

void pushdown(int l,int r,int rt){
	int m = (l + r) >> 1;
	int cur = m - l + 1;
	if(cur >= 2){
		(seg[rt<<1].a += seg[rt].a) %= MOD;
		(seg[rt<<1].b += seg[rt].b) %= MOD;
	}
	else{
		(seg[rt<<1].sum += seg[rt].a) %= MOD;
	}
	cur = r - m;
	if(cur >= 2){
		(seg[rt<<1|1].a += get(m+2-l,seg[rt].a,seg[rt].b,0)) %= MOD;
		(seg[rt<<1|1].b += get(m+3-l,seg[rt].a,seg[rt].b,0)) %= MOD;
	}
	else{
		(seg[rt<<1|1].sum += get(m + 2 - l, seg[rt].a,seg[rt].b,0)) %= MOD;
	}
}

void build(int l,int r,int rt){
	seg[rt].sum = 0;
	seg[rt].a = seg[rt].b = 0;
	if(l == r)
		return ;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		if(l == r){
			seg[rt].sum = (seg[rt].sum + get(l - L + 1,1,1,0)) % MOD;
			seg[rt].a = seg[rt].b = 0;
		}
		else{
			seg[rt].a = (seg[rt].a + get(l - L + 1,1,1,0)) % MOD;
			seg[rt].b = (seg[rt].b + get(l - L + 2,1,1,0)) % MOD;
		}
		return ;
	}
	int m = (l + r) >> 1;
	pushdown(l,r,rt);
	if(L <= m)
		update(L,R,lson);
	if(R > m)
		update(L,R,rson);
	pushup(l,r,rt);
	return ;
}

LL query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		if(l == r)
			return seg[rt].sum;
		return (seg[rt].sum + get(r-l+3,seg[rt].a,seg[rt].b,1)) % MOD;
	}
	int m = (l + r) >> 1;
	pushdown(l,r,rt);
	LL ret = 0;
	if(L <= m){
		ret = (ret + query(L,R,lson)) % MOD;
	}
	if(R > m){
		ret = (ret + query(L,R,rson)) % MOD;
	}
	pushup(l,r,rt);
	return ret;
}

void solve(int N,int Q){
	init_fib(N + 10);
	pre_sum[0] = 0;
	for(int i=1;i<=N;i++){
		pre_sum[i] = (pre_sum[i-1] + a[i]) % MOD;
	}
	build(1,N,1);
	for(int i=0,op,l,r;i<Q;i++){
		scanf("%d %d %d",&op,&l,&r);
		if(op == 1){
			update(l,r,1,N,1);
		}
		else{
			LL ans = query(l,r,1,N,1);
			ans = (ans + pre_sum[r] - pre_sum[l - 1] + MOD) % MOD;
			printf("%d\n",(int)ans);
		}
	}
	return ;
}

int main(){
	int N,Q;
	while(~scanf("%d %d",&N,&Q)){
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		solve(N,Q);
	}
	return 0;
}
