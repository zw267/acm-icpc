                                            
  //File Name: nod1371.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月11日 星期二 11时42分54秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 203;
const int MOD = (int)1e8 + 7;
LL f[MAXN][MAXN][MAXN];
LL c[MAXN][MAXN];
void init(){
	c[0][0] = 1;
	for(int i=1;i<MAXN;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++){
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
		}
	}
}
void up(LL &x){
	while(x >= MOD) x -= MOD;
}
LL solve(int n){
	f[0][0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k+j<=i;k++){
				if(!f[i][j][k]) continue;
				up(f[i+1][j][k] += f[i][j][k]);
				if(j > 0) up(f[i+1][j-1][k+1] += f[i][j][k] * j % MOD);
				up(f[i+1][j+1][k] += f[i][j][k] * (i+1-j-k) % MOD);	
				up(f[i+1][j][k+1] += f[i][j][k] * j * (i+1-j-k) % MOD);
				if(j > 1) up(f[i+1][j-2][k+2] += f[i][j][k]*c[j][2] % MOD);
				up(f[i+1][j][k+1] += f[i][j][k]*(i+1-j-k) % MOD);
				if(i+1-j-k>1) up(f[i+1][j+2][k]+=f[i][j][k]*c[i+1-j-k][2]%MOD);
			}
		}
	}
	LL ans = 0;
	for(int i=0;i<=n;i++)
		for(int j=0;i+j<=n;j++)
			up(ans += f[n][i][j]);
	return ans;
}
int main(){
	init();
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
