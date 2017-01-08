                                            
  //File Name: bzoj2301.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月18日 星期一 12时50分28秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 50000 + 10;

bool check[MAXN];
int prime[MAXN];
int mu[MAXN];

void moebius(){
	memset(check,false,sizeof check);
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN)
				break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
	return ;
}

void init(){
	moebius();
	for(int i=2;i<MAXN;i++){
		mu[i] += mu[i - 1];
	}
	return ;
}

LL get(int n,int m){
	LL ans = 0;
	int ma = min(n,m),now,x,y;
	for(int i=1;i<=ma;){
		x = n / i;
		y = m / i;
		now = min(n / x,m / y);
		ans += (LL)x * y * (mu[now] - mu[i - 1] + 0LL);
		i = now + 1;
	}
	return ans;
}

void solve(int a,int b,int c,int d,int k){
	if(b < k || d < k){
		puts("0");
		return ;
	}
	printf("%lld\n",get(b / k,d / k) - get((c - 1) / k,b / k) 
			- get((a - 1) / k,d / k) 
			+ get((a - 1) / k,(c - 1) / k));
	return ;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int a,b,c,d,k;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		solve(a,b,c,d,k);
	}
	return 0;
}
