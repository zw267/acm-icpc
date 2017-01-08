                                            
  //File Name: cf403D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月14日 星期五 22时33分04秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 1005;
LL f[MAXN][63],jie[63],c[MAXN][63];
int ans[MAXN][63];
void init(){
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<MAXN;i++)
		f[i][1] = 1;
	for(int i=1;i<MAXN;i++){
		for(int j=2;j<63 && j <= i;j++){
			f[i][j] = (f[i-j][j-1] + f[i-j][j]) % MOD;
		}
	}
	c[0][0] = 1;
	for(int i=1;i<MAXN;i++){
		c[i][0] = 1;
		for(int j=1;j<=i && j < 63;j++){
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
		}
	}
	jie[0] = 1;
	for(int i=1;i<63;i++)
		jie[i] = jie[i-1] * i % MOD;
}
int solve(int n,int k){
	if(ans[n][k] != -1) return ans[n][k];
	LL res = 0;
	int b = k * (k + 1) / 2;
	for(int i=b;i<=n;i++){
		(res += f[i][k] * jie[k] % MOD * c[n-i+k][k] % MOD) %= MOD;
	}
	ans[n][k] = (int)res;
	return ans[n][k];
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	for(int i=1,n,k;i<=t;i++){
		scanf("%d %d",&n,&k);
		if(k * (k + 1) > 2 * n)
			puts("0");
		else
			printf("%d\n",solve(n,k));
	}
	return 0;
}

