                                            
  //File Name: hdu3746.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 18时37分08秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 100000 + 3;

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
	int n = strlen(str);
	kmp_pre(str,next);
	//for(int i=0;i<n;i++)
	//	printf("i = %d next[%d] = %d\n",i,i,next[i]);
	int ans;
	if(next[n] == 0){
		ans = n;
	}
	else{
		int sz = n - next[n];
		ans = sz - n % sz;
		if(ans >= sz)
			ans -= sz;
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",str);
		solve();
	}
	return 0;
}
