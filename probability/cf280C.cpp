                                            
  //File Name: cf280C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月23日 星期六 21时55分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000 + 3;

struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot;
double ans;

void init(){
	memset(head,-1,sizeof head);
	tot = 0;
}

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int u,int p,int s){
	ans += 1.0 / (s + 0.0);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dfs(v,u,s+1);
	}
}

double solve(int n){
	ans = 0;
	dfs(1,-1,1);
	return ans;
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
		printf("%.8f\n",solve(n));
	}
	return 0;
}
