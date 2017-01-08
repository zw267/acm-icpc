                                            
  //File Name: cf543B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月18日 星期一 21时23分07秒
/*

题意：
给出一个图，给出s0,t0,l0,s1,t1,l1
要求在满足dis(s0,t0) <= l0,dis(s1,t1) <= l1的条件下，最多可以删除的边

思路：
由于边的长度都是1
先bfsn次，求出dis(i,j)的值
若dis(s0,t0) > l0 || dis(s1,t1) > l1 返回-1
res = dis(s0,t0) + dis(s1,t1);

由于这2条路径可能有相交的部分
则：
枚举图的任意2点，不断更新res的值
最后返回m - res

*/	
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define pb push_back
#define fir first
#define sec second

using namespace std;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int dis[MAXN][MAXN];

bool vis[MAXN];
vector<int>G[MAXN];

int s[2],t[2],l[2];

void init(int n)
{
	for(int i=1;i<=n;i++)
		G[i].clear();
}

void bfs(int str,int n)
{
	for(int i=1;i<=n;i++)
		dis[str][i] = INF;
	dis[str][str] = 0;
	memset(vis,false,sizeof vis);
	vis[str] = true;

	queue< pair<int,int> > que;
	while(!que.empty())
		que.pop();
	que.push(make_pair(str,0));
	while(!que.empty()){
		pair<int,int> u = que.front();
		que.pop();
		dis[str][u.fir] = u.sec;
		
		for(int i=0;i<G[u.fir].size();i++){
			int to = G[u.fir][i];
			if(vis[to])
				continue;
			que.push(make_pair(to,u.sec+1));
			vis[to] = true;
		}
	}
}

int solve(int n,int m)
{
	for(int i=1;i<=n;i++){
		bfs(i,n);
	}
	//printf("%d %d\n",dis[s[0]][t[0]],dis[s[1]][t[1]]);
	
	if(dis[s[0]][t[0]] > l[0] || dis[s[1]][t[1]] > l[1])
		return -1;

	int res = dis[s[0]][t[0]] + dis[s[1]][t[1]];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp1 = min(dis[s[0]][i] + dis[i][j] + dis[j][t[0]],dis[s[0]][j] + dis[j][i] + dis[i][t[0]]);
			int tmp2 = min(dis[s[1]][i] + dis[i][j] + dis[j][t[1]],dis[s[1]][j] + dis[j][i] + dis[i][t[1]]);
			//if(i == 3 && j == 4)
			//	printf("%d %d %d\n",tmp1,tmp2,dis[i][j]);
			if(tmp1 > l[0] || tmp2 > l[1])
				continue;
			//printf("%d %d %d %d %d\n",i,j,tmp1,tmp2,dis[i][j]);
			res = min(res,tmp1 + tmp2 - dis[i][j]);
		}
	}

	return m  - res;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	init(n);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	scanf("%d %d %d",&s[0],&t[0],&l[0]);
	scanf("%d %d %d",&s[1],&t[1],&l[1]);

	printf("%d\n",solve(n,m));

	return 0;
}
