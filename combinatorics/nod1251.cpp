                                            
  //File Name: nod1251.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月08日 星期六 14时39分39秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 200000 + 10;
const int MOD = (int)1e9 + 7;
LL jie[MAXN],inv[MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y;y>>=1){
		if(y & 1) res = res * x % MOD;
		x =x * x % MOD;
	}
	return res;
}
void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		jie[i] = jie[i-1] * i % MOD;
	for(int i=0;i<MAXN;i++)
		inv[i] = qp(jie[i],MOD - 2);
}
LL solve(int n,int m){
	if(m == 1) return 1;
	LL ans = 0,tmp;
	for(int i=1,ma;i<=n;i++){
		ma = (n - i) / i;
		for(int j=0;j<=ma;j++){
			if(m - 1 < j) continue;
			tmp = jie[n-(j+1)*i+m-2]*inv[m-2]%MOD*inv[n-(j+1)*i]%MOD;
			tmp = tmp*jie[m-1]%MOD*inv[j]%MOD*inv[m-1-j]%MOD;
			if(j & 1) ans = (ans - tmp + MOD) % MOD;
			else ans = (ans + tmp) % MOD;
		}
	}
	return ans * m % MOD;
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
