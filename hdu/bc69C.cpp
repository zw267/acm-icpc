                                            
  //File Name: bc69C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 19时47分18秒
                                   

#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long double

using namespace std;

char a[50][50];
bool vis[50][50];

int dx[4] = {-2,0,0,2};
int dy[4] = {0,-2,2,0};
int dxx[4] = {-1,0,0,1};
int dyy[4] = {0,-1,1,0};

bool flag;
LL sum;
int n,m;

LL get(LL cnt,char op,LL num)
{
	if(op == '+')
		return cnt + num;
	if(op == '-')
		return cnt - num;
	if(op == '*')
		return cnt * num;
	if(op == '/')
		return cnt / num;
}

void dfs(int r,int c,LL cnt)
{
	if(flag)
		return ;
	if(cnt == sum){
		flag = true;
		return ;
	}

	for(int i=0;i<4;i++){
		int dr = r + dx[i];
		int dc = c + dy[i];
		if(dr < 0 || dr >= n || dc < 0 || dc >= m)
			continue;
		if(vis[dr][dc])
			continue;
		int num = a[dr][dc] - '0';
		int drr = r + dxx[i];
		int dcc = c + dyy[i];
		if(a[drr][dcc] == '/' && num == 0)
			continue;
		LL cur = get(cnt,a[drr][dcc],num);
		vis[dr][dc] = true;
		dfs(dr,dc,cur);
		vis[dr][dc] = false;
	}

}

void solve()
{
	if(sum > 10000000000000000LL){
		puts("Impossible");
		return ;
	}
	flag = false;
	memset(vis,false,sizeof vis);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int cnt = a[i][j] - '0';
			if(0 <= cnt && cnt <= 9){
				vis[i][j] = true;
				dfs(i,j,cnt);
				vis[i][j] = false;
				if(flag){
					puts("Possible");
					return ;
				}
			}
		}
	}
	puts("Impossible");
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&m);
		cin >> sum;
		for(int i=0;i<n;i++)
			scanf("%s",a[i]);

		solve();
	}
	return 0;
}
