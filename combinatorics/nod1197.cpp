                                            
  //File Name: nod1197.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月08日 星期六 20时18分58秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 2;
const int MOD = (int)1e9 + 7;
const int N = 22;
int f[MAXN][N],len[N],g[N];
struct matrix_t{
	LL x[N][N];
	matrix_t(int v){
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
};
LL solve(int n,LL m){
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		f[i][0] = 1;
		for(int j=1;j<=20;j++)
			f[i][j] = (0LL + f[i-1][j] + f[i/2][j-1]) % MOD;
	}
	for(int i=1;i<=20;i++)
		len[i] = (0LL + f[n][i] - f[n/2][i] + MOD) % MOD;
	matrix_t mat(0);
	for(int i=1;i<=20;i++)
		mat.x[1][i] = len[i];
	for(int i=2;i<=21;i++)
		mat.x[i][i-1] = 1;
	g[0] = 1;
	for(int i=1;i<N;i++)
		for(int j=1;j<=20 && j <= i;j++)
			g[i] = (0LL + g[i] + 1LL * g[i-j] * len[j] % MOD) % MOD;	
	if(m < N) return g[m];
	mat = mat.power(m - 21);
	LL ans = 0;
	for(int i=1;i<N;i++)
		ans = (0LL + ans + mat.x[1][i] * g[N - i] % MOD) % MOD;
	return ans;
}
int main(){
	int n;
	LL m;
	cin >> n >> m;
	cout << solve(n,m) <<endl;
	return 0;
}
