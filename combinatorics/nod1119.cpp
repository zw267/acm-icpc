                                            
  //File Name: nod1119.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月27日 星期五 14时34分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define LL long long

const int MAXN = 2000000 + 3;
const int MOD = (int)1e9 + 7;

LL jie[MAXN];

void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
}

LL qp(LL x){
	LL res = 1, y = MOD - 2;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get_c(int x,int y){
	if(x < y) return 0;
	if(x == y || y == 0) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD) % MOD;
}

int main(){
	init();
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		printf("%d\n",(int)get_c(n+m-2,n-1));
	}
	return 0;
}
