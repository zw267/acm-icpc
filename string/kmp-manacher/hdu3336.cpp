                                            
  //File Name: hdu3336.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 23时16分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 200000 + 3;
const int MOD = 10007;

char str[MAXN];
int next[MAXN];
int sum[MAXN];

void kmp_pre(const char *x,int m,int *next){
	int i = 0,j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

void solve(int n){
	kmp_pre(str,n,next);
	memset(sum,0,sizeof sum);
	for(int i=1;i<=n;i++){
		sum[next[i]]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans + sum[i] + 1) % MOD;
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		scanf("%s",str);
		solve(n);
	}
	return 0;
}
