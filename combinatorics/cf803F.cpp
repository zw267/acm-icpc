                                            
  //File Name: cf803F.cpp
  //Created Time: 2017年05月05日 星期五 23时50分08秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN =   100000 + 5;
const int P = (int)1e9 + 7;
int a[MAXN];
int num[MAXN];
LL p2[MAXN];
int prime[MAXN];
bool check[MAXN];
int mu[MAXN];
void init(const int n){
	memset(check,false,sizeof check);
	int tot(0);
	mu[1] = 1;
	for(int i(2);i<=n;++i){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j(0);j < tot && (LL)prime[j] * i <= n;++j){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
	p2[0] = 1;
	for(int i=1;i<=n;++i)
		p2[i] = p2[i - 1] * 2 % P;
}
LL solve(const int n,const int ma){
	init(max(n,ma));
	LL res(0);
	for(int i(1);i<=ma;++i){
		if(!mu[i]) continue;
		int sum = 0;
		for(int j(i);j<=ma;j+=i)
			sum += num[j];
		res = (res + (LL)mu[i] * (p2[sum] - 1) % P) % P;
		if(res < 0) res += P;
	}
	return res;
}
int main(){
	int n,ma(0);
	scanf("%d",&n);
	for(int i(1);i<=n;++i){
		scanf("%d",a + i);
		++num[a[i]];
		ma = max(ma,a[i]);
	}
	printf("%lld\n",solve(n,ma));
	return 0;
}
