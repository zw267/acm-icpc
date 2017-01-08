                                            
  //File Name: cf616E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月08日 星期二 19时10分04秒
                                   
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
LL solve(LL n,LL m){
	LL inv_2 = qp(2,MOD - 2);
	LL res2 = (n % MOD) * (min(n,m) % MOD) % MOD;
	if(m > n){
		(res2 += (m - n) % MOD * (n % MOD) % MOD) %= MOD;
		m = n;
	}
	LL res = 0;
	for(LL i=1;i<=m;){
		LL x = n / i;
		LL r = n / x;
		r = min(r,m);
		(res += x%MOD*((i+r)%MOD)%MOD*((r-i+1)%MOD)%MOD*inv_2%MOD) %= MOD;
		i = r + 1;
	}
	res = (res2 - res + MOD) % MOD;
	return res;
}
int main(){
	LL n,m;
	cin >> n >> m;
	cout << solve(n,m) << endl;
	return 0;
}
