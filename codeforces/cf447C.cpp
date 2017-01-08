#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000+10;

int dp[MAXN][2];
int a[MAXN];

int solve(int n)
{
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		dp[i][0] = 1;
		if(a[i] > a[i-1]){
			dp[i][0] = dp[i-1][0] + 1;
		}
	}	

	for(int i=2;i<=n;i++){
		dp[i][1] = 0;
		if(i==2 && a[i] > a[i-1])
			dp[i][1] = dp[i-1][1] + 1;
		else{
			if(i-2>0 && a[i-1] > a[i-2])
				dp[i][1] = dp[i-1][0] + 1;
		}
		if(i-2 > 0 && a[i] - a[i-2] > 0){
			dp[i][1] = max(dp[i][1],dp[i-2][0] + 2);
		}
	}

	int res = -1;
	for(int i=1;i<=n;i++){
		res = max(res ,max(dp[i][0],dp[i][1]));
	}

	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	printf("%d\n",solve(n));
	
	return 0;
}
