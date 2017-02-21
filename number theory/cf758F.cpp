                                            
  //File Name: cf758F.cpp
  //Created Time: 2017年02月21日 星期二 18时03分00秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x % y);
}
LL solve(int n,int l,int r){
	if(n == 1) return r - l + 1;
	if(n == 2) return (r - l + 1LL) * (r - l);
	if(n >= 25) return 0;
	LL res = 0;
	for(LL v=1;;++v){
		LL vn = 1;
		for(int i=1;i<n;++i)
			vn = min(1LL << 30,vn * v);
		if(vn > r) break;
		LL d = (l + vn - 1) / vn;
		for(LL a1=vn*d;;a1+=vn,++d){
			if(a1 > r) break;
			for(LL u=v+1;;++u){
				if(gcd(u,v) > 1) continue;
				LL un = 1;
				for(int i=1;i<n;++i)
					un = min(1LL << 30,un * u);
				if(un * d > r) break;
				++res;
			}
		}
	}
	res <<= 1;
	return res;
}
int main(){
	int n,l,r;
	cin >> n >> l >> r;
	cout << solve(n,l,r) << endl;
	return 0;
}
