                                            
  //File Name: cf616B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 17时05分12秒

/*

给出一个n*m的矩阵，矩阵的每一行有一个最小值，
求出这n个最小值的最大值

*/
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;

int cost[MAXN][MAXN];
int mi[MAXN];

void solve(int n,int m)
{
	for(int i=1;i<=n;i++){
		mi[i] = cost[i][1];
		for(int j=2;j<=m;j++){
			if(cost[i][j] < mi[i])
				mi[i] = cost[i][j];
		}
	}

	int res = mi[1];
	for(int i=2;i<=n;i++){
		if(mi[i] > res)
			res = mi[i];
	}
	printf("%d\n",res);
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	solve(n,m);

	return 0;
}
