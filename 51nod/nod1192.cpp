                                            
  //File Name: nod1192.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月07日 星期一 23时56分50秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 5000000 + 1;
bool check[MAXN];
int prime[MAXN];
int f[MAXN],mu[MAXN];
void init(){
	memset(check,false,sizeof(check));
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			mu[i] = -1;
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = mu[i] * mu[prime[j]];
		}
	}
	for(int i=0;i<tot;i++){
		for(int j=prime[i];j<MAXN;j+=prime[i]){
			f[j] += mu[j / prime[i]];
		}
	}
	for(int i=2;i<MAXN;i++)
		f[i] += f[i-1];
}
LL solve(int n,int m){
	if(n > m) swap(n,m);
	LL res = 0;
	for(int i=1;i<=n;){
		int x = n / i,y = m / i;
		int r = min(n / x,m / y);
		res += 1LL * x * y * (f[r] - f[i - 1]);
		i = r + 1;
	}
	return res;
}
int main(){
	init();
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
