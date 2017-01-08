                                            
  //File Name: hdu4609.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月27日 星期三 15时14分22秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 1<<18;

struct complex_t{
	double r,i;
	complex_t(double _r = 0.0,double _i = 0.0){
		r = _r,i = _i;
	}
	complex_t operator+(const complex_t &b){
		return complex_t(r + b.r,i + b.i);
	}
	complex_t operator-(const complex_t &b){
		return complex_t(r - b.r,i - b.i);
	}
	complex_t operator*(const complex_t &b){
		return complex_t(r * b.r - i * b.i,r * b.i + i * b.r);
	}
};

complex_t f[MAXN],g[MAXN];
complex_t eps[MAXN],inv_eps[MAXN];
int num[MAXN],a[MAXN];
LL s[MAXN];

void init_eps(int p){
	double pi = acos(-1.0);
	for(int i=0;i!=p;i++){
		eps[i] = complex_t(cos(2.0 * pi * i / p),sin(2.0 * pi * i / p));
		inv_eps[i] = complex_t(eps[i].r,-eps[i].i);
	}
}

void fft(int n,complex_t *x,complex_t *w){
	for(int i=0,j=0;i!=n;i++){
		if(i < j) swap(x[i],x[j]);
		for(int l=n>>1;(j^=l) < l;l>>=1);
	}
	for(int i=2;i<=n;i<<=1){
		int m = i >> 1;
		for(int j=0;j<n;j+=i){
			for(int k=0;k!=m;k++){
				complex_t z = x[j + m + k] * w[n / i * k];
				x[j + m + k] = x[j + k] - z;
				x[j + k] = x[j + k] + z;
			}
		}
	}
}

double solve(int n,int N){
	for(int i=0;i<n;i++){
		f[i] = complex_t(num[i],0);
		g[i] = f[i];
	}
	int p = 1;
	while(p < n){
		p <<= 1;
	}
	p <<= 1;
	for(int i=n;i!=p;i++){
		f[i] = complex_t(0.0,0.0);
		g[i] = f[i];
	}
	init_eps(p);
	fft(p,f,eps);
	fft(p,g,eps);
	for(int i=0;i!=p;i++)
		f[i] = f[i] * g[i];
	fft(p,f,inv_eps);
	for(int i=0;i!=p;i++)
		f[i].r /= p;
	for(int i=0;i!=p;i++)
		s[i] = (LL)(f[i].r + 0.5);
	//for(int i=0;i<p;i++)
	//	printf("i = %d s = %lld\n",i,s[i]);
	for(int i=0;i<p;i++){
		if((i & 1) == 0){
			s[i] -= num[i / 2];
		}
		s[i] /= 2;
	}
	//for(int i=0;i<p;i++){
	//	printf("i = %d s = %lld\n",i,s[i]);
	//}
	for(int i=1;i<p;i++)
		s[i] += s[i-1];
	sort(a,a+N);
	LL ans = 0,tmp;
	for(int i=0;i<N;i++){
		tmp = s[p-1] - s[a[i]] - (LL)(N - 1 - i) * (N - 2 - i) / 2
			- (LL)(N - 1 - i) * i - (N - 1);
		ans += tmp;
		//printf("i = %d s = %lld\n",a[i],tmp);
	}
	return (double) ans / ((LL)N * (N - 1) * (N - 2) / 6);
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		memset(num,0,sizeof num);
		int ma = -1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
			if(a[i] > ma) ma = a[i];
		}
		ma++;
		printf("%.7f\n",solve(ma,n));
	}
	return 0;
}
