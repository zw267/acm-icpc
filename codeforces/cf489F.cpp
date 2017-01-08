//好题
//dp[i][j][k]表示到了第i行，目前有j列有0个1，有k列有1个1
//i可以用滚动数组，不然数组开不下


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 505;

int num[MAXN];
char str[MAXN];

LL dp[2][MAXN][MAXN];

inline LL comb(LL x)
{
	return x * (x - 1) / 2;
}

void solve(int n,int m,LL mod)
{
	memset(dp,0,sizeof dp);

	int num_0 = 0,num_1 = 0;
	for(int i=1;i<=n;i++){
		if(num[i] == 1)
			num_1++;
		else if(num[i] == 0)
			num_0++;
	}
	//printf("%d %d\n",num_0,num_1);
	dp[0][num_0][num_1] = 1;

	n -= m;
	num_1 += num_0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=num_0;j++){
			for(int k=0;k<=num_1;k++){
				int pre = (i + 1) % 2;
				if(dp[pre][j][k] == 0)
					continue;
				if(j >= 2)
					dp[i%2][j-2][k+2] = (dp[i%2][j-2][k+2] + comb(j) * dp[pre][j][k] % mod) % mod;
				if(k >= 2)
					dp[i%2][j][k-2] = (dp[i%2][j][k-2] + comb(k) * dp[pre][j][k] % mod) % mod;
				if(j >= 1)
					dp[i%2][j-1][k] = (dp[i%2][j-1][k] + j * k * dp[pre][j][k] % mod) % mod;
			}
		}
	}

	printf("%lld\n",dp[n%2][0][0]);
	//printf("%I64d\n",dp[n%2][0][0]);

	return ;
}

int main()
{
	memset(num,0,sizeof num);
	int n,m,mod;
	scanf("%d %d %d",&n,&m,&mod);
	for(int i=1;i<=m;i++){
		scanf("%s",str);
		for(int j=1;j<=n;j++){
			if(str[j-1] == '1')
				num[j]++;
		}
	}

	solve(n,m,mod);

	return 0;
}
