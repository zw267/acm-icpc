#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 200000+10;
const int MOD = 1e9+7;

vector<int>G[MAXN];
LL dp[MAXN];
LL res[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++){
		G[i].clear();
		dp[i] = -1;
		res[i] = -1;
	}
}

LL qp(LL x,LL y)
{
	LL ret = 1;
	while(y){
		if(y & 1)
			ret =ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

LL inv(LL x)
{
	return qp(x,MOD - 2);
}

void dfs1(int u)
{
	dp[u] = 1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(dp[v] != -1)
			continue;
		dfs1(v);
		dp[u] = dp[u] * (dp[v] + 1 ) % MOD;
	}
}

void dfs2(int u)
{
	for(int i=0;i<G[u].size();i++){
		int v= G[u][i];
		if(res[v] != -1)
			continue;
		res[v] = (res[u] * inv(dp[v] + 1) % MOD +1) % MOD * dp[v] % MOD;
		dfs2(v);
	}
}

void solve(int n)
{
	dfs1(1);
	res[1] = dp[1];
	dfs2(1);
}

int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=2;i<=n;i++){
		int u;
		scanf("%d",&u);
		G[i].pb(u);
		G[u].pb(i);
	}

	solve(n);
	
	for(int i=1;i<n;i++){
		printf("%lld ",res[i]);
		//printf("%I64d ",res[i]);
	}
	printf("%lld\n",res[n]);
	//printf("%I64d\n",res[n]);

	return 0;
}
