                                            
  //File Name: cf223C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月27日 星期五 21时49分42秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 200 + 3;
const int MOD = (int)1e9 + 7;

struct matrix_t{
	int n;
	int x[MAXN][MAXN];
	matrix_t(int _n = 1,int v = 1){
		n = _n;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++) x[i][i] = v;
	}
	void update(int _n){
		n = _n;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i > j) x[i][j] = 0;
				else x[i][j] = 1;
			}
		}
	}
	matrix_t operator*(const matrix_t &r){
		matrix_t p = 0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(x[i][k] == 0) continue;
				for(int j=1;j<=n;j++){
					p.x[i][j] += x[i][k] * r.x[k][j];
					p.x[i][j] %= MOD;
				}
			}
		}
		return p;
	}
	matrix_t power(LL p){
		matrix_t r(this->n,1),a = *this;
		for(;p;p>>=1){
			if(p & 1) r = r * a;
			a = a * a;
		}
		return r;
	}
}mat;

LL a[MAXN];
LL f[MAXN];

void solve(int n,int k){
	if(k == 0){
		for(int i=1;i<=n;i++){
			printf("%d",(int)a[i]);
			i == n ? puts(""):printf(" ");
		}
		return ;
	}
	mat.update(n);
	mat = mat.power(k-1);
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			(f[i] += mat.x[n-i+1][j]) %= MOD;
		}
	}
	LL ans;
	for(int i=1;i<=n;i++){
		ans = 0;
		for(int j=1;j<=i;j++){
			(ans += a[j] * f[i-j+1]) %= MOD;
		}
		printf("%d",(int)ans);
		i == n ? puts(""):printf(" ");
	}
	return ;
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve(n,k);
	}
	return 0;
}
