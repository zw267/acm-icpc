#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30000+5;

int dp[MAXN][600];
int a[MAXN];

void solve(int n,int d,int ma)
{
	int base = 300;
	int res = 0;
	memset(dp,0,sizeof dp);
	dp[d][base] = a[0] + a[d];
	for(int i=d;i<=ma;i++){
		for(int j=0;j<600;j++){
			res = max(res,dp[i][j]);
			int len = j + d - base;
			if(len > 1 && i + len - 1 <= ma && j-1 >= 0)
				dp[i+len-1][j-1] = max(dp[i+len-1][j-1],dp[i][j]+a[i+len-1]);
			if(len >= 1 && i+len <= ma)
				dp[i+len][j] = max(dp[i+len][j],dp[i][j]+a[i+len]);
			if(len >= 1 && i+len+1 <= ma)
				dp[i+len+1][j+1] = max(dp[i+len+1][j+1],dp[i][j]+a[i+len+1]);
		}
	}
	printf("%d\n",res);
	return ;

}

int main()
{
	memset(a,0,sizeof a);
	int n,d;
	scanf("%d %d",&n,&d);
	int ma = 0;
	for(int i=1;i<=n;i++){
		int cur;
		scanf("%d",&cur);
		if(cur > ma)
			ma = cur;
		a[cur]++;
	}

	solve(n,d,ma);
	return 0;
}
