                                            
  //File Name: nod1120.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月27日 星期五 15时46分58秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = 10007;

LL jie[MOD];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init(){
	jie[0] = 1;
	for(int i=1;i<MOD;i++)
		jie[i] = jie[i-1] * i % MOD;
}

LL get_c(int x,int y){
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x-y] % MOD,MOD - 2) % MOD;
}

LL lucas(LL x,LL y){
	LL ans = 1;
	int u,v;
	while(x > 0 || y > 0){
		u = x % MOD;
		v = y % MOD;
		ans = ans * get_c(u,v) % MOD;
		x /= MOD;
		y /= MOD;
	}
	return ans;
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		n--;
		printf("%d\n",(int)lucas(2*n,n) * qp(n+1,MOD-2) * 2 % MOD);
	}
	return 0;
}
