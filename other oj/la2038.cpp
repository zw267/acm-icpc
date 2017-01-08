                                            
  //File Name: la2038.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 23时06分43秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

const int MAXN  = 1505;
const int INF = 0x3f3f3f3f;

vector<int> G[MAXN];
int dp[MAXN][2][2];
int fa[MAXN];

void init(int n)
{
	for(int i=0;i<n;i++)
		G[i].clear();
}

void dfs0(int u,int pa)
{
	fa[u] = pa;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(v == pa)
			continue;
		dfs0(v,u);
	}
}

void dfs1(int u)
{
	dp[u][1][1] = 1;
	dp[u][0][0] = 0;
	dp[u][0][1] = INF;
	if(G[u].size() == 1 && fa[u] != u){
		return ;
	}

	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(v == fa[u])
			continue;
		dfs1(v);
		dp[u][1][1] += min(dp[v][1][1],min(dp[v][0][0],dp[v][0][1]));
		dp[u][0][0] += dp[v][0][1];
	}
	for(int i=0;i<G[u].size();i++){
		int son = G[u][i];
		if(son == fa[u])
			continue;
		int tmp = dp[son][1][1];
		for(int j=0;j<G[u].size();j++){
			int v = G[u][j];
			if(v == fa[u] || v == son)
				continue;
			tmp += min(dp[v][0][1],dp[v][1][1]);

		}
		dp[u][0][1] = min(dp[u][0][1],tmp);
	}
}

void solve(int n)
{
	int root = 0;
	dfs0(root,root);
	dfs1(root);
	printf("%d\n",min(dp[root][0][1],dp[root][1][1]));
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		init(n);
		for(int i=0;i<n;i++){
			int u,num;
			scanf("%d:(%d)",&u,&num);
			for(int j=0;j<num;j++){
				int v;
				scanf("%d",&v);
				G[u].pb(v);
				G[v].pb(u);
			}
		}
		//puts("eeeeeeeee");
		solve(n);
	}
	return 0;
}
