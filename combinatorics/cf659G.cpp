                                            
  //File Name: cf659G.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月12日 星期二 12时40分28秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;
const int MOD = (int)1e9 + 7;

LL h[MAXN];
LL f[MAXN][2][2];

LL solve(int n){
	h[n+1] = 1;
	memset(f,0,sizeof f);
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		f[i][0][0] = 1;
		(f[i][1][1] = f[i-1][1][1] + h[i] - 1 + f[i-1][1][0] * min(h[i]-1,h[i-1]-1) % MOD) %= MOD;
		(f[i][1][0] = min(h[i],h[i+1]) - 1 + f[i-1][1][0] * min(min(h[i-1]-1,h[i]-1),h[i+1]-1)) %= MOD;
		//printf("i = %d %lld %lld\n",i,f[i][1][0],f[i][1][1]);
	}
	return f[n][1][1];
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		printf("%d\n",(int)solve(n));
	}
	return 0;
}
