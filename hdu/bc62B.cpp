                                            
  //File Name: bc62B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月26日 星期六 20时18分57秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[12];
int dp[12][10][7];
int len,k;

void init()
{
	memset(dp,-1,sizeof dp);
}

int dfs(int pos,int pre,int mod,bool limit)
{
	if(!limit && dp[pos][pre][mod] != -1)
		return dp[pos][pre][mod];

	if(pos == 0){
		return mod == 0;
	}

	int res = 0;
	int ma = limit?a[pos]:9;
	for(int i=0;i<=ma;i++){
		if(pos != len && i + pre == k)
			continue;
		int cur_mod = (mod * 10 + i) % 7;

	}
}

int solve(int n)
{
	len = 0;
	while(n){
		a[++len] = n % 10;
		n /= 10;
	}

	return dfs(len,0,0,true);
}

int main()
{
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int l,r;
		scanf("%d %d %d",&l,&r,&k);
		printf("%d\n",solve(r) - solve(l - 1));
	}
	return 0;
}
