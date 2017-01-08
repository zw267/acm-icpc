                                            
  //File Name: nod1341.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月14日 星期四 18时36分43秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = (int)1e9 + 7;

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get(LL x,LL n){
	if(x == 1) 
		return n;
	return (qp(x,n) - 1 + MOD) % MOD * qp(x - 1 + MOD,MOD - 2) % MOD;
}

LL solve(LL p,LL q,LL r,LL n){
	LL ans;
	if(p == 1 && q == 1){
		ans = (1+n) * n % MOD * qp(2,MOD - 2) % MOD * r % MOD * 3LL % MOD;
		return ans;
	}
	if(p == 1){
		ans = (get(q,n+1) - 1 + MOD) % MOD * 3 % MOD;
		ans =  (ans - 3 * n % MOD + MOD) % MOD;
		ans = ans * qp(q-1,MOD - 2) % MOD * r % MOD;
		return ans;
	}
	if(p == q){
		ans = qp(q,n) * (n + 1) % MOD - get(q,n+1);
		ans = (ans + MOD) % MOD * r % MOD * 3 % MOD * qp(p-1,MOD-2) % MOD;
		return ans;
	}
	LL u,v;
	if(p > q){
		u = p ,v = q;
	}
	else{
		u = q, v = p;
	}
	ans = (qp(u,n+1) - qp(v,n+1) + MOD) % MOD;
	ans = ans * qp(u - v,MOD - 2) % MOD;
	ans = (ans - get(q,n+1) + MOD) % MOD;
	ans = ans * r % MOD * 3LL % MOD * qp(p-1,MOD-2) % MOD;
	return ans;
}

int main(){
	LL p,q,r,n;
	while(~scanf("%lld %lld %lld %lld",&p,&q,&r,&n)){
		printf("%lld\n",solve(p,q,r,n));
	}
	return 0;
}
