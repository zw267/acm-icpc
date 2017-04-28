                                            
  //File Name: cf514E.cpp
  //Created Time: 2017年04月26日 星期三 13时38分32秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 101;
const int P = (int)1e9 + 7;
struct matrix_t{
	LL a[MAXN][MAXN];
	matrix_t(int v = 1){
		memset(a,0,sizeof a);
		for(int i=0;i<MAXN;++i)
			a[i][i] = v;
	}
	matrix_t operator *(const matrix_t &r) const{
		matrix_t res(0);
		for(int k=0;k<MAXN;++k){
			for(int i=0;i<MAXN;++i){
				if(!a[i][k]) continue;
				for(int j=0;j<MAXN;++j){
					res.a[i][j] += a[i][k] * r.a[k][j] % P;
					if(res.a[i][j] >= P) 
						res.a[i][j] -= P;
				}
			}
		}
		return res;
	}
	matrix_t power(LL y) const{
		matrix_t res(1),x = *this;
		for(;y>0;y>>=1){
			if(y & 1) res = res * x;
			x = x * x;
		}
		return res;
	}
};
matrix_t mat(0);
int s[MAXN];
LL f[MAXN];
LL solve(const int n,const int x){
	f[0] = 1;
	for(int i=0;i<100;++i){
		for(int d=1;d<=i;++d){
			f[i] += f[i-d] * s[d];
		}
		f[i] %= P;
		f[100] += f[i];
		if(f[100] >= P) f[100] -= P;
	}
	LL res(0);
	if(x < 100){
		for(int i=0;i<=x;++i){
			res += f[i];
			if(res >= P) res -= P;
		}
		return res;
	}
	mat.a[0][0] = 1;
	for(int i=1;i<=100;++i)
		mat.a[0][i] = mat.a[1][i] = s[i];
	for(int i=2;i<101;++i)
		mat.a[i][i - 1] = 1;
	mat = mat.power(x - 99);
	for(int i=0;i<MAXN;++i){
		res += mat.a[0][i] * f[100 - i] % P;
		if(res >= P) res -= P;
	}
	return res;
}
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=1,u;i<=n;++i){
		scanf("%d",&u);
		++s[u];
	}
	printf("%lld\n",solve(n,x));
	return 0;
}
