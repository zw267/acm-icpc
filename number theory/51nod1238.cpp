                                            
  //File Name: nod1238.cpp
  //Created Time: 2017年01月23日 星期一 22时37分33秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = (int)1e7;
const int P = (int)1e9 + 7;
bool check[MAXN];
int prime[MAXN / 10];
int s[MAXN];
map<LL,int> rem;
int inv2,inv6;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	inv2 = qp(2,P - 2);
	inv6 = qp(6,P - 2);
	memset(check,false,sizeof(check));
	int tot = 0;
	s[1] = 1;
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			s[i] = i - 1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				s[i * prime[j]] = s[i] * prime[j];
				break;
			}
			else
				s[i * prime[j]] = s[i] * (prime[j] - 1);
		}
	}
	for(int i=1;i<MAXN;++i){
		s[i] = 1LL * i * i % P * s[i] % P;
		s[i] = (0LL + s[i - 1] + s[i]) % P;
	}
}
LL cal_p2(LL x){
	return (x % P) * ((x + 1) % P) % P * inv2 % P;
}
LL cal_p3(LL x){
	return (x % P) * ((x + 1) % P) % P * ((x + x + 1) % P) % P * inv6 % P;
}
LL cal_s(LL n){
	if(n < MAXN) return s[n];
	if(rem.count(n)) return rem[n];
	LL res = 0;
	for(LL i=2;i<=n;){
		LL x = n / i;
		LL r = n / x;
		LL tmp = (cal_p3(r) - cal_p3(i - 1) + P) % P;
		tmp = tmp * cal_s(x) % P;
		res = (res + tmp) % P;
		i = r + 1;
	}
	LL tmp = cal_p2(n);
	tmp = tmp * tmp % P;
	res = (tmp - res + P) % P;
	rem[n] = res;
	return res;
}
LL solve(LL n){
	LL res = 0;
	for(LL i=1;i<=n;){
		LL x = n / i;
		LL r = n / x;
		LL tmp = cal_p2(x) * ((cal_s(r) - cal_s(i - 1) + P) % P) % P;
		res = (res + tmp) % P;
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
