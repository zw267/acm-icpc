                                            
  //File Name: hdu5719.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月26日 星期二 21时06分20秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;
const int MOD = 998244353;

LL f[MAXN];
int b[MAXN],c[MAXN];

int solve(int n){
	memset(f,0,sizeof f);
	if(b[1] != c[1]) return 0;
	f[1] = 1;
	for(int i=2;i<=n;i++){
		if(b[i] < b[i-1]){
			if(c[i] == c[i-1])
				f[i] = f[i-1];
			else
				f[i] = 0;
		}
		else if(c[i] > c[i-1]){
			if(b[i] == b[i-1])
				f[i] = f[i-1];
			else
				f[i] = 0;
		}
		else{
			if(c[i] == c[i-1] && b[i] == b[i-1] && c[i]-b[i]+1>=i)
				f[i] = f[i-1] * (c[i]-b[i]+2-i) % MOD;
			else
				f[i] = 0;
		}
	}
	return f[n];
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		printf("%d\n",solve(n));
	}
	return 0;
}
