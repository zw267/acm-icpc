                                            
  //File Name: nod1190.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月08日 星期二 14时55分34秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 100000;
vector<int> dive;
bool check[MAXN];
int prime[MAXN],tot;
int fact[40],num[40],len;
LL inv_2;
void init(){
	memset(check,false,sizeof(check));
	tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i])
			prime[tot++] = i;
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
void cal_fact(int n){
	len = 0;
	for(int i=0;i<tot;i++){
		if((LL)prime[i] * prime[i] > n) break;
		if(n % prime[i] == 0){
			num[len] = 0;
			fact[len] = prime[i];
			while(n % prime[i] == 0){
				num[len]++;
				n /= prime[i];
			}
			len++;
		}
	}
	if(n > 1){
		fact[len] = n,num[len] = 1;
		len++;
	}
}
void cal_dive(int now,int p){
	if(p >= len){
		dive.push_back(now);
		return ;
	}
	int tmp = 1;
	for(int i=0;i<=num[p];i++){
		cal_dive(now * tmp,p + 1);
		tmp *= fact[p];
	}
}
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
LL solve(int a,int b){
	cal_fact(b);
	dive.clear();
	cal_dive(1,0);
	LL res = 0;
	for(int i=0;i<dive.size();i++){
		int k = dive[i];
		int l = (a + k - 1) / k,r = b / k;
		if(l > r) continue;
		LL tmp = (0LL + l + r) % MOD * (r - l + 1) % MOD * inv_2 % MOD;
		LL f = 1;
		for(int j=0;j<len;j++){
			int d = fact[j];
			if(k % d) continue;
			f = (1 - d + MOD) % MOD * f % MOD;
		}
		(res += tmp * f % MOD) %= MOD;
	}
	res = res * b % MOD;
	return res;
}
int main(){
	init();
	inv_2 = qp(2,MOD - 2);
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%lld\n",solve(a,b));
	}
	return 0;
}
