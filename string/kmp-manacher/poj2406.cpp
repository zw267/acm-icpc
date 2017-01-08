                                            
  //File Name: poj2406.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 22时47分08秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;

int next[MAXN];
char str[MAXN];

void kmp_pre(char *x,int *next){
	int m = strlen(str);
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
	int sz = n - next[n];
	int ans;
	if(n % sz)
		ans = 1;
	else
		ans = n / sz;
	printf("%d\n",ans);
	return ;
}

int main(){
	while(~scanf("%s",str)){
		if(str[0] == '.')
			break;
		solve();
	}
	return 0;
}
