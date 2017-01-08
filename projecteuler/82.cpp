                                            
  //File Name: 82.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 12时31分36秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 82;
const LL INF = 0x3f3f3f3f3f3f3f;
int a[MAXN][MAXN];
LL f[MAXN][MAXN][2][2];
LL solve(int n){
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			for(int x=0;x<=1;x++)
				for(int y=0;y<=1;y++)
					f[i][j][x][y] = INF;
	for(int i=1;i<=n;i++)
		f[i][0][0][0] = 0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			f[i][j][0][0] = min(f[i][j-1][1][0],f[i][j-1][0][1]);
			f[i][j][0][0] = min(f[i][j][0][0],f[i][j-1][0][0]);
			f[i][j][0][0] += a[i][j];
		}
		for(int i=1;i<=n;i++)
			f[i][j][1][0] = min(f[i-1][j][0][0],f[i-1][j][1][0])+a[i][j];
		for(int i=n;i>0;i--)
			f[i][j][0][1] = min(f[i+1][j][0][1],f[i+1][j][0][0])+a[i][j];
	}
	LL res = INF;
	for(int i=1;i<=n;i++)
		for(int x=0;x<=1;x++)
			for(int y=0;y<=1;y++)
				res = min(res,f[i][n][x][y]);
	return res;
}
int main(){
	int n = 80;
	freopen("data.in","r",stdin);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++)
			scanf("%d,",&a[i][j]);
		scanf("%d",&a[i][n]);
	}
	cout << solve(n) << endl;
	fclose(stdin);
	return 0;
}
