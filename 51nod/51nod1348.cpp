                                            
  //File Name: 51nod1348.cpp
  //Created Time: 2017年04月13日 星期四 23时42分12秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1 << 18;
const int P = 100003;
const double PI = acos(-1.0);
struct complex_t{
	long double r,i;
	complex_t(){}
	complex_t(long double _r,long double _i):r(_r),i(_i){}
	complex_t operator+(const complex_t &a) const{
		return complex_t(r + a.r,i + a.i);
	}
	complex_t operator-(const complex_t &a) const{
		return complex_t(r - a.r,i - a.i);
	}
	complex_t operator*(const complex_t &a) const{
		return complex_t(r * a.r - i * a.i,r * a.i + i * a.r);
	}
	complex_t operator*(const long double &a) const{
		return complex_t(r * a,i * a);
	}
	complex_t operator/(const long double &a) const{
		return complex_t(r / a,i / a);
	}
	void init(){
		r = i = 0;
	}
};
complex_t a[MAXN],b[MAXN];
vector<int> ans[MAXN];
int val[MAXN];
void fft(complex_t *a,int n,bool invert){
	for(int i=1,j=0;i<n;++i){
		int bit = n >> 1;
		for(;j>=bit;bit>>=1) j-= bit;
		j += bit;
		if(i < j) swap(a[i],a[j]);
	}
	for(int len=2;len<=n;len<<=1){
		long double ang = 2 * PI / len * (invert ? -1 : 1);
		complex_t wlen(cos(ang),sin(ang));
		for(int i=0;i<n;i+=len){
			complex_t w(1,0);
			for(int j=0;j<len / 2;++j){
				complex_t u = a[i + j],v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w = w * wlen;
			}
		}
	}
	if(invert){
		for(int i=0;i<n;++i)
			a[i] = a[i] / n;
	}
}
void solve(int l,int r){
	if(l == r){
		ans[l].push_back(1);
		ans[l].push_back(val[l]);
		return ;
	}
	int mid = l + r >> 1;
	solve(l,mid);
	solve(mid + 1,r);
	int t = 1;
	while(t <= r - l + 1)
		t <<= 1;
	for(int i=0;i<ans[l].size();++i)
		a[i] = complex_t(ans[l][i],0);
	for(int i=ans[l].size();i<t;++i)
		a[i] = complex_t(0,0);
	for(int i=0;i<ans[mid+1].size();++i)
		b[i] = complex_t(ans[mid+1][i],0);
	for(int i=ans[mid+1].size();i<t;++i)
		b[i] = complex_t(0,0);
	fft(a,t,0);
	fft(b,t,0);
	for(int i=0;i<t;++i)
		a[i] = a[i] * b[i];
	fft(a,t,1);
	ans[l].clear();
	ans[mid + 1].clear();
	for(int i=0;i<=r-l+1;++i)
		ans[l].push_back((LL)(a[i].r + 0.5) % P);
}
int main(){
	int n,q,x;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i){
		scanf("%d",val + i);
		val[i] %= P;
	}
	solve(0,n - 1);
	while(q--){
		scanf("%d",&x);
		printf("%d\n",ans[0][x]);
	}
	return 0;
}
