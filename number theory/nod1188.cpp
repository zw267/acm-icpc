                                            
  //File Name: nod1188.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月17日 星期日 00时21分35秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 5000000 + 3;

LL g[MAXN];
int phi[MAXN];
bool check[MAXN];
int prime[MAXN];

void mubius(){
	memset(check,false,sizeof check);
	phi[1] = 1;
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j=0;j<tot && i * prime[j] < MAXN;j++){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else{
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
	return ;
}

void init(){
	mubius();
	phi[1] = 0;
	memset(g,0,sizeof g);
	for(int i=1;i<MAXN;i++){
		for(int j=i;j<MAXN;j+=i){
			g[j] += phi[i] * (j / i);
		}
	}
	for(int i=2;i<MAXN;i++){
		g[i] += g[i-1];
	}
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",g[n]);
	}
	return 0;
}
