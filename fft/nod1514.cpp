                                            
  //File Name: nod1514.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月18日 星期五 17时17分25秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 262144;
const int p = 998244353;
const int g = 3;
LL A[MAXN + 3],B[MAXN + 3],tmp[MAXN + 3],w[2][MAXN + 3];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
void ntt_init(int n){
	w[0][0] = w[0][n] = w[1][0] = w[1][n] = 1;
	LL G = qp(g,(p - 1) / n);
	for(int i=1;i<n;i++)
		w[0][i] = w[0][i-1] * G % p;
	for(int i=1;i<n;i++)
		w[1][i] = w[0][n - i];
}
void ntt(int n,LL *x,LL *w){
	for(int i=0,j=0;i<n;i++){
		if(i > j) swap(x[i],x[j]);
		for(int l=n>>1;(j^=l)<l;l>>=1);
	}
	for(int i=2;i<=n;i<<=1){
		int m = i >> 1;
		for(int j=0;j<n;j+=i){
			for(int l=0;l<m;l++){
				LL t = x[j + l + m] * w[MAXN / i * l] % p;
				x[j + l + m] = (x[j + l] - t + p) % p;
				x[j + l] = (x[j + l] + t) % p;
			}
		}
	}
}
void polynomial_inverse(int deg,LL *a,LL *b,LL *tmp){
	if(deg == 1){
		b[0] = qp(a[0],p - 2);
		return ;
	}
	polynomial_inverse((deg + 1) >> 1,a,b,tmp);
	int n = 1;
	for(;n < (deg << 1);n <<= 1);
	copy(a,a+deg,tmp);
	fill(tmp+deg,tmp+n,0);
	ntt(n,tmp,w[0]);
	ntt(n,b,w[0]);
	for(int i=0;i<n;i++){
		b[i] = (2 - tmp[i] * b[i] % p) * b[i] % p;
		if(b[i] < 0) b[i] += p;
	}
	ntt(n,b,w[1]);
	LL inv_n = qp(n,p - 2);
	for(int i=0;i<n;i++)
		b[i] = b[i] * inv_n % p;
	fill(b + deg,b + n,0);
}
void init(){
	ntt_init(MAXN);
	int n = 100001;
	A[0] = 1;
	for(int i=1;i<n;i++)
		A[i] = A[i - 1] * i % p;
	polynomial_inverse(n,A,B,tmp);
	for(int i=0;i<n;i++)
		B[i] = (-B[i] + p) % p;
	B[0] = (B[0] + 1) % p;
}
int main(){
	init();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",B[n]);
	}
	return 0;
}
