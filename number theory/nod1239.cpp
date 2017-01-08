                                            
  //File Name: nod1239.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月18日 星期一 18时44分41秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long
#define hash _HASH_

using namespace std;

const int MAXN = 10000000;
const int MOD = (int)1e9 + 7;
const int N = 100000;

int prime[MAXN];
bool check[MAXN];
LL phi[MAXN];

void init_prime(){
	memset(check,false,sizeof check);
	int tot = 0;
	phi[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j=0;j<tot && (LL)prime[j] * i < MAXN;j++){
			check[i * prime[j]] = true;
			if(i % prime[j] != 0)
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			else{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	for(int i=2;i<MAXN;i++)
		(phi[i] += phi[i-1]) %= MOD;
}

struct Hash{
	LL key,val;
	int next;
}hash[N];
int tot,head[N];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void addedge(LL key,LL val){
	int p = key % N;
	hash[tot].key = key;
	hash[tot].val = val;
	hash[tot].next = head[p];
	head[p] = tot++;
}

LL solve(LL n){
	if(n < MAXN)
		return phi[n];
	for(int i=head[n % N];i;i=hash[i].next){
		if(hash[i].key == n)
			return hash[i].val;
	}
	LL ans = 0;
	for(LL i=2;i<=n;){
		LL x = n / i;
		LL r = n / x;
		(ans += (r - i + 1) * solve(x) % MOD) %= MOD;
		i = r + 1;
	}
	ans = ((1 + n) % MOD * (n % MOD) % MOD * qp(2,MOD-2) % MOD - ans) % MOD;
	(ans += MOD) %= MOD;
	addedge(n,ans);
	return ans;
}

int main(){
	init_prime();
	LL n;
	while(~scanf("%lld",&n)){
		printf("%lld\n",solve(n));
	}
	return 0;
}
