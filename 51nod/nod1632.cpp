                                            
  //File Name: nod1632.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月30日 星期六 08时12分16秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 100000 + 2;
const int MOD = (int)1e9 + 7;

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

LL C(int x,int y){
	if(x < 0 || x < y) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

int solve(int n){
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans + C(n-1,i-1) * i % MOD) % MOD;
		//printf("%d %d %d\n",n-1,i-1,C(n-1,i-1));
	}
	return ans;
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		int u,v;
		for(int i=1;i<n;i++)
			scanf("%d %d",&u,&v);
		printf("%d\n",solve(n));
	}
	return 0;
}
