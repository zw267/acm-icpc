                                            
  //File Name: poj2478.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 21时50分30秒
                                   
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 5;
int prime[MAXN];
LL phi[MAXN];
bool check[MAXN];
void init(){
	memset(check,false,sizeof(check));
	int tot = 0;
	phi[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	phi[1] = 0;
	for(int i=1;i<MAXN;i++)
		phi[i] += phi[i - 1];
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		if(!n) break;
		printf("%lld\n",phi[n]);
	}
	return 0;
}
