                                            
  //File Name: cf396D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月11日 星期二 18时17分25秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN = 1000000 + 5;
const int MOD = (int)1e9 + 7;
LL jie[MAXN],inv_4,inv_2;
int a[MAXN],bit[MAXN],n;
struct Seg{
	int r,ly;
	LL s;
}seg[MAXN << 2];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
void init(){
	jie[0] = 1;
	for(int i=1;i<=n;i++) jie[i] = jie[i-1] * i % MOD;
	inv_4 = qp(4,MOD - 2);
	inv_2 = qp(2,MOD - 2);
}
void update(int x,int add){
	for(int i=x;i<=n;i+=i&-i)
		bit[i] += add;
}
int query(int x){
	int res = 0;
	for(int i=x;i>0;i-=i&-i)
		res += bit[i];
	return res;
}
void pushdown(int rt){
	if(seg[rt].ly){
		int &ly = seg[rt].ly,l = rt<<1,r = rt<<1|1;
		seg[l].ly += ly;
		seg[r].ly += ly;
		seg[l].s += 1LL * seg[l].r * ly;
		seg[r].s += 1LL * seg[r].r * ly;
		ly = 0;
	}
}
void pushup(int rt){
	seg[rt].s = seg[rt<<1].s + seg[rt<<1|1].s;
	seg[rt].r = seg[rt<<1].r + seg[rt<<1|1].r;
}
void build(int l,int r,int rt){
	seg[rt].s = seg[rt].ly = 0;
	seg[rt].r = r - l + 1;
	if(l == r) return ;
	int m = l + r >> 1;
	build(lson);
	build(rson);
}
void update(int p,int l,int r,int rt){
	if(l == r){
		seg[rt].r = seg[rt].s = 0;
		return ;
	}
	pushdown(rt);
	int m = l + r >> 1;
	if(p <= m) update(p,lson);
	else update(p,rson);
	pushup(rt);
}
void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		seg[rt].ly += add;
		seg[rt].s += 1LL * add * seg[rt].r;
		return ;
	}
	pushdown(rt);
	int m = l + r >> 1;
	if(L <= m) update(L,R,add,lson);
	if(R > m) update(L,R,add,rson);
	pushup(rt);
}
LL solve(){
	init();
	LL ans = 0,now = 0;
	build(1,n,1);
	for(int u=1;u<=n;u++){
		int i = n - u + 1;
		int j = a[u] - 1 - query(a[u]);
		LL P = 1LL * j * jie[i-1] % MOD;
//		printf("u = %d i = %d j = %d P = %lld\n",u,i,j,P);
		LL suf = P*(i-1)%MOD*(i-2)%MOD*inv_4%MOD+P*(j-1)%MOD*inv_2%MOD;
		LL tmp = seg[1].s % MOD * P % MOD;
//		printf("now = %lld suf = %lld tmp = %lld\n",now,suf,tmp);
		update(a[u],1,n,1);
		if(a[u] > 1) update(1,a[u]-1,1,1,n,1);
		(ans += now % MOD * P % MOD + suf + tmp) %= MOD;
//		printf("ans = %lld\n",ans);
		now += u - 1 - query(a[u]);
		update(a[u],1);
	}
	(ans += now) %= MOD;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a + i);
	printf("%lld\n",solve());
//	printf("%I64d\n",solve());
	return 0;
}

