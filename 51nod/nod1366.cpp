                                            
  //File Name: nod1366.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 21时42分28秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 55;

struct Edge{
	int to,next;
}edge[MAXN * MAXN];

int head[MAXN],tot;

void init(){
	memset(head,-1,sizeof head);
	tot = 0;
}

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

char str[MAXN];
int level[MAXN];
int has[MAXN][MAXN];

void bfs(int s){
	memset(level,-1,sizeof level);
	level[s] = 0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i=head[u];~i;i=edge[i].next){
			int v = edge[i].to;
			if(level[v] != -1) continue;
			level[v] = level[u] + 1;
			que.push(v);
		}
	}
}

int solve(int n,int D){
	memset(level,-1,sizeof level);
	bfs(0);
	for(int i=0;i<n;i++){
		if(level[i] == -1) 
			return -1;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		bfs(i);
		//for(int j=0;j<n;j++)
		//	printf("i = %d %d\n",j,level[j]);
		int ma = 0;
		for(int j=0;j<n;j++){
			if(level[j] > ma)
				ma = level[j];
		}
		ans = max(ans,ma * D);
	}
	return ans;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		init();
		memset(has,0,sizeof has);
		int n,D;
		scanf("%d %d",&n,&D);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			for(int j=0;j<n;j++){
				if(str[j] == 'Y' && has[i][j] == 0){
					addedge(i,j);
					addedge(j,i);
					has[i][j] = has[j][i] = 1;
				}
			}
		}
		printf("%d\n",solve(n,D));
	}
	return 0;
}
