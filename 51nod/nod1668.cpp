                                            
  //File Name: nod1668.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月04日 星期二 16时04分05秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
const int N = 4;
const int MOD = (int)1e9 + 7;
int g[5];
struct matrix_t{
	LL x[N+1][N+1];
	matrix_t(int v = 1){
		memset(x,0,sizeof x);
		for(int i=1;i<=N;i++) x[i][i] = v;
	}
	matrix_t operator*(const matrix_t &r){
		matrix_t p(0);
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				if(x[i][k] == 0) continue;
				for(int j=1;j<=N;j++){
					(p.x[i][j] += x[i][k] * r.x[k][j] % MOD) %= MOD;
				}
			}
		}
		return p;
	}
	matrix_t power(LL p){
		matrix_t r(1),a = *this;
		for(;p;p>>=1){
			if(p & 1) r = r * a;
			a = a * a;
		}
		return r;
	}
};
LL solve(LL n){
	g[1] = 2,g[2] = 4,g[3] = 7,g[4] = 12;
	if(n <= 4) return g[n];
	matrix_t mat(0);
	mat.x[1][1] = mat.x[1][2] = mat.x[1][4] = 1;
	mat.x[2][1] = mat.x[3][2] = mat.x[4][3] = 1;
	mat = mat.power(n - 4);
	LL ans = mat.x[1][1] * g[4] % MOD + mat.x[1][2] * g[3] % MOD + 
		mat.x[1][3] * g[2] % MOD + mat.x[1][4] * g[1] % MOD;
	return ans % MOD;
}
int main(){
	LL n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
