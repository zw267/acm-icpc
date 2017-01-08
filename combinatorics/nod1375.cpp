                                            
  //File Name: nod1375.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月10日 星期一 13时28分47秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define LL long long
using namespace std;
const int MOD = 998244353;
const int MAXN = 1000000 + 1;
const int N = 100000 + 1;
int s[MAXN],K;
int mu[MAXN],prime[MAXN];
bool check[MAXN];
LL p2[N],jie[N];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
LL C(LL x,LL y){
	if(y < 0 || y > x) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x-y] % MOD,MOD - 2) % MOD;
}
void mobius(){
	memset(check,false,sizeof check);
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else{
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}
void init(){
	p2[0] = jie[0] = 1;
	for(int i=1;i<N;i++){
		p2[i] = p2[i-1] * 2 % MOD;
		jie[i] = jie[i-1] * i % MOD;
	}
	mobius();
}
LL cal(int sum){
	if(K == -1) return p2[sum] - 1;
	return C(sum,K);
}
LL solve(int n,int ma){
	LL ans = 0;
	for(int k=1;k<=ma;k++){
		int sum = 0;
		for(int i=k;i<=ma;i+=k)
			sum += s[i];
		ans = (ans + mu[k] * cal(sum) + MOD) % MOD;
	}
	return ans;
}
int main(){
	init();
	int n,ma = 0;
	scanf("%d %d",&n,&K);
	for(int i=0,u;i<n;i++){
		scanf("%d",&u);
		ma = max(ma,u);
		s[u]++;
	}
	printf("%lld\n",solve(n,ma));
	return 0;
}
