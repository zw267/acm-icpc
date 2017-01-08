                                            
  //File Name: hdu1711.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 14时29分48秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;
const int MAXM = 10000 + 3;

int str1[MAXN];
int str2[MAXM];
int next[MAXM];

void kmp_pre(int *x,int m,int *next){
	int i = 0,j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

int kmp(int *y,int n,int *x,int m,int *next){
	kmp_pre(x,m,next);
	int i = 0,j = 0;
	while(i < n){
		while(j != -1 && y[i] != x[j])
			j = next[j];
		i++;
		j++;
		if(j >= m){
			return i - m;
		}
	}
	return -1;
}

void solve(int n,int m){
	if(n < m){
		puts("-1");
		return ;
	}
	int ans = kmp(str1,n,str2,m,next);
	if(ans < 0)
		puts("-1");
	else
		printf("%d\n",ans + 1);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&str1[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&str2[i]);
		}
		solve(n,m);
	}
	return 0;
}
