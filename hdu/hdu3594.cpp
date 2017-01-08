                                            
  //File Name: hdu3594.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月02日 星期二 22时24分32秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 20000+5;
const int MAXM = 50000+5;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
int out[MAXN];
int in[MAXN];
bool vis[MAXN];

void init(int n)
{
	for(int i=0;i<n;i++){
		G[i].clear();
		rG[i].clear();
	}
	memset(out,0,sizeof out);
	memset(in,0,sizeof in);
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
	int res = 0;
	memset(vis,false,sizeof vis);
	vs.clear();
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(i);
	}
	memset(vis,false,sizeof vis);
	for(int i=vs.size()-1;i>=0;i--){
		int v = vs[i];
		if(!vis[v]){
			rdfs(v);
			res++;
		}
	}
	return res;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		init(n);
		int u,v;
		while(scanf("%d %d",&u,&v)){
			if(u == 0 && v == 0)
				break;
			addedge(u,v);
			out[u]++;
			in[v]++;
		}
		bool flag = true;
		for(int i=0;i<n;i++){
			if(out[i] != in[i])
				flag = false;
		}
		if(flag && scc(n) == 1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
