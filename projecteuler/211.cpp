                                            
  //File Name: 211.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月07日 星期一 11时05分14秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
const int MAXN = 64000000;
int prime[MAXN];
bool check[MAXN];
LL f[MAXN];
LL cal(LL x){
	LL res = 0;
	for(LL i=1;i*i<=x;i++){
		if(x % i == 0){
			res += i * i;
			if(x / i != i)
				res += (x / i) * (x / i);
		}
	}
	return res;
}
/*
LL bs(LL x){
	LL l = 1,r = (LL)sqrt(10000000000000000);
	if(r * r <= x) return r;
	while(r - l > 1){
		LL m = l + r >> 1;
		if(m * m <= x) l = m;
		else r = m;
	}
	if(r * r <= x) return r;
	return l;
}
*/
LL solve(){
	memset(check,false,sizeof(check));
	int tot = 0;
	f[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			f[i] = 1 + (LL)i * i;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				LL x = i,u = 1;
				while(x % prime[j] == 0)
					x /= prime[j],u *= prime[j];
				f[i * prime[j]] = f[i] + f[x]*u*u*prime[j]*prime[j];
//				LL tmp = cal(i * prime[j]);
//				if(tmp != f[i * prime[j]]){
//					printf("i = %d\n",i);
//					printf("f = %lld\n",f[i * prime[j]]);
//					printf("tmp = %lld\n",tmp);
//					puts("not");
//					return -1;
//				} 
				break;
			}
			else{
				f[i * prime[j]] = f[i] * f[prime[j]];
//				LL tmp = cal(i * prime[j]);
//				if(tmp != f[i * prime[j]]){
//					LL tmp = cal(i);
//					printf("i = %d f = %lld tmp = %lld\n",i,f[i],tmp);
//					return -2;
//				}
			}
		}
	}
	LL res = 0;
//	for(int i=1;i<MAXN;i++){
//		LL u = cal(i);
//		if(u != f[i]){
//			printf("i = %d u = %lld f = %lld\n",i,u,f[i]);
//			res++;		
//		}
//	}
//	return res;
	for(int i=1;i<MAXN;i++){
		LL u = (LL)sqrt(f[i] + 0.0);
		if(u * u == f[i])
			res += i;
	}
	return res;
}
int main(){
	printf("%lld\n",solve());
	return 0;
}
