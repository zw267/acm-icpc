                                            
  //File Name: hdu1686.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 14时43分19秒
                                   

#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;
const int MAXM = 10000 + 3;

char str1[MAXN];
char str2[MAXM];
int next[MAXM];

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

int kmp(char *y,char *x){
	int ans = 0;
	kmp_pre(x,next);
	int n = strlen(y), m = strlen(x);
	int i = 0, j = 0;
	while(i < n){
		while(j != -1 && y[i] != x[j])
			j = next[j];
		i++;
		j++;
		if(j >= m){
			ans++;
			j = next[j];
		}
	}
	return ans;
}

void solve(){
	printf("%d\n",kmp(str1,str2));
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",str2);
		scanf("%s",str1);
		solve();
	}
	return 0;
}
