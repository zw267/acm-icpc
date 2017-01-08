                                            
  //File Name: uva11426.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 18时44分33秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 4000000 + 1;
bool check[MAXN];
int prime[MAXN],mu[MAXN];
LL g[MAXN];
void init(){
	memset(check,false,sizeof(check));
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<MAXN;i++){
		for(int j=i;j<MAXN;j+=i){
			g[j] += mu[i] * j / i;
		}
	}
	for(int i=1;i<MAXN;i++)
		g[i] += g[i - 1];
}
int gcd(int x,int y){
	return (!y)?x:gcd(y,x % y);
}
LL solve(int n){
	LL res = 0;
	for(int k=1;k<=n;){
		int x = n / k;
		int r = n / x;
		res += 1LL * x * x * (g[r] - g[k - 1]);
		k = r + 1;
	}
	LL tmp = 0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			tmp += gcd(i,j);
//		}
//	}
//	printf("res = %lld tmp = %lld\n",res,tmp);
	res = (res - (1LL + n) * n / 2) / 2;
	return res;
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		if(!n) break;
		printf("%lld\n",solve(n));
	}
	return 0;
}
