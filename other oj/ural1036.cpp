#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL dp[51][550];

LL solve(int n,int s)
{
	if(s % 2)
		return 0;
	s /= 2;
	if(9 * n < s)
		return 0;
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;

	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			if(dp[i][j] == 0)
				continue;
			for(int k=0;k<10;k++){
				if(j + k <= s)
					dp[i+1][j+k] += dp[i][j];
			}
		}
	}

	return dp[n][s] * dp[n][s];
}

int main()
{
	int n,s;
	while(~scanf("%d %d",&n,&s)){
		printf("%lld\n",solve(n,s));
		//printf("%I64d\n",solve(n,s));
	}
	return 0;
}
