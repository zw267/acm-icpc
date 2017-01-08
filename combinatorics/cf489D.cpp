                                            
  //File Name: cf489D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 22时43分41秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 3005;
const int MAXM = 30005;

int is[MAXN][MAXN];

struct Edge
{
	int to,next;
};
Edge edge[MAXM];
int head[MAXN],tot;

void init()
{
	memset(is,0,sizeof is);
	memset(head,-1,sizeof head);
	tot = 0;
}

void addedge(int u,int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int s,int u,int step)
{
	if(step == 2){
		is[s][u]++;
		return ;
	}
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == s)
			continue;
		dfs(s,v,step+1);
	}
}

void solve(int n,int m)
{
	for(int i=1;i<=n;i++){
		dfs(i,i,0);
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++)
	//		cout << is[i][j] << " ";
	//	cout << endl;
	//}
	LL ans = 0LL;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j)
				continue;
			ans += (LL)is[i][j] * (is[i][j] - 1) / 2;
		}
	}
	cout << ans << endl;
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init();
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
		}

		solve(n,m);
	}
	return 0;
}
