                                            
  //File Name: nod1769.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月23日 星期五 14时52分11秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 500000 + 5;
const int P = (int)1e9 + 7;
int f[MAXN],g[MAXN],h[MAXN],prime[MAXN],inv[MAXN];
bool check[MAXN];
LL K;
char str[MAXN << 1];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void inverse(int n){
	inv[0] = inv[1] = 1;
	for(int i=2;i<=n;++i)
		inv[i] = (LL)inv[P % i] * (P - P / i) % P;
}
void init(int n){
	int tot = 0;
	h[1] = 1;
	memset(check,false,sizeof(check));
	for(int i=2;i<=n;++i){
		if(!check[i]){
			prime[tot++] = i;
			h[i] = K;
		}
		for(int j=0;j<tot;++j){
			if(1LL * i * prime[j] > n) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				int e = 0,now = i;
				while(now % prime[j] == 0){
					++e;
					now /= prime[j];
				}
				h[i * prime[j]] = 1LL * h[i] * (K + e) % P * inv[e+1] % P;
				break;
			}
			h[i * prime[j]] = 1LL * h[i] * h[prime[j]] % P;
		}
	}
}
void solve(int n){
	K = 0;
	int len = strlen(str);
	for(int i=0;i<len;++i)
		K = (K * 10 + str[i] - '0') % P;
//	printf("K = %lld\n",K);
	inverse(n);
	init(n);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			g[j] = (g[j] + 1LL * f[i] * h[j / i] % P) % P;
		}
	}
}
int main(){
	int n;
	scanf("%d %s",&n,str);
	for(int i=1;i<=n;++i)
		scanf("%d",f + i);
	solve(n);
	for(int i=1;i<=n;++i)
		printf("%d%c",g[i],i == n ? '\n' : ' ');
	return 0;
}
