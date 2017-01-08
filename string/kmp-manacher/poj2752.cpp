                                            
  //File Name: poj2752.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月28日 星期四 00时55分36秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next Next

using namespace std;

const int MAXN = 400000 + 3;

char str[MAXN];
int next[MAXN];
int ans[MAXN];

void kmp_pre(const char *x,int *next){
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
	int tot = 0;
	ans[tot++] = n;
	while(next[n] > 0){
		ans[tot++] = next[n];
		n = next[n];
	}
	for(int i=tot-1;i>0;i--){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[0]);
	return ;
}

int main(){
	while(~scanf("%s",str)){
		solve();
	}
	return 0;
}
