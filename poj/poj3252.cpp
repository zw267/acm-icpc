#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL dp[40][2][40];
int a[40];

void init()
{
	memset(dp,-1,sizeof dp);
}

LL dfs(int pos,int pre,int need,bool limit)
{
	if(need < 0)
		return 0;
	if(!limit && dp[pos][pre][need] != -1)
		return dp[pos][pre][need];

	if(pos == 0){
		if(need == 0)
			return 1;
		else
			return 0;
	}

	int ma = limit ? a[pos] : 1;
	LL res = 0;
	
	for(int i=0;i<=ma;i++){
		if(i==0)
			res += dfs(pos-1,i,need-1,limit && i==ma);
		else
			res += dfs(pos-1,i,need,limit && i==ma);
	}

	return limit ? res :dp[pos][pre][need] = res;
}

LL solve(LL n)
{
	if(n == 0)
		return 0;

	int len = 1;
	while(n){
		a[len++] = n % 2;
		n /= 2;
	}

	LL res = 0;
	for(int pos=len-1;pos>0;pos--){
		for(int i=(pos+1)/2;i<=pos-1;i++){
			res += dfs(pos-1,1,i,pos==len-1);
		}
	}

	return res;
}

int main()
{
	init();
	LL l,r;
	while(cin >> l >> r){
		cout << solve(r) - solve(l-1) << endl;
	}
	return 0;
}
