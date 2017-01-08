                                            
  //File Name: cf466D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月13日 星期六 23时22分07秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 2005;
const int MOD = 1e9+7;

int a[MAXN];
LL dp[MAXN][MAXN];

void solve(int n,int h)
{
	memset(dp,0,sizeof dp);
	dp[0][0] = 1LL;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			//printf("i = %d j = %d %d\n",i,j,dp[i][j]);
			if(dp[i][j] == 0 || j + a[i+1] > h)
				continue;
			if(a[i+1] + j == h){
				dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
				if(j > 0)
					dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j] * j % MOD) % MOD;
			}
			else if(a[i+1] + j == h - 1){
				dp[i+1][j] = (dp[i+1][j] + dp[i][j] * (j + 1) % MOD) % MOD;
				dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
			}
		}
	}

	printf("%d\n",(int)dp[n][0]);
	return ;
}

int main()
{
	int n,h;
	while(~scanf("%d %d",&n,&h)){
		bool flag = false;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] > h)
				flag = true;
		}
		if(flag)
			puts("0");
		else
			solve(n,h);
	}
	return 0;
}
