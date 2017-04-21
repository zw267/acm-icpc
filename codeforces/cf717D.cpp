                                            
  //File Name: cf717D.cpp
  //Created Time: 2017年04月21日 星期五 21时05分54秒
                                   
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 128;
double f[MAXN];
double p[MAXN];
struct matrix_t{
	double a[MAXN][MAXN];
	matrix_t(double _v = 0){
		for(int i=0;i<MAXN;++i)
			for(int j=0;j<MAXN;++j)
				if(i == j) a[i][j] = _v;
				else a[i][j] = 0.0;
	}
	matrix_t operator*(const matrix_t &r) const{
		matrix_t p = 0;
		for(int k=0;k<MAXN;++k){
			for(int i=0;i<MAXN;++i){
				if(a[i][k] == 0.0) continue;
				for(int j=0;j<MAXN;++j){
					p.a[i][j] += a[i][k] * r.a[k][j];
				}
			}
		}
		return p;
	}
	matrix_t power(LL y){
		matrix_t r = 1,a = *this;
		for(;y>0;y>>=1){
			if(y & 1) r = r * a;
			a = a * a;
		}
		return r;
	}
};
matrix_t mat;
double solve(int n,int x){
	f[0] = 1.0;
	for(int j=0;j<MAXN;++j){
		for(int i=0;i<MAXN;++i){
			mat.a[j][j ^ i] = p[i];
		}
	}
	mat = mat.power(n);
	double res = 0.0;
	for(int i=1;i<MAXN;++i){
		res += mat.a[i][0];
	}
	return res;
}
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=0;i<=x;++i)
		scanf("%lf",&p[i]);
	for(int i=x+1;i<MAXN;++i)
		p[i] = 0.0;
	printf("%.14f\n",solve(n,x));
	return 0;
}
