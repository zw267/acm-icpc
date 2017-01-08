                                            
  //File Name: nod1201.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月14日 星期四 21时43分10秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 50000 + 2;
const int MOD = (int)1e9 + 7;
const int N = 316;

LL f[MAXN][N];

void init(){
	memset(f,0,sizeof f);
	for(int i=1;i<MAXN;i++){
		f[i][1] = 1;
		for(int j=2;j<N;j++){
			if(i >= j)
				(f[i][j] = f[i-j][j] + f[i-j][j-1]) %= MOD;
		}
	}
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		LL ans = 0;
		for(int i=1;i<N;i++)
			ans = (ans + f[n][i]) % MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
