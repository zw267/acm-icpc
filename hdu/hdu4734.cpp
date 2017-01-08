/*

dp[pos][pre][sum] 
but pre is not necessary
dp[pos][sum]
is enough

*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pow2[12];
int dp[12][10][6000];
int a[12];

void init()
{
	memset(dp,-1,sizeof dp);
	pow2[0] = 1;
	for(int i=1;i<12;i++)
		pow2[i] = pow2[i-1] * 2;
}

int get_f(int x)
{
	int f = 0;
	int len = 0;
	while(x){
		a[len++] = x % 10;
		x /= 10;
	}
	for(int i=0;i<len;i++){
		f += pow2[i] * a[i];
	}
	return f;
}

int dfs(int pos,int pre,int sum,bool limit)
{
	if(sum < 0)
		return 0;
	if(!limit && dp[pos][pre][sum] != -1)
		return dp[pos][pre][sum];
	if(pos == 0)
		return 1;
	int ma = limit?a[pos]:9;
	int res = 0;
	for(int i=0;i<=ma;i++){
		res += dfs(pos-1,i,sum - i * pow2[pos-1],limit && i == ma);
	}

	return limit ? res : dp[pos][pre][sum] = res;
}

int solve(int x,int n)
{
	int f = get_f(x);
	int len = 0;
	while(n){
		a[++len] = n % 10;
		n /= 10;
	}
	return dfs(len,0,f,true);
}

int main()
{
	init();
	int test;
	int cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case #%d: ",cas++);
		int x,r;
		scanf("%d %d",&x,&r);
		printf("%d\n",solve(x,r));
	}
	return 0;
}
