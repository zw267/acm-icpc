                                            
  //File Name: cf757E.cpp
  //Created Time: 2017年01月16日 星期一 17时10分47秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 2;
const int P = (int)1e9 + 7;
LL jie[MAXN << 1];
bool check[MAXN];
int prime[MAXN];
int fir[MAXN];
int num[50];
int c[MAXN + 30][30];
void init(){
	int tot = 0;
	fir[1] = 1;
	memset(check,false,sizeof(check));
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			fir[i] = i;
		}
		for(int j=0;j<tot;++j){
			if(1LL * i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			fir[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
//	jie[0] = 1;
//	for(int i=1;i<(MAXN << 1);++i)
//		jie[i] = jie[i - 1] * i % P;
	c[0][0] = 1;
	for(int i=1;i<MAXN+30;++i){
		c[i][0] = 1;
		for(int j=1;j<30;++j)
			c[i][j] = (0LL + c[i-1][j] + c[i-1][j-1]) % P;
	}
}
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
LL C(int x,int y){
	if(y == 0 || y == x) return 1;
	if(y < 0 || y > x) return 0;
//	return jie[x] * qp(jie[y] * jie[x - y] % P,P - 2) % P;
	return c[x][y];
}
int fact(int n){
	int tot = 0;
//	printf("n = %d\n",n);
	while(n > 1){
		int pre = fir[n];
		num[tot] = 0;
		while(fir[n] == pre){
			++num[tot];
			n /= pre;
		}
//		printf("p = %d num = %d\n",pre,num[tot]);
		++tot;
	}
	return tot;
}
LL solve(int r,int n){
	if(n == 1) return 1;
	int tot = fact(n);
	LL res = 1;
	for(int i=0;i<tot;++i){
		LL tmp = (C(num[i]+r-1,num[i]) + 2 * C(num[i]+r-1,num[i]-1)) % P;
//		printf("tmp = %lld\n",tmp);
		res = res * tmp % P;
	}
	return res;
}
int main(){
	init();
	int q,r,n;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&r,&n);
		printf("%lld\n",solve(r,n));
	}
	return 0;
}
