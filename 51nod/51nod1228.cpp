                                            
  //File Name: 51nod1228.cpp
  //Created Time: 2017年04月14日 星期五 23时26分59秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2005;
const int P = (int)1e9 + 7;
LL inv[MAXN],pn[MAXN],c[MAXN][MAXN];
LL B[MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	inv[0] = inv[1] = 1;
	for(int i=2;i<MAXN;++i)
		inv[i] = qp(i,P - 2);
   	for(int i=0;i<MAXN;++i){
		for(int j=0;j<=i;++j){
			c[i][j] = (j == 0) ? 1 : (c[i-1][j-1] + c[i-1][j]) % P;
		}
	}
	B[0] = 1;
	for(int i=1;i<MAXN;++i){
		LL tmp = 0;
		for(int j=0;j<i;++j){
			tmp = (tmp + c[i + 1][j] * B[j] % P) % P;
		}
		tmp = tmp * inv[i + 1] % P;
		B[i] = P - tmp;
	}	
}
LL solve(LL n,int m){
	pn[0] = 1;
	LL nn = n % P;
	for(int i=1;i<=m+1;++i)
		pn[i] = pn[i - 1] * nn % P;
	LL res = 0;
	for(int k=0;k<=m;++k){
		res += c[m+1][k] * B[k] % P * pn[m + 1 - k] % P;
		res %= P;
	}
	res = res * inv[m + 1] % P;
	return res;
}
int main(){
	init();
	LL n;
	int m,t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %d",&n,&m);
		++n;
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
