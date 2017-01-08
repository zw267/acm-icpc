                                            
  //File Name: nod1113.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 00时14分21秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 101;
const int MOD = (int)1e9 + 7;

struct matrix_t{
	int n;
	LL x[MAXN][MAXN];
	matrix_t(int _n = 1,int v = 1){
		n = _n;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++) x[i][i] = v;
	}
	matrix_t operator*(const matrix_t &r){
		matrix_t p(n,0);
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(x[i][k] == 0) continue;
				for(int j=1;j<=n;j++){
					p.x[i][j] += x[i][k] * r.x[k][j] % MOD;
					p.x[i][j] %= MOD;
				}
			}
		}
		return p;
	}
	matrix_t power(LL p){
		matrix_t r(n,1),a = *this;
		for(;p;p>>=1){
			if(p & 1) r = r * a;
			a = a * a;
		}
		return r;
	}
}res;

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		res = matrix_t(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%lld",&res.x[i][j]);
			}
		}
		res = res.power(m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<n;j++){
				printf("%lld ",res.x[i][j]);
			}
			printf("%lld\n",res.x[i][n]);
		}
	}
	return 0;
}
