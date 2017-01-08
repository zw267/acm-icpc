                                            
  //File Name: cf711E.cpp
  //Created Time: 2017年01月06日 星期五 00时05分30秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int P = (int)1e6 + 3;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
LL cal_phi(LL n){
	LL res = n;
	for(int i=2;i*i<=n;++i){
		if(n % i == 0){
			res -= res / i;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1) res -= res / n;
	return res;
}
void solve(LL n,LL k,LL &a,LL &b){
	LL now = 1;
	for(LL j=1;j<=n;++j){
		now *= 2;
		if(now >= k) break;
	}
	if(now < k) a = 1,b = 1;
	else{
//		puts("fffff");
		LL d = 0;
		now = k - 1;
		while(now >= 2){
			d += now / 2;
			now /= 2;
		}
		LL phi = P - 1;
		b = qp(2,((n % phi) * (k % phi) - n % phi - d % phi + 2 * phi) % phi);
		if(k >= P) a = b;
		else{
			now = qp(2,n % phi);
			a = 1;
			for(LL i=1;i<k;++i)
				a = (now - i + P) % P * a % P;
			now = qp(2,d % phi);
			a = a * qp(now,P - 2) % P;
			a = (b - a + P) % P;
		}
	}
}
int main(){
	LL n,k;
	cin >> n >> k;
	LL a,b;
	solve(n,k,a,b);
	printf("%lld %lld\n",a,b);
	return 0;
}
