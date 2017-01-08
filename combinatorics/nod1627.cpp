                                            
  //File Name: nod1627.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月13日 星期三 14时15分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 200000 + 3;
const int MOD = (int)1e9 + 7;

LL jie[MAXN];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		jie[i] = jie[i-1] * i % MOD;
}

LL get_C(int x,int y){
	if(x < 0 || y > x) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x-y] % MOD,MOD - 2) % MOD;
}

int main(){
	init();
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		printf("%d\n",(int)get_C(n + m - 4,m - 2));
	}
	return 0;
}
