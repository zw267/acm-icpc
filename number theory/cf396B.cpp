                                            
  //File Name: cf396B.cpp
  //Created Time: 2017年02月21日 星期二 12时46分23秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
bool miller_rabin(LL n,LL b){
	LL m = n - 1,cnt = 0;
	while(m % 2 == 0) m >>= 1,++cnt;
	LL ret = qp(b,m,n);
	if(ret == 1 || ret == n - 1) return true;
	--cnt;
	while(cnt >= 0){
		ret = ret * ret % n;
		if(ret == n - 1) return true;
		--cnt;
	}
	return false;
}
bool prime_test(LL n){
	if(n < 2) return false;
	if(n < 4) return true;
	if(n == 3215031751LL) return false;
	const int basic[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
	for(int i=0;i<12 && basic[i] < n;++i){
		if(!miller_rabin(n,basic[i]))
			return false;
	}
	return true;
}
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y, x % y);
}
pair<LL,LL> solve(LL n){
	LL u,v;
	for(int i=n+1;;++i){
		if(prime_test(i)){
			u = i;
			break;
		}
	}
	for(int i=n;;--i){
		if(prime_test(i)){
			v = i;
			break;
		}
	}
//	printf("u = %lld v = %lld\n",u,v);
	pair<LL,LL> ans(0,0);
	ans.first = u * v - 2 * v - 2 * (u - 1 - n);
	ans.second = u * v * 2;
	LL d = gcd(ans.first,ans.second);
	ans.first /= d;
	ans.second /= d;
	return ans;
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		pair<LL,LL> ans = solve(n);
		printf("%lld/%lld\n",ans.first,ans.second);	
	}
	return 0;
}
