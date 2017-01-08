                                            
  //File Name: nod1363.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月19日 星期二 09时06分32秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 1000;
const int MOD = (int)1e9 + 7;
const int N = 100000;

int val[MAXN],len[MAXN],tot;
map<int,int> rem;
int prime[N];
bool check[N];
LL ans;

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init_prime(){
	int cnt = 0;
	memset(check,false,sizeof check);
	for(int i=2;i<N;i++){
		if(!check[i]){
			check[i] = true;
			prime[cnt++] = i;
		}
		for(int j=0;j<cnt && prime[j] * i < N;j++){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) 
				break;
		}
	}
}

void fact(int n){
	tot = 0;
	int ma = (int)sqrt(n + 0.5);
	for(int i=0;prime[i]<=ma;i++){
		if(n % prime[i] == 0){
			val[tot] = prime[i];
			len[tot] = 0;
			while(n % prime[i] == 0){
				len[tot]++;
				n /= prime[i];
			}
			tot++;
		}
	}
	if(n != 1){
		val[tot] = n;
		len[tot] = 1;
		tot++;
	}
}

void dfs(int p,int d,LL phi,bool flag){
	if(flag)
		(ans += (phi * d / 2) % MOD) %= MOD;
	if(p >= tot) return ;
	int u = d;
	LL v = phi;
	for(int i=0;i<=len[p];i++){
		dfs(p+1,u,v,!(i == 0));
		//printf("p = %d u  = %d v = %lld\n",p,u,v);
		if(u % val[p] == 0)
			v = v * val[p];
		else
			v = v * (val[p] - 1);
		u = u * val[p];
	}
}

int solve(int n){
	if(rem.count(n))
		return rem[n];
	fact(n);
	//for(int i=0;i<tot;i++)
	//	printf("val = %d len = %d\n",val[i],len[i]);
	ans = 0;
	dfs(0,1,1,false);
	(ans = (ans * n % MOD) + n) %= MOD;
	rem[n] = ans;
	return ans;
}

int main(){
	init_prime();
	rem.clear();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}
