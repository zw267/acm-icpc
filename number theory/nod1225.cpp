                                            
  //File Name: nod1225.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月13日 星期三 22时24分03秒
                                   

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

LL solve(const LL n){
	LL ans = (n % MOD) * (n % MOD) % MOD;
	LL x,r;
	LL inv_2 = qp(2,MOD - 2);
	for(LL i=1;i<=n;){
		x = n / i;
		r = n / x;
		//if(x != n / r)
		//	puts("666666666666666");
		ans = (ans - (i+r) % MOD * ((r-i+1) % MOD) % MOD * inv_2 % MOD * (x % MOD) % MOD) % MOD;
		if(ans < 0)
			ans = (ans + MOD) % MOD;
		i = r + 1;
	}
	return ans;
}

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		printf("%lld\n",solve(n));
	}
	return 0;
}
