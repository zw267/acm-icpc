                                            
  //File Name: nod1379.cpp
  //Created Time: 2017年01月21日 星期六 23时11分15秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 90;
const int P = (int)1e9 + 7;
LL f[MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	f[0] = 0,f[1] = 1;
	for(int i=2;i<MAXN;++i)
		f[i] = f[i - 1] + f[i - 2];
}
LL solve(LL n){
	if(n < MAXN){
		LL res = 1;
		while(res <= f[n])
			res *= 2;
		return (res - 1 + P) % P;
	}
	else{
		double s5 = sqrt(5 + 0.0);
//		cout << log2(s5 + 1.0) - 1.0 << endl;
		double u = n * (log2(s5 + 1.0) - 1.0) - log2(s5 + 0.0);
		LL v = (LL)u;
		if(u - v > 0)
			++v;
		LL res = qp(2,v) - 1 + P;
		return res % P;
	}
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}
