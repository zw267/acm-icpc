                                            
  //File Name: hdu1827.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月01日 星期一 22时40分59秒
                                   

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

#define pb push_back

using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
vector<int> num[MAXN];
int chg[MAXN];
bool vis[MAXN];
int from[MAXN << 1];
int to[MAXN << 1];
int in[MAXN];
int cost[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++){
		G[i].clear();
		rG[i].clear();
		num[i].clear();
	}
	num[0].clear();
}

void addedge(int u,int v)
{
	G[u].pb(v);
	rG[v].pb(u);
}

void dfs(int u)
{
	vis[u] = true;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(!vis[v])
			dfs(v);
	}
	vs.pb(u);
}

void rdfs(int u,int k)
{
	vis[u] = true;
	chg[u] = k;
	num[k].pb(u);
	for(int i=0;i<rG[u].size();i++){
		int v = rG[u][i];
		if(!vis[v])
			rdfs(v,k);
	}
}

int scc(int n)
{
	memset(vis,false,sizeof vis);
	vs.clear();
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}
	memset(vis,false,sizeof vis);
	int res = 0;
	for(int i=vs.size()-1;i>=0;i--){
		int v = vs[i];
		if(!vis[v]){
			rdfs(v,res++);
		}
	}
	return res;
}

void solve(int n,int m)
{
	int k = scc(n);
	memset(in,0,sizeof in);
	for(int i=0;i<m;i++){
		int u = chg[from[i]];
		int v = chg[to[i]];
		if(u == v)
			continue;
		in[v]++;
	}
	int tot = 0;
	int ans = 0;
	for(int i=0;i<k;i++){
		if(in[i])
			continue;
		tot++;
		int mi = INF;
		for(int j=0;j<num[i].size();j++){
			mi = min(mi,cost[num[i][j]]);
		}
		ans += mi;
	}
	printf("%d %d\n",tot,ans);
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init(n);
		for(int i=1;i<=n;i++){
			scanf("%d",&cost[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&from[i],&to[i]);
			addedge(from[i],to[i]);
		}
		solve(n,m);
	}
	return 0;
}


