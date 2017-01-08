#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1000000+10;

int dp[10][10];
int a[10];

int dfs(int pos,int pre,bool limit)
{
	if(!limit && dp[pos][pre] != -1)
		return dp[pos][pre];
	if(pos == 0)
		return 1;

	int ma = limit?a[pos]:9;
	int res = 0;

	for(int i=0;i<=ma;i++){
		if(i == 4)
			continue;
		if(pre == 6 && i == 2)
			continue;
		res += dfs(pos-1,i,limit && i==ma);
	}
	return limit ? res : dp[pos][pre] = res;
}

int solve(int n)
{
	int len = 1;
	while(n){
		a[len++] = n % 10;
		n /= 10;
	}	
	return dfs(len-1,0,true);
}

void init()
{
	memset(dp,-1,sizeof dp);
}

int main()
{
	init();
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(!n && !m)
			break;
		printf("%d\n",solve(m)-solve(n-1));
	}
	return 0;
}
