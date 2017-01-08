#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long 

using namespace std;

LL dp[20][20][10][1500];
int a[20];

void init()
{
	memset(dp,-1,sizeof dp);
}

LL dfs(int mid,int pos,int pre,int w,bool limit)
{
	if(w < 0)
		return 0;
	if(!limit && dp[mid][pos][pre][w] != -1)
		return dp[mid][pos][pre][w];

	if(pos == 0){
		if(w == 0)
			return 1;
		else
			return 0;
	}

	LL res = 0;
	int ma = limit? a[pos] : 9;

	for(int i=0;i<=ma;i++){
		res = res + dfs(mid,pos-1,i,w + (pos-mid) * i ,limit && i==ma);
	}
	
	return limit? res : dp[mid][pos][pre][w] = res;
}

LL solve(LL n)
{
	if(n < 0)
		return 0;
	int len = 1;
	while(n){
		a[len++] = n % 10;
		n /= 10;
	}
	
	LL res = 0;
	for(int i=1;i<len;i++){
		res += dfs(i,len-1,0,0,1);
	}
	res = res - (len - 2);
	return res;
}

int main()
{
	init();
	int test;
	cin >> test;
	while(test--){
		LL l,r;
		cin >> l >> r;
	   	cout << solve(r) - solve(l-1) << endl;
	}
	return 0;
}
