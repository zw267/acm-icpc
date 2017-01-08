                                            
  //File Name: uva11038.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月23日 星期三 21时32分15秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

#define LL long long 

using namespace std;

LL dp[15][10][2];
int a[15];
LL have_limit[15];
LL no_limit[15];

void init()
{
	memset(dp,-1,sizeof dp);
	no_limit[0] = 0;
	for(int i=1;i<15;i++){
		no_limit[i] = no_limit[i-1] * 10 + 9;
	}
}

LL dfs(int pos,int pre,int is,bool limit)
{
	if(!limit && dp[pos][pre][is] != -1)
		return dp[pos][pre][is];
	if(pos == 0){
		if(!is && pre == 0)
			return 1;
		else
			return 0;
	}
	
	int ma = limit? a[pos]: 9;
	LL res = 0;

	for(int i=0;i<=ma;i++){
		res = res + dfs(pos-1,i,is && i == 0,i == ma && limit);
	}

	if(pre == 0 && !is){
		if(limit)
			res = res + have_limit[pos] + 1;
		else
			res = res + no_limit[pos] + 1;
	}
	
	return limit? res : dp[pos][pre][is] = res;
}

LL solve(LL n)
{
	if(n < 0)
		return -1;
	int len = 0;
	while(n){
		a[++len] = n % 10;
		n /= 10;
	}
	
	have_limit[0] = 0;
	for(int i=1;i<=len;i++){
		have_limit[i] = a[i] * pow(10,i-1) + have_limit[i-1];
		//printf("%lld\n",have_limit[i]);
	}

	return dfs(len,0,true,true);
}

int main()
{
	init();
	LL l,r;
	while(~scanf("%lld %lld",&l,&r)){
		if(l < 0 || r < 0)
			break;
		printf("%lld\n",solve(r) - solve(l - 1) );
	}
	return 0;
}
