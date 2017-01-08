#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long 

using namespace std;

const int MOD = 1000000;

LL dp[201][201];

void init()
{
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i=1;i<201;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
	}
}

int main()
{
	init();
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		if(!n && !k)
			break;
		printf("%lld\n",dp[n+k-1][n]);
	}
	return 0;
}
