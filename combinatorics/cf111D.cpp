                                            
  //File Name: cf111D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月16日 星期一 01时13分24秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 1000 + 3;
const int MAXM = 1000000 + 3;
const int MOD = (int)1e9 + 7;

LL jie[MAXM];
LL g[MAXN];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get_c(LL x,LL y){
	if(x < y) return 0;
	if(x == y || y == 0) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

void init(int sum,int n){
	jie[0] = 1;
	for(int i=1;i<MAXM;i++)
		jie[i] = jie[i-1] * i % MOD;
	int ma = min(sum,n);
	LL now;
	for(int i=0;i<=ma;i++){
		for(int k=0;k<=i;k++){
			now = get_c(i,k) * qp(k,n) % MOD;
			if((i - k) % 2)
				g[i] = (g[i] - now + MOD) % MOD;
			else
				g[i] = (g[i] + now) % MOD;
		}
	}
}

LL solve(int n,int m,int sum){
	if(m == 1) return qp(sum,n);
	init(sum,n);
	LL ans = 0,now,tmp;
	int ma = min(sum,n);
	for(int j=0,ma2;j<=ma;j++){
		now = 0;
		ma2 = min(n - j,(sum - j) / 2);
		for(int i=0;i<=ma2;i++){
			(now += jie[sum-j] * qp(jie[sum-j-2*i]*jie[i]%MOD*jie[i]%MOD,MOD - 2) % MOD
				* g[i+j] % MOD * g[i+j] % MOD) %= MOD;
		}
		tmp = qp(j,(m - 2) * n) % MOD;
		(ans += get_c(sum,j) * tmp % MOD * now % MOD) %= MOD;
		//cout << j << " " <<ans << endl;
	}
	return ans;
}

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	printf("%d\n",(int)solve(n,m,k));
	return 0;
}
