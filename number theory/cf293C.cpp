                                            
  //File Name: cf293C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月19日 星期一 18时45分43秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 10;
LL dive[MAXN];
LL sqrt3(LL x){
	LL l = 1,r = 100000;
	while(r - l > 1){
		LL m = l + r >> 1;
		if(m * m * m <= x) l = m;
		else r = m;
	}
	return l;
}
int factor(LL x){
	int tot = 0;
	for(LL i=2;i*i<=x;i++){
		if(x % i == 0){
			dive[tot++] = i;
			if(x / i != i)
				dive[tot++] = x / i;
		}
	}
	sort(dive,dive+tot);
	return tot;
}
LL solve(const LL N){
	LL res = 0,n = 0;
	if(N % 24 == 0){
		n = N / 24;
		LL a = sqrt3(n);
		if(a * a * a == n) res += 1;
	}
	if(N % 6 == 0){
		n = N / 6;
		for(LL i=1;i*i*i<=n;++i){
			if(n % i) continue;
			LL u = n / i;
			LL v= sqrt(u + 0.0);
			if(v * v != u || v <= i) continue;
			if(v - i != i) 
				res += 3;
		}
	}
	if(N % 3 == 0){
		n = N / 3;
		LL a,b,c,x,y,z;
		int tot = factor(n);
//		printf("tot = %d\n",tot);
		for(int i=0;i<tot;i++){
			x = dive[i];
			if(x * x * x >= n) break;
			for(int j=i+1;j<tot;j++){
				y = dive[j];
				z = n / x / y;
				if(z <= y) break;
				if((z + y - x) & 1) continue;
				c = (z + y - x) / 2;
				a = y - c;
				b = z - c;
				if(0 < a && a < b && b < c && (a+b+c)*(a+b+c)*(a+b+c)==a*a*a+b*b*b+c*c*c+N) 
					res += 6;
			}
		}
	}
	return res;
}
int main(){
	LL n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
