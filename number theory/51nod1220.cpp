                                            
  //File Name: nod1220.cpp
  //Created Time: 2017年01月25日 星期三 14时13分16秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = (int)1e7;
const int P = (int)1e9 + 7;
bool check[MAXN];
int prime[1270608];
int s[MAXN];
LL inv_2;
map<LL,int> rem;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	inv_2 = qp(2,P - 2);
	memset(check,false,sizeof(check));
	int tot = 0;
	s[1] = 1;
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			s[i] = -1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i* prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				s[i * prime[j]] = 0;
				break;
			}
			else
				s[i * prime[j]] = -s[i];
		}
	}
//	printf("tot = %d\n",tot);
	for(int i=1;i<MAXN;++i){
		s[i] = 1LL * s[i] * i % P;
		s[i] = (s[i - 1] + s[i]) % P;
	}
}
LL cal_h(LL n){
	LL res = 0;
	for(LL i=1;i<=n;){
		LL x = n / i;
		LL r = n / x;
		LL tmp = (i + r) % P * (r - i + 1) % P * inv_2 % P * x % P;
		res = (res + tmp) % P;
		i = r + 1;
	}
	return res;
}
LL cal_s(LL n){
	if(n < MAXN) return s[n];
	if(rem.count(n)) return rem[n];
	LL res = 0;
	for(LL i=2;i<=n;){
		LL x = n / i;
		LL r = n / x;
		LL tmp = (i + r) * (r - i + 1) % P * inv_2 % P * cal_s(x) % P;
		res += tmp;
		if(res >= P) res -= P;
		i = r + 1;
	}
	res = (1 - res + P) % P;
	rem[n] = res;
	return res;
}
LL solve(LL n){
	LL res = 0;
	for(LL i=1;i<=n;){
		LL x = n / i;
		LL r = n / x;
		LL tmp = cal_h(x);
		tmp = tmp * tmp % P;
		tmp = (cal_s(r) - cal_s(i - 1) + P) % P * tmp % P;
		res = res + tmp;
		if(res >= P) res -= P;
		i = r + 1;
	}
	return res;
}
int main(){
	init();
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",solve(n));
	return 0;
}
