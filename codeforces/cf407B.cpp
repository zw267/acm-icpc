                                            
  //File Name: cf407B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月27日 星期日 00时58分52秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9+7;

LL dp[MAXN];
int p[MAXN];

void solve(int n)
{
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		LL tmp = 0;
		for(int j=p[i];j<i;j++)
			tmp = (tmp + dp[j]) % MOD;
		dp[i] = (2 + tmp) % MOD;
	}

	LL res = 0;
	for(int i=1;i<=n;i++)
		res = (res + dp[i]) % MOD;
	printf("%lld\n",res);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	solve(n);
	return 0;
}
