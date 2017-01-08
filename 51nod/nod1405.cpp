                                            
  //File Name: nod1405.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 16时11分10秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;

struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot;

int siz[MAXN];
LL dis[MAXN];

void init(){
	memset(head,-1,sizeof head);
	tot = 0;
}

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int u,int p){
	dis[u] = 0;
	siz[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dfs(v,u);
		dis[u] += dis[v] + siz[v];
		siz[u] += (LL)siz[v];
	}
}

void dfs2(int u,int p,int n){
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dis[v] = dis[u] + n - 2 * siz[v];
		dfs2(v,u,n);
	}
}

void solve(int n){
	dfs(1,-1);
	dfs2(1,-1,n);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve(n);
		for(int i=1;i<=n;i++)
			printf("%lld\n",dis[i]);
	}
	return 0;
}
