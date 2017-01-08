                                            
  //File Name: light1213.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 18时19分57秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL qp(LL x,LL y,LL mod){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
int main(){
	int t,cas = 1;
	scanf("%d",&t);
	while(t--){
		LL n,k,mod,a,sum = 0;
		scanf("%lld %lld %lld",&n,&k,&mod);
		for(int i=0;i<n;i++){
			scanf("%lld",&a);
			sum = (sum + a) % mod;
		}
		printf("Case %d: %lld\n",cas++,k * qp(n,k-1,mod) % mod * sum % mod);
	}
	return 0;
}
