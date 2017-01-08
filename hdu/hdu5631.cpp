                                            
  //File Name: hdu5631.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月21日 星期日 00时35分23秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define fir first
#define sec second

using namespace std;

const int MAXN = 105;

struct E
{
	int u,v,num_u,num_v;
};

vector<int> edge[MAXN];
E e[MAXN];
pair<int,int> is[MAXN],base;
bool vis[MAXN];

void init(int n)
{
	for(int i=1;i<=n;i++)
		edge[i].clear();
	base = make_pair(-1,-1);
	for(int i=1;i<=n+1;i++)
		is[i] = base;
}

void addedge(int i,int u,int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
	e[i].u = u;
	e[i].v = v;
	e[i].num_u = edge[u].size() - 1;
	e[i].num_v = edge[v].size() - 1;
}

void dfs(int u)
{
	vis[u] = true;
	for(int i=0;i<edge[u].size();i++){
		if(i == is[u].fir || i == is[u].sec)
			continue;
		int v = edge[u][i];
		if(!vis[v])
			dfs(v);
	}
}

void solve(int n)
{
	int ans = 0;
	for(int i=1;i<=n+1;i++){
		for(int j=i;j<=n+1;j++){
			is[e[i].u] = make_pair(e[i].num_u,-1);
			is[e[i].v] = make_pair(e[i].num_v,-1);
			if(i != j){
				if(e[j].u == e[i].u || e[j].u == e[i].v)
			  	 	is[e[j].u] = make_pair(is[e[j].u].fir,e[j].num_u);
				else
					is[e[j].u] = make_pair(e[j].num_u,-1);
				if(e[j].v == e[i].u || e[j].v == e[i].v)
					is[e[j].v] = make_pair(is[e[j].v].fir,e[j].num_v);
				else
					is[e[j].v] = make_pair(e[j].num_v,-1);	
			}
			memset(vis,false,sizeof vis);
			dfs(1);
			bool flag = true;
			for(int i=1;i<=n;i++){
				if(vis[i] == false){
					flag = false;
					break;
				}
			}
			if(flag)
				ans++;
			is[e[i].u] = base;
			is[e[i].v] = base;
			is[e[j].u] = base;
			is[e[j].v] = base;
		}
	}

	printf("%d\n",ans);
	return ;
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
		for(int i=1;i<=n+1;i++){
			scanf("%d %d",&u,&v);
			addedge(i,u,v);
		}
		solve(n);
	}
	return 0;
}
