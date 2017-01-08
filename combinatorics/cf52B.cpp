                                            
  //File Name: cf52B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月23日 星期二 20时06分13秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 1005;

int row[MAXN];
int col[MAXN];
char s[MAXN][MAXN];

void solve(int n,int m)
{
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j] == '*'){
				row[i]++;
				col[j]++;
			}
		}
	}
	//for(int i=1;i<=n;i++)
	//	printf("%d ",row[i]);
	LL ans = 0LL;
	for(int j=1;j<=m;j++){
		if(col[j] <= 1)
			continue;
		for(int i=1;i<=n;i++){
			if(s[i][j] == '*')
				ans = ans + (LL)(col[j] - 1) * (row[i] - 1);
		}
	}

	cout << ans << endl;
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%s",s[i] + 1);
		}
		solve(n,m);
	}
	return 0;
}
