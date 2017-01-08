                                            
  //File Name: nod1244.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月18日 星期一 17时56分25秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long
#define hash _HASH_

using namespace std;

const int MAXN = 10000000;
const int N = 1000000;

struct Hash{
	LL key;
	int val,next;
}hash[N];
int head[N],tot;

int mu[MAXN];
bool check[MAXN];
int prime[MAXN];

void init_prime(){
	memset(check,false,sizeof check);
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			mu[i] = -1;
			prime[tot++] = i;
		}
		for(int j=0;j<tot && (LL)prime[j] * i < MAXN;j++){
			check[i * prime[j]] = true;
			if(i % prime[j] != 0)
				mu[i * prime[j]] = -mu[i];
			else{
				mu[i * prime[j]] = 0;
				break;
			}
		}
	}
	//for(int i=1;i<=10;i++)
	//	printf("i = %d mu = %d\n",i,mu[i]);
	for(int i=2;i<MAXN;i++)
		mu[i] += mu[i-1];
}

void addedge(LL key,int val){
	int p = key % N;
	hash[tot].key = key;
	hash[tot].val = val;
	hash[tot].next = head[p];
	head[p] = tot++;
}

int solve(LL n){
	if(n < MAXN)
		return mu[n];
	int p = n % N;
	for(int i=head[p];i;i=hash[i].next){
		if(hash[i].key == n)
			return hash[i].val;
	}
	LL ans = 0;
	for(LL i=2;i<=n;){
		LL x = n / i;
		LL r = n / x;
		ans += (r - i + 1) * solve(x);
		i = r + 1;
	}
	ans = 1 - ans;
	addedge(n,ans);
	return ans;
}

int main(){
	init_prime();
	tot = 0;
	LL l,r;
	while(~scanf("%lld %lld",&l,&r)){
		printf("%d\n",solve(r) - solve(l - 1));
	}
	return 0;
}
