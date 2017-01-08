                                            
  //File Name: 67.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 18时00分18秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
const int MAXN = 105;
LL f[MAXN][MAXN],a[MAXN][MAXN];
void solve(int n){
	for(int i=1;i<=n;i++)
		f[n][i] = a[n][i];
	for(int i=n-1;i>0;i--){
		for(int j=1;j<=i;j++)
			f[i][j] = std::max(f[i+1][j],f[i+1][j+1]) + a[i][j];
	}
}
int main(){
	freopen("data.in","r",stdin);
	int n = 100;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	}
	solve(n);
	printf("%lld\n",f[1][1]);
	return 0;
}
