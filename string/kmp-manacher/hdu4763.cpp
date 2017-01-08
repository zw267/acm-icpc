                                            
  //File Name: hdu4763.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 10时58分55秒
                                   

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

#define next nextnext

using namespace std;

const int MAXN = 1000000 + 3;

int next[MAXN];
char str[MAXN];

void kmp_pre(char *x,int m,int *next){
	int i = 0,j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

void solve(){
	int n = strlen(str);
	kmp_pre(str,n,next);
	int len = next[n];
	int ans = 0;
	bool flag = true;
	while(len > 0 && flag){
		for(int i=2*len;i<=n-len;i++){
			if(next[i] >= len){
				ans = len;
				flag = false;
				break;
			}
		}
		len = next[len];
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
