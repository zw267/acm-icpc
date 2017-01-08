                                            
  //File Name: cf382E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月31日 星期一 00时00分31秒

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define LL long long
using namespace std;
const int MAXN = 52;
const int MOD = (int)1e9 + 7;
LL C[MAXN][MAXN],f[MAXN][MAXN][2],inv_2;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
void init(){
	C[0][0] = 1;
	for(int i=1;i<MAXN;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	inv_2 = qp(2,MOD - 2);
}
LL solve(int n,int s){
	f[1][0][0] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			LL t0 = f[i-1][j][1] * i % MOD;
			LL t1 = f[i-1][j-1][0] * i % MOD;
			LL tmp;
			for(int k=1;k<=i-1-k;k++){
				for(int l=0;l<=j;l++){
					if(k == i - 1 - k) tmp = inv_2;
					else tmp = 1;
					(t0 += f[k][l][1] * f[i-1-k][j-l][1] % MOD * C[i-1][k] % MOD * i % MOD * tmp % MOD) %= MOD;
					if(j - l - 1 >= 0)
						(t1 += f[k][l][0] * f[i-1-k][j-l-1][0] % MOD * C[i-1][k] % MOD * i % MOD * tmp % MOD) %= MOD;
				}
			}
//			if(i % 2 == 1 && j % 2 == 0)
//				(t0 += f[i/2][j/2][1] * f[i/2][j/2][1] % MOD * C[i-2][i/2] % MOD * i % MOD) %= MOD;
//			if(i % 2 == 1 && j % 2 == 1)
//				(t1 += f[i/2][j/2][0] * f[i/2][j/2][0] % MOD * C[i-2][i/2] % MOD * i % MOD) %= MOD;
			for(int k=1;k<=i-1-k;k++){
				for(int l=0;l<j;l++){
					if(k == i - 1 - k) tmp = inv_2;
					else tmp = 1;
					(t1 += f[k][l][1] * f[i-1-k][j-l-1][0] % MOD * C[i-1][k] % MOD * i % MOD * tmp % MOD) %= MOD;
					(t1 += f[k][l][0] * f[i-1-k][j-l-1][1] % MOD * C[i-1][k] % MOD * i % MOD * tmp % MOD) %= MOD;
				}
			}
//			if(i % 2 == 1 && j % 2 == 1)
//				(t1 += f[i/2][j/2][0] * f[i/2][j/2][1] % MOD * C[i-1][i/2] % MOD * i % MOD) %= MOD;
			f[i][j][0] = t0;
			f[i][j][1] = t1;
		}
	}
	LL ans = (f[n][s][0] + f[n][s][1]) % MOD * qp(n,MOD - 2) % MOD;
	return ans;
}
int main(){
	init();
	int n,s;
	cin >> n >> s;
	cout << solve(n,s) << endl;
	return 0;
}

