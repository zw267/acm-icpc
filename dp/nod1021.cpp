                                            
  //File Name: nod1021.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月16日 星期六 16时42分38秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 103;
const int INF = 0x3f3f3f3f;

int a[MAXN];
int sum[MAXN];
LL f[MAXN][MAXN];

void solve(int n){
	sum[0] = 0;
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j)
				f[i][j] = 0;
			else
				f[i][j] = INF;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			int j = i + len - 1;
			if(j > n) break;
			for(int k=i;k<j;k++){
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + sum[j] - sum[i-1]);
			}
		}
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n);
		printf("%lld\n",f[1][n]);
	}
	return 0;
}
