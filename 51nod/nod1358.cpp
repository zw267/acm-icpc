                                            
  //File Name: nod1358.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月16日 星期六 15时32分58秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = (int)1e9 + 7;
const int N = 34;

struct matrix_t{
	LL x[N+1][N+1];
	matrix_t(LL v = 1){
		memset(x,0,sizeof x);
		for(int i=1;i<=N;i++)
			x[i][i] = v;
	}
	matrix_t operator *(const matrix_t &r){
		matrix_t p(0);
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				if(x[i][k] == 0) continue;
				for(int j=1;j<=N;j++){
					p.x[i][j] += x[i][k] * r.x[k][j] % MOD;
					p.x[i][j] %= MOD;
				}
			}
		}
		return p;
	}
	matrix_t power(LL p){
		matrix_t r(1),a = *this;
		for(;p;p>>=1){
			if(p & 1) r = r * a;
			a = a * a;
		}
		return r;
	}
}b;

LL solve(LL n){
	if(n <= 40) return 1;
	for(int j=1;j<=N;j++){
		if(j == 10 || j == 34)
			b.x[1][j] = 1;
		else
			b.x[1][j] = 0;
	}
	for(int i=2;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(j == i - 1)
				b.x[i][j] = 1;
			else
				b.x[i][j] = 0;
		}
	}
	b = b.power(n - 40);
	LL ans = 0;
	for(int j=1;j<=N;j++)
		(ans += b.x[1][j]) %= MOD;
	return ans;
}

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		printf("%lld\n",solve(n * 10));
	}
	return 0;
}
