                                            
  //File Name: 51nod1028.cpp
  //Created Time: 2017年04月12日 星期三 20时17分32秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 18;
char s1[MAXN],s2[MAXN];
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
	complex_t conj(){
		return complex_t(r,-i);
	}
};
complex_t f[MAXN],g[MAXN];
complex_t w[2][MAXN];
int ans[MAXN];
int tot;
void init_w(int n){
	double pi = acos(-1.0);
	for(int i=0;i<n;++i){
		w[0][i] = complex_t(cos(2.0 * pi * i / n),sin(2.0 * pi * i / n));
		w[1][i] = w[0][i].conj();
	}
}
void fft(int n,complex_t *x,complex_t *w){
	for(int i=0,j=0;i!=n;++i){
		if(i > j) swap(x[i],x[j]);
		for(int l=n>>1;(j^=l)<l;l>>=1);
	}
	for(int i=2;i<=n;i<<=1){
		int m = i >> 1;
		for(int j=0;j<n;j+=i){
			for(int k=0;k!=m;++k){
				complex_t z = x[j + m + k] * w[n / i * k]; //
				x[j + m + k] = x[j + k] - z;
				x[j + k] = x[j + k] + z;
			}
		}
	}
}
void solve(){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(int i=0;i<len1;++i)
		f[i] = complex_t(s1[len1 - 1 - i] - '0',0);
	for(int i=0;i<len2;++i)
		g[i] = complex_t(s2[len2 - 1 - i] - '0',0);
	tot = max(len1,len2);
	int p = 1;
	for(;p<(tot << 1);p<<=1);
	tot = p;
	init_w(tot);
	fft(tot,f,w[0]);
	fft(tot,g,w[0]);
	for(int i=0;i<tot;++i)
		f[i] = f[i] * g[i];
	fft(tot,f,w[1]);
	for(int i=0;i<tot;++i)
		f[i].r /= tot;
	for(int i=0;i<tot;++i)
		ans[i] = (int)(f[i].r + 0.5);
	for(int i=0;i<tot;++i){
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	tot = len1 + len2 - 1;
	while(tot > 0 && ans[tot] <= 0)
		--tot;
	for(int i=tot;i>=0;--i)
		printf("%d",ans[i]);
	puts("");

}
int main(){
	scanf("%s %s",s1,s2);
	solve();
	return 0;
}
