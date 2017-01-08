                                            
  //File Name: poj2186.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月02日 星期二 15时49分22秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 10000+5;
const int MAXM = 50000+5;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool vis[MAXN];
int chg[MAXN];

void init(int n)
{
	for(int i=0;i<=n;i++){
		G[i].clear();
		rG[i].clear();
	}
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
		if(!vis[v])
			rdfs(v,res++);
	}
	return res;
}

void solve(int n,int m)
{
	int num = scc(n);
	int ans = 0;
	int cur = -1;
	for(int i=1;i<=n;i++){
		if(chg[i] == num-1){
			ans++;
			cur = i;
		}
	}
	memset(vis,false,sizeof vis);
	rdfs(cur,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans = 0;
			break;
		}
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init(n);
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			addedge(u,v);
		}
		solve(n,m);
	}
	return 0;
}
