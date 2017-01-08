                                            
  //File Name: uva11481.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 00时45分35秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long 

using namespace std;

const int MAXN = 1000 + 3;
const int MOD = 1e9 + 7;

LL dp[MAXN][MAXN];
LL jc[MAXN];

void init()
{
	jc[0] = 1;
	jc[1] = 1;
	for(int i=2;i<MAXN;i++){
		jc[i] = jc[i-1] * i % MOD;
	}

	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i=1;i<MAXN;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
		}
	}
}

LL solve(int n,int m,int k)
{
	LL res = 0;

	for(int i=0;i<=m-k;i++){
		LL tmp = dp[m-k][i] * jc[n-k-i] % MOD;
		if(i % 2)
			res = (res - tmp + MOD) % MOD;
		else
			res = (res + tmp + MOD ) % MOD;
	}
	
	res = res * dp[m][k] % MOD;

	return res;
}

int main()
{
	init();
	int cas = 1;
	int test;
	scanf("%d",&test);
	while(test--){
		printf("Case %d: ",cas++);
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		printf("%lld\n",solve(n,m,k));
	}

	return 0;
}
