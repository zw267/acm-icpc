                                            
  //File Name: cf690D2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月11日 星期一 22时26分52秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iostream>

#define LL long long 

using namespace std;

const int MAXN = 700000 + 10;
const int MOD = (int)1e6 + 3;

LL jie[MAXN];

void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		jie[i] = jie[i-1] * i % MOD;
}

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get_C(int x,int y){
	if(x < 0 || y > x) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

LL solve(int n,int C){
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans + get_C(i + C - 1,i)) % MOD;
	}
	return ans;
}

int main(){
	init();
	int n,C;
	while(~scanf("%d %d",&n,&C)){
		printf("%d\n",(int)solve(n,C));
	}
	return 0;
}
