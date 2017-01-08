                                            
  //File Name: hdu5750.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月25日 星期一 21时31分19秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 10000000;

bool check[MAXN];
int prime[MAXN],tot;
int s[MAXN];

void init(){
	tot = 0;
	memset(check,false,sizeof check);
	memset(s,0,sizeof s);
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			s[i] = 1;
		}
		for(int j=0;j<tot && prime[j] * i < MAXN;j++){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i=2;i<MAXN;i++)
		s[i] += s[i-1];
}

bool is(int x){
	for(int i=0;i<tot;i++){
		if(x % prime[i] == 0) 
			return false;
	}
	return true;
}

int solve(int n,int d){
	int r = (n - 1) / d;
	for(int i=0;i<tot && prime[i] < r;i++){
		if(d % prime[i] == 0){
			r = prime[i];
			break;
		}
	}
	if(r < MAXN) return s[r];
	int ans = s[MAXN-1];
	for(int i=MAXN;i<=r;i++){
		if(is(i))
			ans++;
	}
	return ans;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n,d;
		scanf("%d %d",&n,&d);
		printf("%d\n",solve(n,d));
	}
	return 0;
}
