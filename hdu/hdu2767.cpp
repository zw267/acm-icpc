                                            
  //File Name: hdu2767.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月29日 星期五 19时53分19秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20000+5;
const int MAXM = 50000+5;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool vis[MAXN];
int chg[MAXN];
int in[MAXN];
int out[MAXN];
pair<int,int> edge[MAXM];

void addedge(int u,int v)
{
	G[u].push_back(v);
	rG[v].push_back(u);
}

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

void rdfs(int u,int k)
{
	vis[u] = true;
	chg[u] = k;
	for(int i=0;i<rG[u].size();i++){
		int v = rG[u][i];
		if(!vis[v]){
			rdfs(v,k);
		}
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
		if(!vis[vs[i]]){
			rdfs(vs[i],res++);
		}
	}
	return res;
}

void init(int n)
{
	for(int i=0;i<=n;i++){
		G[i].clear();
		rG[i].clear();
	}
}

void solve(int n,int m)
{
	int num = scc(n);
	if(num == 1){
		printf("0\n");
		return ;
	}
	memset(in,0,sizeof in);
	memset(out,0,sizeof out);
	for(int i=1;i<=m;i++){
		int u = edge[i].first;
		int v = edge[i].second;
		if(chg[u] == chg[v])
			continue;
		out[chg[u]]++;
		in[chg[v]]++;
	}
	int the_in = 0;
	int the_out = 0;
	for(int i=0;i<num;i++){
		if(in[i] == 0)
			the_in++;
		if(out[i] == 0)
			the_out++;
	}
	printf("%d\n",max(the_in,the_out));
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d %d",&n,&m);
		init(n);
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			edge[i] = make_pair(u,v);
			addedge(u,v);
		}
		solve(n,m);
	}
	return 0;
}
