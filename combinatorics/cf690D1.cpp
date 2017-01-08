                                            
  //File Name: cf690D1.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月11日 星期一 22时11分42秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 103;

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x,int y,int n,int m){
	vis[x][y] = 1;
	int u,v;
	for(int i=0;i<4;i++){
		u = x + dx[i];
		v = y + dy[i];
		if(u < 0 || u >= n || y < 0 || y >= m)
			continue;
		if(maze[u][v] == '.' || vis[u][v] != -1)
			continue;
		dfs(u,v,n,m);
	}
}

int solve(int n,int m){
	int ans = 0;
	memset(vis,-1,sizeof vis);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maze[i][j] == 'B' && vis[i][j] == -1){
				dfs(i,j,n,m);
				ans++;
			}
		}
	}	
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%s",maze[i]);
		printf("%d\n",solve(n,m));
	}
	return 0;
}
