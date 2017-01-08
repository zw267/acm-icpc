                                            
  //File Name: cf557D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 20时38分29秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;

int deg[MAXN];
int is[MAXN];
bool flag;
queue<int> que;

struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot;

void init(){
	memset(head,-1,sizeof head);
	tot = 0;
	memset(deg,0,sizeof deg);
}

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
	edge[tot].to = u;
	edge[tot].next = head[v];
	head[v] = tot++;
}

void dfs(int p,int u,int x){
	is[u] = x;
	que.push(u);
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)
			continue;
		if(is[v] == x){
			flag = false;
			return ;
		}
		else if(is[v] == -1)
			dfs(u,v,x ^ 1);
	}
}

void solve(int n,int m){
	LL ans;
	int ma = -1;
	for(int i=1;i<=n;i++)
		ma = max(deg[i],ma);
	if(ma == 0){
		ans = (LL)n * (n - 1) * (n - 2) / 6;
		cout << "3 " << ans << endl;
	}
	else if(ma == 1){
		ans = (LL)m * (n - 2);
		cout << "2 " << ans << endl; 
	}
	else{
		ans = 0;
		memset(is,-1,sizeof is);
		flag = true;
		while(!que.empty())
			que.pop();
		for(int i=1;i<=n;i++){
			if(is[i] == -1){
				dfs(-1,i,0);
				int x = 0,y = 0, u;
				while(!que.empty()){
					u = que.front();
					que.pop();
					if(is[u] == 0) x++;
					else y++;
				}
				ans += (LL)x * (x - 1) / 2 + (LL)y * (y - 1) / 2;
			}
		}
		if(!flag)
			cout << "0 1" << endl;
		else
			cout << "1 " << ans << endl;
	}
	return ;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init();
		for(int i=0,u,v;i<m;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			deg[u]++;
			deg[v]++;
		}
		solve(n,m);
	}
	return 0;
}
