                                            
  //File Name: light1236.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 14时39分26秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10000000 + 4;
bool check[MAXN];
int prime[MAXN / 10],tot;
int init(){
	memset(check,false,sizeof(check));
	tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
LL solve(LL n){
	LL res = 1;
	for(int i=0;i<tot;i++){
		if(prime[i] > n) break;
		if(n % prime[i] == 0){
			int now = 0;
			while(n % prime[i] == 0){
				now++;
				n /= prime[i];
			}
			res *= (2 * now + 1);
		}
	}
	if(n > 1) res *= 3;
	res = (res + 1) / 2;
	return res;
}
int main(){
	init();
	int t,cas = 1;
	scanf("%d",&t);
	while(t--){
		LL n;
		scanf("%lld",&n);
		printf("Case %d: %lld\n",cas++,solve(n));
	}
	return 0;
}
