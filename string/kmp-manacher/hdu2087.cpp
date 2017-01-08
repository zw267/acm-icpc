                                            
  //File Name: hdu2087.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月26日 星期二 14时54分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define next nextnext

using namespace std;

const int MAXN = 1003;

char str1[MAXN];
char str2[MAXN];
int next[MAXN];

void kmp_pre(char *x,int *next){
	int m = strlen(x);
	int i = 0,j = -1;
	next[0] = -1;
	while(i < m){
		while(j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}

int kmp(char *y,char *x){
	kmp_pre(x,next);
	int n = strlen(y), m = strlen(x), i = 0, j = 0;
	int ans = 0;
	while(i < n){
		while(j != -1 && y[i] != x[j])
			j = next[j];
		i++;
		j++;
		if(j >= m){
			ans++;
			j = 0;
		}
	}
	return ans;
}

int main(){
	while(true){
		scanf("%s",str1);
		if(str1[0] == '#')
			break;
		scanf("%s",str2);
		printf("%d\n",kmp(str1,str2));
	}
	return 0;
}
