                                            
  //File Name: nod1594.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月08日 星期二 00时58分49秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 2000000 + 1;
int prime[MAXN],phi[MAXN],mu[MAXN],s[MAXN];
LL g[MAXN];
bool check[MAXN];
void init(){
	memset(check,false,sizeof(check));
	int tot = 0;
	phi[1] = 1;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				mu[i * prime[j]] = 0;
				break;
			}
			else{
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}
LL solve(int n){
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
		s[phi[i]]++;
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i)
			g[i] += s[j];
	}
	for(int i=1;i<=n;i++)
		g[i] = g[i] * g[i];
	LL res = 0,tmp;
	for(int d=1,ma;d<=n;d++){
		tmp = 0;
		ma = n /d;
		for(int i=1;i<=ma;i++)
			tmp += g[i * d] * mu[i];
		tmp *= phi[d];
		res += tmp;
	}
	return res;
}
int main(){
	init();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}
