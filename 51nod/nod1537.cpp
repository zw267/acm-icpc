                                            
  //File Name: nod1537.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月18日 星期五 15时17分38秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD((int)1e9 + 7);
const int N(2);
struct matrix_t{
	LL x[N + 1][N + 1];
	matrix_t(LL v){
		memset(x,0,sizeof(x));
		for(int i=1;i<=N;i++) x[i][i] = v;
	}
	matrix_t operator*(const matrix_t &r){
		matrix_t p(0);
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				if(x[i][k] == 0) continue;
				for(int j=1;j<=N;j++){
					p.x[i][j] += x[i][k] * r.x[k][j] % MOD;
					p.x[i][j] %= MOD;
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
}mat(0);
LL solve(LL n){
	if(n == 0) return 1;
	if(n == 1) return 2;
	mat.x[1][1] = mat.x[2][1] = mat.x[2][2] = 1;
	mat.x[1][2] = 2;
	mat = mat.power(n - 1);
	LL a = (mat.x[1][1] + mat.x[1][2]) % MOD;
	if(n & 1) return (a * a % MOD + 1) % MOD;
	else return a * a % MOD;
}
int main(){
	LL n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
