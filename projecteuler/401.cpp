                                            
  //File Name: 401.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月05日 星期六 00时08分37秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MOD = (int)1e9;
LL inv_3;
LL ext_gcd(LL a,LL b,LL &x,LL &y){
	if(a == 0 && b == 0) return -1;
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	LL d = ext_gcd(b,a % b,y,x);
	y -= a / b * x;
	return d;
}
LL inv(LL a,LL n){
	LL x,y;
	LL d = ext_gcd(a,n,x,y);
	if(d == 1) return (x % n + n) % n;
	return -1;
}
LL cal(LL l,LL r){
	if(l == 1){
		LL x = r,y = r + 1;
		if(x & 1) y /= 2;
		else x /= 2;
		LL res = (x % MOD) * (y % MOD) % MOD * ((2 * r + 1) % MOD) % MOD;
		res = res * inv_3 % MOD;
		return res;
	}
	LL x = cal(1,l - 1);
	LL y = cal(1,r);
	return (y - x + MOD) % MOD;
}
LL solve(LL n){
	inv_3 = inv(3,MOD);
	LL res = 0;
	for(LL d=1;d<=n;){
		LL x = n / d;
		LL r = n / x;
		(res += cal(d,r) * (x % MOD) % MOD) %= MOD;
		d = r + 1;
	}
	return res;
}
int main(){
	LL n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
