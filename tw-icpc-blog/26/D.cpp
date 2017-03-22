                                            
  //File Name: D.cpp
  //Created Time: 2017年03月22日 星期三 13时54分28秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 2010;
LL inv[MAXN];
LL P,sum;
LL qp(LL x,LL y){
	LL res = 1;
	x %= P;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	sum = 0;
	int ma = min((int)P,MAXN);
	for(int i=1;i<ma;++i){
		inv[i] = qp(i,P - 2);
	}
}
LL get(LL x,int f){
	while(x % P == 0){
		sum += f;
		x /= P;
	}
	return x % P;
}
LL debug(LL a,LL b){
	LL res = 1;
	for(int i=0;i<b;++i){
		res = (a - i) * inv[i + 1] % P * res % P;
	}
	return res;
}
LL solve(LL a,LL b,LL n){
	init();
	LL now(1),res(0);
	for(int i=0;i<b;++i){
		LL tmp = get(a - i,1);
		now = tmp * now % P;
		tmp = get(i + 1,-1);
		now = inv[tmp] * now % P;
	}
//	printf("debug = %lld\n",debug(a,b));
	if(sum) res = 0;
	else res = now;
	for(int i=1;i<=n;++i){
		LL tmp = get(a + i,1);
		now = now * tmp % P;
		tmp = get(b + i,-1);
		now = now * inv[tmp] % P;
		if(!sum)
			res = max(res,now);
	}
	return res;
}
int main(){
	LL a,b,n;
	scanf("%lld %lld %lld %lld",&a,&b,&n,&P);
	printf("%lld\n",solve(a,b,n));
	return 0;
}
