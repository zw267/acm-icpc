#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL dp[22][10];
int a[22];

void init()
{
	memset(dp,-1,sizeof dp);
}

LL dfs(int pos,int pre,bool limit)
{
	if(!limit && dp[pos][pre] != -1)
		return dp[pos][pre];
	if(pos == 0)
		return 1;

	int ma = limit ? a[pos] : 9;
	LL res = 0;

	for(int i=0;i<=ma;i++){
		if(pre == 4 && i == 9)
			continue;
		res += dfs(pos-1,i,limit && i==ma);
	}
	return limit ? res :dp[pos][pre] = res;
}

LL solve(LL n)
{
	int len = 1;
	while(n){
		a[len++] = n % 10;
		n /= 10;
	}
	return dfs(len-1,0,true);
}

int main()
{
	init();
	int test;
	cin >> test;
	while(test--){
		LL n;
		cin >> n;
		cout << n+1-solve(n) << endl;
	}
	return 0;
}
