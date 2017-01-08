                                            
  //File Name: hdu4746.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月17日 星期日 15时27分56秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 500000 + 3;

bool check[MAXN];
int prime[MAXN];
int mu[MAXN];
int num[MAXN];
int pre[20][MAXN];

void moebius(){
	memset(check,0,sizeof check);
	memset(num,-1,sizeof num);
	mu[1] = 1;
	num[1] = 0;
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
			num[i] = 1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= MAXN)
				break;
			check[i * prime[j]] = true;
			if(num[i * prime[j]] < 0)
				num[i * prime[j]] = num[i] + 1;
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
	memset(pre,0,sizeof pre);
	for(int i=1;i<MAXN;i++){
		for(int j=i;j<MAXN;j+=i){
			pre[num[i]][j] += mu[j / i];
		}
	}
	for(int j=1;j<MAXN;j++){
		for(int i=1;i<19;i++){
			pre[i][j] += pre[i-1][j];
		}
	}
	for(int i=0;i<19;i++){
		for(int j=1;j<MAXN;j++){
			pre[i][j] += pre[i][j-1];
		}
	}
}

void solve(int n,int m,int p){
	if(p >= 19){
		printf("%lld\n",(LL)n * m);
		return ;
	}
	LL ans = 0;
	int ma = min(n,m),x,y,now;
	for(int i=1;i<=ma;){
		x = n / i;
		y = m / i;
		now = min(n / x,m / y);
		ans += (LL)x * y * (pre[p][now] - pre[p][i - 1]);
		i = now + 1;
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,p;
		scanf("%d %d %d",&n,&m,&p);
		solve(n,m,p);
	}
	return 0;
}
