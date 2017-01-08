                                            
  //File Name: nod1434.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 15时48分46秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 10;

bool check[MAXN];
LL prime[MAXN];
int tot;

void init(){
	memset(check,false,sizeof check);
	tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if(prime[j] * i >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

LL solve(LL n){
	LL ans = n + 1;
	for(int i=0;i<tot;i++){
		if(prime[i] > n) break;
		LL sum = prime[i];
		while(sum * prime[i] <= n){
			sum *= prime[i];
		}
		ans = max(ans,(n / sum + 1) * sum);
	}
	return ans;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}


