#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>

#define LL long long

using namespace std;

LL dp[20][10];
int a[20];
LL sum[20];
LL p[20];

LL dfs(int pos,int pre,bool limit)
{
	if(!limit && dp[pos][pre] != -1)
		return dp[pos][pre];
	if(pos == 0)
		return pre==1;

	int ma = limit?a[pos]:9;
	LL res = 0;

	for(int i=0;i<=ma;i++){
		res = res + dfs(pos-1,i,limit && i==ma);
	}
	if(pre==1){
		if(limit)
			res += sum[pos] + 1;
		else
			res += p[pos];
	}
	if(!limit)
		dp[pos][pre] = res;
	return res;
}

LL solve(LL n)
{
	if(n==0)
		return 0;
	if(n<10)
		return 1;
	int len=1;

	while(n){
		a[len++]=n % 10;
		n /= 10 ;
	}
	sum[0] = 0;
	sum[1] = a[1];
	for(int i=2;i<len;i++)
		sum[i] = sum[i-1] + a[i] * p[i-1];

	return dfs(len-1,0,true);
}

void init()
{
	memset(dp,-1,sizeof dp);
	p[0]=1;
	for(int i=1;i<19;i++)
		p[i] = p[i-1] * 10;
}

int main()
{
	init();
	LL l,r;
	while(cin>>l>>r){
		if(l>r)
			swap(l,r);
		cout<<solve(r)-solve(l-1)<<endl;
	}
	return 0;
}
