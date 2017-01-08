                                            
  //File Name: cf660E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月24日 星期二 17时26分18秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;
const int MOD = (int)1e9 + 7;

LL p1[MAXN],p2[MAXN];

void init(int n,int m){
	p1[0] = 1,p2[0] = 1;
	for(int i=1;i<=n;i++){
		p1[i] = p1[i-1] * m % MOD;
		p2[i] = p2[i-1] * (2 * m - 1) % MOD;	
	}
}

LL solve(int n,int m){
	init(n,m);
	LL ans = p1[n];
	for(int i=0;i<n;i++){
		ans = (ans + p1[n-i] * p2[i] % MOD) % MOD;
	}
	return ans;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d\n",(int)solve(n,m));
	return 0;
}
