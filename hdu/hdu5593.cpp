                                            
  //File Name: hdu5593.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月11日 星期一 23时54分25秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define pb push_back
#define LL long long

using namespace std;

const int MAXN = 500000+5;

int dp1[MAXN][11];
int dp2[MAXN][11];
int fa[MAXN];
int A,B,K;
vector<int>G[MAXN];

int get_fa(int x)
{
	return ((LL)A * x + B) % (x - 1) + 1;
}

void dfs0(int u)
{
	dp1[u][0] = 1;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		dfs0(v);
		for(int j=1;j<=K;j++){
			dp1[u][j] += dp1[v][j-1];
		}
	}
}

void dfs1(int u)
{
	for(int j=1;j<=K;j++){
		dp2[u][j] += dp2[fa[u]][j-1] + dp1[fa[u]][j-1];
		if(u != 1 && j >= 2){
			dp2[u][j] -= dp1[u][j-2];
		}
	}
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		dfs1(v);
	}
}

void solve(int n)
{
	for(int i=0;i<=n;i++)
		G[i].clear();
	fa[1] = 0;
	for(int i=2;i<=n;i++){
		fa[i] = get_fa(i);
		G[fa[i]].pb(i);
	}

	memset(dp1,0,sizeof dp1);
	memset(dp2,0,sizeof dp2);

	dfs0(1);
	dfs1(1);

	//for(int i=1;i<=n;i++){
	//	for(int j=0;j<=K;j++)
	//		printf("%d  ",dp2[i][j]);
	//	puts("");
	//}

	int res = 0;
	for(int i=1;i<=n;i++){
		int tmp = 0;
		for(int j=0;j<=K;j++){
			tmp = tmp + dp1[i][j] + dp2[i][j];
		}
		//printf("%d\n",tmp);
		res ^= tmp;
	}

	printf("%d\n",res);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d %d %d %d",&n,&K,&A,&B);
		solve(n);
	}
	return 0;
}
