                                            
  //File Name: light1282.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 13时29分18秒
                                   
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
	int t,n,k,cas = 1;
	cin >> t;
	while(t--){
		cin >> n >> k;
		double c = k * log10(n + 0.0);
		double d = c - (int)c;
		int ans1 = pow(10,d) * 100;
		int ans2 = qp(n,k,1000);
		printf("Case %d: %d %03d\n",cas++,ans1,ans2);
	}
	return 0;
}
