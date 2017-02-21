                                            
  //File Name: cf226C.cpp
  //Created Time: 2017年02月21日 星期二 15时05分00秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL P;
struct matrix_t{
	LL x[3][3];
	matrix_t(LL v = 0){
		x[1][2] = x[2][1] = 0;
		x[1][1] = x[2][2] = v;
	}
	matrix_t operator * (const matrix_t &a)const{
		matrix_t res(0);
		for(int i=1;i<=2;++i){
			for(int j=1;j<=2;++j){
				for(int k=1;k<=2;++k){
					res.x[i][j] += x[i][k] * a.x[k][j] % P;
					res.x[i][j] %= P;
				}
			}
		}
		return res;
	}
	matrix_t power(LL y) const{
		matrix_t res(1),a = *this;
		for(;y>0;y>>=1){
			if(y & 1) res = res * a;
			a = a * a;
		}
		return res;
	}
}basic;
LL solve(LL l,LL r,LL num){
	LL ans = 0;
	basic.x[1][1] = basic.x[1][2] = basic.x[2][1] = 1;
	basic.x[2][2] = 0;
	for(LL i=1;i<=r;){
		LL x = r / i,y = (l - 1) / i;
		LL r1 = min(r / x,y == 0 ? r / x : (l - 1) / y);
		if(x - y >= num)
			ans = max(ans,r1);
		i = r1 + 1;
	}
//	printf("ans = %lld\n",ans);
	if(ans <= 2) return 1 % P;
	matrix_t now = basic.power(ans - 2);
	return (now.x[1][1] + now.x[1][2]) % P;
}
int main(){
	LL l,r,num;
	cin >> P >> l >> r >> num;
	cout << solve(l,r,num) << endl;
	return 0;
}
