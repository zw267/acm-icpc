                                            
  //File Name: 365.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月06日 星期日 20时41分31秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 5000;
int prime[MAXN],m[505],a[505];
bool check[MAXN];
int init(){
	memset(check,false,sizeof(check));
	int len = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i])
			prime[len++] = i;
		for(int j=0;j<len;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	int tot = 0;
	for(int i=0;i<len;i++){
		if(prime[i] > 1000 && prime[i] < 5000)
			m[tot++] = prime[i];
	}
	return tot;
}
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
LL C(LL x,LL y,LL p){
	if(x < y) return 0;
	if(y == 0 || y == x) return 1;
	LL res = 1;
	y = min(y,x - y);
	for(int i=x-y+1;i<=x;i++)
		res = i * res % p;
	for(int i=2;i<=y;i++)
		res = res * qp(i,p - 2,p) % p;
	return res;
}
LL lucas(LL x,LL y,LL p){
	LL res = 1;
	while(x > 0 || y > 0){
		(res *= C(x % p,y % p,p)) %= p;
		x /= p;
		y /= p;
	}
	return res;
}
LL crt(int n,int *a,int *m){
	LL M = 1,res = 0;
	for(int i=0;i<n;i++) M *= m[i];
	for(int i=0;i<n;i++){
		LL w = M / m[i];
		LL inv = qp(w % m[i],m[i] - 2,m[i]);
		res = (res + inv * w % M * a[i]) % M;
	}
	return res;
}
LL solve(LL x,LL y){
	int tot = init();
	for(int i=0;i<tot;i++)
		a[i] = lucas(x,y,m[i]);
	LL res = 0;
	for(int i=0;i<tot;i++){
		for(int j=i+1;j<tot;j++){
			for(int k=j+1;k<tot;k++){
				int aa[3] = {a[i],a[j],a[k]};
				int mm[3] = {m[i],m[j],m[k]};
				res += crt(3,aa,mm);
			}
		}
	}
	return res;
}
int main(){
	LL x = 1000000000000000000;
	LL y = 1000000000;
	printf("%lld\n",solve(x,y));
	return 0;
}
