                                            
  //File Name: 81.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 21时27分44秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 81;
int a[MAXN][MAXN];
LL f[MAXN][MAXN];
void solve(int n){
	for(int i=1;i<=n;i++)
		f[1][i] = f[1][i-1] + a[1][i],f[i][1] = f[i-1][1] + a[i][1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			f[i][j] = min(f[i-1][j],f[i][j-1]) + a[i][j];
		}
	}
}
int main(){
	freopen("data.in","r",stdin);
	int n = 80;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++)
			scanf("%lld,",&a[i][j]);
		scanf("%lld",&a[i][n]);
	}
	solve(n);
	printf("%lld\n",f[n][n]);
	fclose(stdin);
	return 0;
}
