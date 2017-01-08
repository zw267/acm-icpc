                                            
  //File Name: nod1189.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月15日 星期五 19时26分31秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = (int)1e9 + 7;
const int MAXN = 1000000 + 2;

bool check[MAXN];
int prime[MAXN],tot;
int num[MAXN];

void init(){
	memset(check,false,sizeof check);
	tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int get(int n,int p){
	int res = 0;
	while(n >= p){
		res += n / p;
		n /= p;
	}
	return res;
}

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL solve(int n){
	LL ans = 1;
	memset(num,0,sizeof num);
	for(int i=0;i < tot && prime[i] <= n;i++){
		num[i] = get(n,prime[i]);
		num[i] *= 2;
		ans = ans * (num[i] + 1) % MOD;
		//cout << ans << endl;
	}
	ans = (ans + 1) * qp(2,MOD - 2) % MOD;
	return ans;
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%lld\n",solve(n));
	}
	return 0;
}
