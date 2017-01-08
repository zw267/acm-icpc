                                            
  //File Name: hdu2594.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 23时32分52秒
                                   

#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#define next Next

using namespace std;

const int MAXN = 50000 + 3;

char str1[MAXN];
char str2[MAXN];
int next[MAXN];
int extend[MAXN];

void ekmp_pre(const char *x,int *next){
	int m = strlen(x);
	next[0] = m;
	int j = 0;
	while(j + 1 < m && x[j] == x[j + 1])
		j++;
	next[1] = j;
	int k = 1;
	for(int i=2;i<m;i++){
		int p = next[k] + k - 1;
		int l = next[i - k];
		if(i + l < p + 1)
			next[i] = l;
		else{
			j = max(0,p - i + 1);
			while(j + i < m && x[i + j] == x[j])
				j++;
			next[i] = j;
			k = i;
		}
	}
}

void ekmp(char *y,char *x,int *next,int *extend){
	ekmp_pre(x,next);
	int n = strlen(y);
	int m = strlen(x);
	int j = 0;
	while(j < n && j < m && x[j] == y[j])
		j++;
	extend[0] = j;
	int k = 0;
	for(int i=1;i<n;i++){
		int p = extend[k] + k - 1;
		int l = next[i - k];
		if(i + l < p + 1)
			extend[i] = l;
		else{
			j = max(0,p - i + 1);
			while(i + j < n && j < m && y[i + j] == x[j])
				j++;
			extend[i] = j;
			k = i;
		}
	}
}

void solve(){
	ekmp(str1,str2,next,extend);
	int n = strlen(str1);
	int ans = 0;
	for(int i=0;i<n;i++){
		if(extend[i] == n - i && extend[i] > ans){
			ans = extend[i];
		}
	}
	if(ans == 0)
		puts("0");
	else{
		for(int i=0;i<ans;i++)
			printf("%c",str2[i]);
		printf(" %d\n",ans);
	}
	return ;
}

int main(){
	while(~scanf("%s",str2)){
		scanf("%s",str1);
		solve();
	}
	return 0;
}
