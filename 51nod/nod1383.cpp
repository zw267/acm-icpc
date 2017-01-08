                                            
  //File Name: nod1383.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月14日 星期四 20时35分17秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 2;
const int MOD = (int)1e9 + 7;

LL f[MAXN];

void init(){
	f[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(i & 1)
			f[i] = f[i-1];
		else
			f[i] = (f[i-1] + f[i/2]) % MOD;
	}
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%lld\n",f[n]);
	}
	return 0;
}
