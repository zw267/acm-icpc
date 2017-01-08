                                            
  //File Name: poj2154.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月30日 星期日 17时58分34秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define LL long long 
using namespace std;
vector<int> dive,fact;
int n,mod;
LL qp(LL x,LL y){
	LL res = 1;
	x %= mod;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
void cal_dive(){
	dive.clear();
	for(int i=1;i*i<=n;i++){
		if(n % i == 0){
			dive.push_back(i);
			if(n / i != i) dive.push_back(n / i);
		}
	}
}
void cal_fact(){
	fact.clear();
	int N = n;
	for(int i=2;i*i<=N;i++){
		if(N % i == 0){
			fact.push_back(i);
			while(N % i == 0)
				N /= i;
		}
	}
	if(N != 1) fact.push_back(N);
}
LL solve(){
	cal_dive();
	cal_fact();
	LL ans = 0;
	for(int i=0;i<dive.size();i++){
		int d = dive[i];
		int u = n / d;
		LL tmp = u;
		for(int j=0,v;j<fact.size();j++){
			v = fact[j];
			if(u % v == 0){
				tmp = tmp / v * (v - 1);
			}
		}
		ans = (ans + qp(n,d-1) * tmp % mod) % mod;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&mod);
		printf("%lld\n",solve());
	}
	return 0;
}
