                                            
  //File Name: hdu1269.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月01日 星期一 21时40分47秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool vis[MAXN];

void dfs(int u)
{
	vis[u] = true;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i];
		if(!vis[v])
			dfs(v);
	}
	vs.push_back(u);
}

void rdfs(int u)
{
	vis[u] = true;
	for(int i=0;i<rG[u].size();i++){
		int v = rG[u][i];
		if(!vis[v])
			rdfs(v);
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
	int k = 0;
	for(int i=vs.size()-1;i>=0;i--){
		int v = vs[i];
		if(!vis[v]){
			rdfs(v);
			k++;
		}
	}
	return k;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(!n && !m)
			break;
		for(int i=1;i<=n;i++){
			G[i].clear();
			rG[i].clear();
		}
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			rG[v].push_back(u);
		}
		int k = scc(n);
		if(k == 1)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
