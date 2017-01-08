                                            
  //File Name: cf360C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月17日 星期一 21时02分18秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 2005;
const int MOD = (int)1e9 + 7;
LL f[MAXN][MAXN],sum[MAXN];
char str[MAXN];
int s[MAXN];
LL solve(int n,int m){
	for(int i=1;i<=n;i++)
		s[i] = str[i] - 'a' + 1;
	f[0][0] = sum[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			(f[i][j] += sum[j] * (s[i] - 1) % MOD) %= MOD;
			for(int k=i-1;k>=0 && (i-k)*(n-i+1)<=j;k--)
				(f[i][j] += f[k][j-(i-k)*(n-i+1)] * (26-s[i]) % MOD)%=MOD;
			(sum[j] += f[i][j]) %= MOD;
		}
	}
	LL ans = 0;
	for(int i=0;i<=n;i++)
		(ans += f[i][m]) %= MOD;
	return ans;
}
int main(){
	int n,K;
	scanf("%d %d",&n,&K);
	scanf("%s",str + 1);
	printf("%d\n",(int)solve(n,K));
	return 0;
}
