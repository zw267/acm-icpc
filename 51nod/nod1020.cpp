                                            
  //File Name: nod1020.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月14日 星期二 01时13分09秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = (int)1e9 + 7;

int f[1001][20001];

void init(){
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=1;i<=1000;i++){
		f[i][0] = 1;
		int pre = 0;
		LL sum = 1;
		for(int j=1;j<=20000;j++){
			sum = (sum + f[i-1][j]) % MOD;
			if(j - i + 1 > pre){
				sum = (sum - f[i-1][pre]) % MOD;
				sum = (sum + MOD) % MOD;
				pre++;
			}
			f[i][j] = sum;
		}
	}
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("%d\n",f[n][k]);
	}
	return 0;
}
