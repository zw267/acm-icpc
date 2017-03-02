                                            
  //File Name: cf768F.cpp
  //Created Time: 2017年03月01日 星期三 19时03分44秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 100;
const int P = (int)1e9 + 7;
LL jie[MAXN << 1];
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
LL C(LL x,LL y){
	if(x < 0 || y < 0 || y > x) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % P,P - 2,P) % P;
}
LL solve(int a,int b,int h){
	if(b == 0) return 1;
	if(a == 0) return b > h;
	jie[0] = 1;
	for(int i=1;i<(MAXN << 1);++i)
		jie[i] = jie[i - 1] * i % P;
	LL res1 = 0,res2 = 0;
	for(int i=1;i<=a;++i){
		LL tmp1 = 0,tmp2 = 0;
		for(int j=i-1;j<=i+1;++j){
			int f = 0;
			if(j == i) f = 2;
			else f = 1;
			tmp1 = (tmp1 + f * C(b-1,b-j)) % P;
			LL b1 = b - 1LL * h * j;
			tmp2 = (tmp2 + f * C(b1-1,b1-j)) % P;
		}
		LL tmp3 = C(a-1,a-i);
		res1 = (res1 + tmp1 * tmp3 % P) % P;
		res2 = (res2 + tmp2 * tmp3 % P) % P;
//		printf("i = %d\n",i);
	}
//	printf("res1 = %lld res2 = %lld\n",res1,res2);
	LL res = res2 * qp(res1,P-2,P) % P;
	return res;
}
int main(){
	int a,b,h;
	scanf("%d %d %d",&a,&b,&h);
	printf("%d\n",(int)solve(a,b,h));
	return 0;
}
