                                            
  //File Name: poj2553.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月02日 星期二 16时17分36秒
                                   
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 5005;

vector<int> G[MAXN];
vector<int> rG[MAXN];
vector< pair<int,int> > edge;
vector<int> vs;
vector<int> ans;
bool vis[MAXN];
int chg[MAXN];
int out[MAXN];

void init(int n)
{
	for(int i=0;i<=n;i++){
		G[i].clear();
		rG[i].clear();
	}
	edge.clear();
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
	int res = 0;
	memset(vis,false,sizeof vis);
	for(int i=vs.size()-1;i>=0;i--){
		int v = vs[i];
		if(!vis[v])
			rdfs(v,res++);
	}
	return res;
}

void solve(int n)
{
	int k = scc(n);
	//for(int i=1;i<=n;i++)
	//	printf("%d = %d\n",i,chg[i]);
	memset(out,0,sizeof out);
	for(int i=0;i<edge.size();i++){
		int u = chg[edge[i].first];
		int v = chg[edge[i].second];
		if(u == v)
			continue;
		out[u]++;
	}
	ans.clear();
	for(int i=1;i<=n;i++){
		if(out[chg[i]] == 0)
			ans.pb(i);
	}
	sort(ans.begin(),ans.end());
	if(ans.size() == 0)
		puts("");
	else{
		for(int i=0;i<ans.size()-1;i++){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[ans.size()-1]);
	}
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		init(n);
		int e;
		scanf("%d",&e);
		for(int i=0;i<e;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			addedge(u,v);
			edge.pb(make_pair(u,v));
		}
		solve(n);
	}
	return 0;
}

