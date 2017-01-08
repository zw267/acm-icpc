                                            
  //File Name: hdu5747.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月25日 星期一 20时35分03秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 40;

LL p[MAXN];

void init(){
	p[0] = 1;
	for(int i=1;i<MAXN;i++)
		p[i] = p[i-1] * 2LL;
}

int solve(LL n,LL m){
	int ans = 0;
	for(int i=MAXN-1;i>=0;i--){
		if(i > m) continue;
		ans += n / p[i];
		n %= p[i];
	}
	return ans;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		LL n,m;
		cin >> n >> m;
		printf("%d\n",solve(n,m));
	}
	return 0;
}
