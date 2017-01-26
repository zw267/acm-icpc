                                            
  //File Name: nod1222.cpp
  //Created Time: 2017年01月26日 星期四 16时26分01秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000;
bool check[MAXN];
int prime[MAXN / 10];
int mu[MAXN];
map<LL,LL> rem;
void init(){
	memset(check,false,sizeof(check));
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot&&(LL)i*prime[j]<MAXN;++j){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
}
LL sqrt3(LL n){
	LL r = (LL)sqrt(n + 0.5);
	LL l = (LL)sqrt(r + 0.5);
	LL res = 0;
	for(LL i=l;i<=r;++i){
		if(i * i * i <= n)
			res = i;
		else
			break;
	}
	return res;
}
LL cal(LL n){
	if(rem.count(n)) 
		return rem[n];
	LL res = 0;
	LL ma = sqrt3(n);
	for(LL i=1;i<=ma;++i){
		LL ma2 = sqrt(n / i);
		for(LL j=i;j<=ma2;++j){
			LL r = n / i / j;
			if(r < j) break;
			if(i == j){
				++res;
				res += 3 * (r - j);
			}
			else{
				res += 3;
				res += 6 * (r - j);
			}
		}
	}
	rem[n] = res;
	return res;
}
LL cal_s(LL n){
	LL res = 0;
	LL ma = sqrt(n + 0.5);
	for(LL i=1;i<=ma;++i){
		res += mu[i] * cal(n / i / i);
	}
	return res;
}
LL solve(LL l,LL r){
	LL tmp1 = (cal_s(r) + r) / 2;
	LL tmp2 = (cal_s(l - 1) + l - 1) / 2;
	return tmp1 - tmp2;
}
int main(){
	init();
	LL l,r;
	scanf("%lld %lld",&l,&r);
	printf("%lld\n",solve(l,r));
	return 0;
}
