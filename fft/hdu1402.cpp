                                            
  //File Name: hdu1402.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月07日 星期一 15时29分22秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 200010;

struct complex_t
{
	double r,i;
	complex_t(double _r = 0.0,double _i = 0.0){
		r = _r;
		i = _i;
	}
	complex_t operator+(const complex_t &b){
		return complex_t(r+b.r,i+b.i);
	}
	complex_t operator-(const complex_t & b){
		return complex_t(r-b.r,i-b.i);
	}
	complex_t operator*(const complex_t &b){
		return complex_t(r*b.r - i * b.i,r * b.i + i * b.r);
	}
};

complex_t f[MAXN],g[MAXN];
complex_t eps[MAXN],inv_eps[MAXN];
char str1[MAXN >> 1];
char str2[MAXN >> 1];
int ans[MAXN];

void init_eps(int p)
{
	double pi = acos(-1.0);
	for(int i=0;i!=p;i++){
		eps[i] = complex_t(cos(2.0 * pi * i / p),sin(2.0 * pi * i / p));
		inv_eps[i] = complex_t(eps[i].r,-eps[i].i);
	}
}

void fft(int n,complex_t *x,complex_t *w)
{
	for(int i=0,j=0;i!=n;i++){
		if(i < j)
			swap(x[i],x[j]);
		for(int l=n>>1;(j ^= l) < l;l >>= 1);
	}
	for(int i=2;i<=n;i <<= 1){
		int m = i >> 1;
		for(int j=0;j<n;j+=i){
			for(int k=0;k!=m;k++){
				complex_t z = x[j+m+k] * w[n / i * k];
				x[j+m+k] = x[j+k] - z;
				x[j+k] = x[j+k] + z;
			}
		}
	}
}

void solve()
{
	//printf("%s\n%s\n",str1,str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i!=len1;i++){
		f[i] = complex_t(str1[len1-1-i] - '0',0);
	}
	for(int i=0;i!=len2;i++){
		g[i] = complex_t(str2[len2-1-i] - '0');
	}
	
	int len = max(len1,len2);
	int p = 1;
	while(p < len)
		p <<= 1;		
	p <<= 1;
	for(int i=len1;i!=p;i++)
		f[i] = complex_t(0,0);
	for(int i=len2;i!=p;i++)
		g[i] = complex_t(0,0);
	
	init_eps(p);
	fft(p,f,eps);
	fft(p,g,eps);
	for(int i=0;i!=p;i++)
		f[i] = f[i] * g[i];
	fft(p,f,inv_eps);
	for(int i=0;i!=p;i++)
		f[i].r /= p;
	for(int i=0;i!=p;i++)
		ans[i] = (int)(f[i].r + 0.5);
	for(int i=0;i!=p;i++){
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
	len = len1+len2-1;
	while(ans[len] <= 0 && len > 0)
		len--;
	for(int i=len;i>=0;i--)
		printf("%c",ans[i] + '0');
	puts("");
	return ;
}

int main()
{
	while(~scanf("%s %s",str1,str2)){
		solve();
	}
	return 0;
}
