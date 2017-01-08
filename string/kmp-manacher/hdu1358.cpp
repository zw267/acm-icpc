                                            
  //File Name: hdu1358.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 21时51分26秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;

int next[MAXN];
char str[MAXN];

void kmp_pre(char *x,int m,int *next){
	int i = 0, j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

void solve(int n){
	kmp_pre(str,n,next);
	for(int i=1;i<n;i++){
		int k = i + 1 - next[i + 1];
		if(k < i + 1 && (i + 1) % k == 0){
			printf("%d %d\n",i + 1,(i + 1) / k);
		}
	}
	return ;
}

int main(){
	int cas = 1,n;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		printf("Test case #%d\n",cas++);
		scanf("%s",str);
		solve(n);
		puts("");
	}
	return 0;
}
