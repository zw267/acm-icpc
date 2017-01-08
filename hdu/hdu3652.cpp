#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

#define LL long long

using namespace std;

LL dp[12][10][13][2];
LL p[12];
int a[12];

void init()
{
	memset(dp,-1,sizeof dp);
	p[0] = 1;
	for(int i=1;i<12;i++)
		p[i] = p[i-1] * 10;
}

LL dfs(int pos,int pre,int mod,int have,bool limit)
{
	if(!limit && dp[pos][pre][mod][have] != -1)
		return dp[pos][pre][mod][have];

	if(pos == 0){
		if(have == 0 && mod == 0)
			return 1;
		else
			return 0;
	} 

	LL res = 0;
	int ma = limit ? a[pos] : 9;

	for(int i=0;i<=ma;i++){
		int tmp = (mod * 10 + i ) % 13;
		if(have){
			if(pre == 1 && i==3)
				res = res + dfs(pos-1, i, tmp,0,limit && i==ma) +
					dfs(pos-1,i,tmp,1,limit && i==ma);
			else
				res = res + dfs(pos-1, i,tmp, 1,limit && i==ma);
		}
		else{
			if(pre == 1 && i==3)
				continue;
			res = res + dfs(pos-1, i ,tmp,0 ,limit && i==ma);
		}
	}

	return limit ? res : dp[pos][pre][mod][have] = res;
}

LL solve(LL n)
{
	int len = 1;
	while(n){
		a[len++] = n % 10;
		n /= 10;
	}
	
	return dfs(len-1,0,0,1,true);
}

int main()
{
	init();
	LL n;
	while(cin >> n){
		cout << solve(n) << endl;
	}
	return 0;
}
