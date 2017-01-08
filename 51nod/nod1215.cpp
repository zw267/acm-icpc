                                            
  //File Name: nod1215.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月16日 星期四 00时30分19秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 50000 + 3;

int l1[MAXN],l2[MAXN],r1[MAXN],r2[MAXN];
int a[MAXN];

void init(int n){
	for(int i=1;i<=n;i++){
		l1[i] = l2[i] = i - 1;
		r1[i] = r2[i] = i + 1;
	}
	for(int i=1;i<=n;i++){
		while(l1[i] && a[l1[i]] < a[i]){
			l1[i] = l1[l1[i]];
		}
		while(l2[i] && a[l2[i]] > a[i]){
			l2[i] = l2[l2[i]];
		}
	}
	for(int i=n;i>0;i--){
		while(r1[i] <= n && a[r1[i]] <= a[i]){
			r1[i] = r1[r1[i]];
		}
		while(r2[i] <= n && a[r2[i]] >= a[i]){
			r2[i] = r2[r2[i]];
		}
	}
	//for(int i=1;i<=n;i++)
	//	printf("i = %d l = %d r = %d\n",i,l2[i],r2[i]);
}

LL solve(int n){
	init(n);
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans += (LL)a[i] * ((LL)(i - l1[i]) * (r1[i] - i) - (LL)(i - l2[i]) * (r2[i] - i));
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%lld\n",solve(n));
	}
	return 0;
}
