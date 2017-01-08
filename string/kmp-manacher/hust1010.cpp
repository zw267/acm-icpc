                                            
  //File Name: hust1010.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 22时04分53秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;

char str[MAXN];
int next[MAXN];

void kmp_pre(char *x,int *next){
	int m = strlen(x);
	int i = 0, j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

void solve(){
	kmp_pre(str,next);
	int n = strlen(str);
	int ans = n - next[n];
	printf("%d\n",ans);
}

int main(){
	while(~scanf("%s",str)){
		solve();
	}
	return 0;
}
