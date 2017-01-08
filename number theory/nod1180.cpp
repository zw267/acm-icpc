                                            
  //File Name: nod1180.cpp
  //Created Time: 2017年01月02日 星期一 18时23分52秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 5000000 + 2;
int prime[MAXN / 10],mu[MAXN];
bool check[MAXN];
void init(int N){
	memset(check,false,sizeof(check));
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<=N;++i){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] > N) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=N;++i)
		mu[i] += mu[i - 1];
}
LL solve(int n,int m){
	if(n == 1 && m == 1) return 0;
	if(n == 1 || m == 1) return 1;
	--n,--m;
	if(n > m) swap(n,m);
	init(n);
	LL res = 2;
	for(int i=1,x,y,r;i<=n;){
		x = n / i;
		y = m / i;
		r = min(n / x,m / y);
		res += 1LL * (mu[r] - mu[i-1]) * x * y;
		i = r + 1;
	}
	return res;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%lld\n",solve(n,m));
	return 0;
}
