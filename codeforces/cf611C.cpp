                                            
  //File Name: cf611C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 16时19分10秒
                                   

/*

一个矩阵，有些可以放东西，有些不可以放
现在有一个1*2的物品，有q个询问：
每个询问给出一个子矩阵，把物品放在这个子矩阵里面有多少种方案

2维前缀和

要么横着放，要么竖着放

分别用dpr，dpc2个数组保存横着放的方案数和竖着放的方案数

对于每一个询问呢，容斥一下

*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 505;

int dpr[MAXN][MAXN];
int dpc[MAXN][MAXN];
int is[MAXN][MAXN];
char str[MAXN];

void solve(int R,int C)
{
	memset(dpr,0,sizeof dpr);
	memset(dpc,0,sizeof dpc);

	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			dpr[i][j] = dpr[i-1][j] + dpr[i][j-1] - dpr[i-1][j-1];
			if(is[i][j] && is[i][j-1])
				dpr[i][j]++;
		}
	}

	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			dpc[i][j] = dpc[i-1][j] + dpc[i][j-1] - dpc[i-1][j-1];
			if(is[i][j] && is[i-1][j])
				dpc[i][j]++;
		}
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int r1,c1,r2,c2;
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		int ans = dpr[r2][c2] - dpr[r2][c1] - dpr[r1-1][c2] + dpr[r1-1][c1];
		ans = ans + dpc[r2][c2] - dpc[r2][c1-1] - dpc[r1][c2] + dpc[r1][c1-1];
		printf("%d\n",ans);
	}
	return ;
}

int main()
{
	memset(is,0,sizeof is);
	int R,C;
	scanf("%d %d",&R,&C);
	for(int i=1;i<=R;i++){
		scanf("%s",str);
		for(int j=1;j<=C;j++){
			if(str[j-1] == '.')
				is[i][j] = 1;
		}
	}

	solve(R,C);

	return 0;
}
