                                            
  //File Name: nod1237.cpp
  //Created Time: 2017年01月04日 星期三 00时47分02秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = (int)2e7 + 1;
const int P = (int)1e9 + 7;
bool check[MAXN];
int prime[MAXN / 10];
LL g[MAXN],inv_2;
map<LL,LL> rem;
void init(int n){
	int tot = 0;
	g[1] = 1;
	memset(check,false,sizeof(check));
	for(int i=2;i<=n;++i){
		if(!check[i]){
			prime[tot++] = i;
			g[i] = i - 1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] > n) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				g[i * prime[j]] = g[i] * prime[j] % P;
				break;
			}
			else{
				g[i * prime[j]] = g[i] * (prime[j] - 1) % P;
			}
		}
	}
	for(int i=1;i<=n;++i)
		g[i] = (g[i] + g[i - 1]) % P;
}
LL cal_g(LL n){
	if(n < MAXN) return g[n];
	if(rem.count(n)) return rem[n];
	LL res = (n % P) * ((n + 1) % P) % P * inv_2 % P;
	for(LL i=2,x,r;i<=n;){
		x = n / i;
		r = n / x;
		res = (res - (r - i + 1) % P * cal_g(x) % P + P) % P;
		i = r + 1;
	}
	rem[n] = res;
	return res;
}
LL solve(LL n){
	init(min(n,MAXN - 1LL));
	LL res = 0;
	for(LL i=1,x,r;i<=n;){
		x = n / i;
		r = n / x;
		res = (res + (x % P) * (x % P) % P * (cal_g(r) - cal_g(i - 1) + P) % P) % P;
		i = r + 1;
	}
	return res;
}
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
int main(){
	inv_2 = qp(2,P - 2);
	LL n;
	scanf("%lld",&n);
	printf("%lld\n",solve(n));
	return 0;
}
