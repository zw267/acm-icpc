                                            
  //File Name: cf392C.cpp
  //Created Time: 2017年05月10日 星期三 01时31分02秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 83;
const int P = (int)1e9 + 7;
struct matrix_t{
	LL a[MAXN][MAXN];
	int n;
	matrix_t(LL v = 0,int _n = 1){
		n = _n;
		memset(a,0,sizeof a);
		for(int i=0;i<n;++i)
			a[i][i] = v;
	}
	matrix_t operator*(const matrix_t &r) const{
		matrix_t res(0,n);
		for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				if(!a[i][k]) continue;
				for(int j=0;j<n;++j){
					res.a[i][j] += a[i][k] * r.a[k][j];
					res.a[i][j] %= P;
				}
			}
		}
		return res;
	}
	matrix_t power(LL y) const{
		matrix_t res(1,n);
		matrix_t x = *this;
		for(;y>0;y>>=1){
			if(y & 1) res = res * x;
			x = x * x;
		}
		return res;
	}
};
matrix_t mat;
LL p2[MAXN],f[MAXN],comb[MAXN][MAXN];
void init(){
	p2[0] = 1;
	for(int i=1;i<MAXN;++i)
		p2[i] = p2[i - 1] * 2 % P;
	for(int i=0;i<MAXN;++i){
		comb[i][0] = 1;
		for(int j=1;j<=i;++j){
			comb[i][j] += comb[i-1][j] + comb[i-1][j-1];
			if(comb[i][j] >= P)
				comb[i][j] -= P;
		}
	}
}
LL solve(const LL n,const int m){
	init();
	int ma = m + m + 2;
	for(int i=0;i<=m;++i)
		f[i] = 1;
	for(int i=m+1;i<ma;++i)
		f[i] = p2[i - m];
	f[ma] = f[m] + f[m + m + 1];
	if(n == 1) return 1;
	else if(n == 2) return f[ma];
	mat = matrix_t(0,ma + 1);
	for(int i=0;i<=m;++i)
		mat.a[i][m + 1 + i] = 1;
	for(int i=m+1;i<ma;++i){
		int x = i - m - 1;
		for(int j=0;j<=x;++j)
			mat.a[i][j] = comb[x][j] * p2[x - j] % P;
		for(int j=m+1;j<=m+x+1;++j)
			mat.a[i][j] = comb[x][j-m-1];
	}
	for(int j=0;j<=m+m+1;++j)
		mat.a[ma][j] = mat.a[ma - 1][j];
	mat.a[ma][ma] = 1;
	mat = mat.power(n - 2);
	LL res(0);
	for(int i=0;i<=ma;++i){
		res += mat.a[ma][i] * f[i];
		res %= P;
	}
	return res;
}
int main(){
	LL n;
	int m;
	scanf("%lld %d",&n,&m);
	printf("%lld\n",solve(n,m));
	return 0;
}
