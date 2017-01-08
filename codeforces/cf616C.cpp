                                            
  //File Name: cf616C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 17时43分11秒

/*
一个矩阵，.表示空，*表示不空
.的地方组成一个联通块
则这个矩阵有若干个联通块
对于每一个*，求出如果*也是.的话，则该位置所在的地方有多少个联通块

思路：
先bfs一遍，确定联通块并且给联通块编号，确定每一个联通块的格子数
然后对于每一个*，知道了它周围4个联通块的编号，看合起来一共有多少个格子

简单题

*/
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1005;

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
char ans[MAXN][MAXN];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
vector<int> sum;

struct Node
{
	int x,y;
};

void bfs(int r,int c,int tot,int n,int m)
{
	int cur = 1;
	vis[r][c] = tot;
	queue<Node>que;
	while(!que.empty())
		que.pop();
	que.push((Node){r,c});
	while(!que.empty()){
		Node u = que.front();
		que.pop();
		Node du;
		for(int i=0;i<4;i++){
			du.x = u.x + dx[i];
			du.y = u.y + dy[i];
			if(du.x < 0 || du.x >= n || du.y < 0 || du.y >= m)
				continue;
			if(vis[du.x][du.y] >=0 || maze[du.x][du.y] == '*')
				continue;
			vis[du.x][du.y] = tot;
			cur++;
			que.push(du);
		}
	}
	sum.push_back(cur);
	return ;
}

char get(int r,int c,int n,int m)
{
	int res = 1;
	vector<int> tmp;
	vector<int> cur;

	for(int i=0;i<4;i++){
		int dr = r + dx[i];
		int dc = c + dy[i];
		if(dr < 0 || dr >= n || dc < 0 || dc >= m)
			continue;
		if(maze[dr][dc] == '*')
			continue;
		tmp.push_back(vis[dr][dc]);
	}

	for(int i=0;i<tmp.size();i++){
		int num = tmp[i];
		bool flag  = false;
		for(int j=0;j<cur.size();j++){
			if(num == cur[j]){
				flag = true;
				break;
			}
		}
		if(!flag){
			res += sum[num];
			cur.push_back(num);
		}
	}
	res %= 10;
	return res + '0';
}

void solve(int n,int m)
{
	memset(vis,-1,sizeof vis);
	sum.clear();

	int tot = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j] == -1 && maze[i][j] == '.'){
				bfs(i,j,tot,n,m);
				tot++;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maze[i][j] == '.'){
				ans[i][j] = maze[i][j];
			}
			else{
				ans[i][j] = get(i,j,n,m);
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%s\n",ans[i]);
	}
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",maze[i]);
	}
	solve(n,m);
	return 0;
}
