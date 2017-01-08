#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 10000+10;

int a[MAXN];
int dp[MAXN][15];

void init_dp(int n)
{
	for(int i=1;i<=n;i++)
		dp[i][0] = a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int l,int r)
{
	int k=0;
	while(1<<(k+1)<=r-l+1)
		k++;
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

void solve(int n)
{
	init_dp(n);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",query(l+1,r+1));
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n);
	}
	return 0;
}	

