                                            
  //File Name: hdu4300.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月27日 星期三 22时41分17秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define next nextnext

using namespace std;

const int MAXN = 100000 + 3;

char pre[MAXN];
char aft[MAXN];
int next[MAXN];
int extend[MAXN];
char chg[26];
char ch[26];

void ekmp_pre(char *x,int *next){
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
	int n = strlen(pre);
	for(int i=0;i<n;i++){
		aft[i] = chg[pre[i] - 'a'];
	}
	ekmp(pre,aft,next,extend);
	int ans = n;
	for(int i=n-1;i>0;i--){
		if(extend[i] == n - i && n <= 2 * i && i < ans){
			ans = i;
		}
	}
	for(int i=0;i<ans;i++)
		printf("%c",pre[i]);
	for(int i=0;i<ans;i++)
		printf("%c",aft[i]);
	puts("");
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",ch);
		for(int i=0;i<26;i++){
			chg[ch[i] - 'a'] = (char)'a' + i;
		}
		scanf("%s",pre);
		solve();
	}
	return 0;
}
