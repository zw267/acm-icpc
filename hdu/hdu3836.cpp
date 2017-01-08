                                            
  //File Name: hdu3836.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月01日 星期一 22时10分49秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

const int MAXN = 20000+5;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool vis[MAXN];
int out[MAXN];
int in[MAXN];
int chg[MAXN];
int from[50000+5];
int to[50000+5];

void init(int n)
{
	for(int i=1;i<=n;i++){
		G[i].clear();
		rG[i].clear();
	}
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
	int res = 0;
	memset(vis,false,sizeof vis);
	vs.clear();
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}
	memset(vis,false,sizeof vis);
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
	if(num == 1){
		puts("0");
		return ;
	}
	//printf("%d\n",num);
	memset(out,0,sizeof out);
	memset(in,0,sizeof in);
	for(int i=0;i<m;i++){
		int u = chg[from[i]];
		int v = chg[to[i]];
		if(u == v)
			continue;
		out[u]++;
		in[v]++;
	}
	int a = 0,b = 0;
	for(int i=0;i<num;i++){
		if(out[i] == 0)
			a++;
		if(in[i] == 0)
			b++;
	}
	printf("%d\n",max(a,b));
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init(n);
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			from[i] = u;
			to[i] = v;
			G[u].pb(v);
			rG[v].pb(u);
		}
		solve(n,m);
	}
	return 0;
}
