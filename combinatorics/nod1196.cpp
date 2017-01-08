                                            
  //File Name: nod1196.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月08日 星期六 19时51分55秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 2;
const int MOD = (int)1e9 + 7;
int f[MAXN][21],g[MAXN],len[21];
int solve(int n,int m){
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		f[i][0] = 1;
		for(int j=1;j<=20;j++)
			f[i][j] = (0LL + f[i-1][j] + f[i/2][j-1]) % MOD;
	}
	for(int i=1;i<=20;i++)
		len[i] = (0LL + f[n][i] - f[n / 2][i] + MOD) % MOD;
	g[0] = 1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=20;j++){
			if(i - j < 0) break;
			g[i] = (0LL + g[i] + 1LL * g[i-j] * len[j] % MOD) % MOD;
		}
	}
	return g[m];
}
int main(){
	int n,m;
	cin >> n >> m;
	cout << solve(n,m) << endl;
	return 0;
}
