                                            
  //File Name: cf295D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月15日 星期六 16时57分16秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 2005;
const int MOD = (int)1e9 + 7;
LL f[MAXN][MAXN],A[MAXN][MAXN],B[MAXN][MAXN];
void init(int n,int m){
	for(int j=2;j<=m;j++) f[1][j] = 1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++)
			f[i][j]=(2*f[i][j-1]+f[i-1][j]-f[i][j-2]+MOD) % MOD;
	}
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++)
			A[i][j] = (A[i-1][j] + f[i][j]) % MOD;
	}
	for(int j=2;j<=m;j++){
		for(int i=1;i<=n;i++)
			B[i][j] = (B[i-1][j] + f[i][j] - f[i-1][j] + MOD) % MOD;
	}
}
LL solve(int n,int m){
	init(n,m);
	LL ans = 0;
	for(int t=1;t<=n;t++){
		for(int l=2;l<=m;l++){
			LL tmp = (m+1-l) * A[t][l] % MOD * B[n-t+1][l] % MOD;
			(ans += tmp) %= MOD;
		}
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	cout << solve(n,m) << endl;
	return 0;
}
