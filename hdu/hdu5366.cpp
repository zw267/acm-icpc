                                            
  //File Name: hdu5366.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 23时20分47秒

/*

一个1*n的矩阵，n <= 60
可以在矩阵里面放石子，但是要求任意2个石子之间的空格子数 >= 2

问，在这个1*n的矩阵中，放至少一个石子的方案数

思路：
dp[i][j][k]:表示考虑了第i个格子，一共放了j个石子，
第i个格子在k这种状态下的方案数
k = 0 表示第i个格子没有放石子
k = 1 表示第i个格子有放石子

先求出dp数组

然后对于每一个输入n，直接累加即可
累加：dp[n][j][k] 
到了第n个格子，一共放了j个石子，第n个格子在k这种状态下的方案数

*/
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 61;

LL dp[MAXN][MAXN][2];

void init()
{
	memset(dp,0,sizeof dp);
	for(int i=1;i<MAXN;i++){
		dp[i][1][1] = 1;
		for(int j=1;j<i;j++)
			dp[i][1][0] += dp[j][1][1];
	}

	for(int j=2;j<=MAXN;j++){
		for(int i=4;i<MAXN;i++){
			for(int k=1;k<=i-3;k++)
				dp[i][j][1] += dp[k][j-1][1];
			for(int k=1;k<i;k++)
				dp[i][j][0] += dp[k][j][1];
		}
	}


	return ;
}

int main()
{
	init();
	int n;
	while(~scanf("%d",&n)){
		LL res = 0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<2;k++)
				res += dp[n][j][k];
		}
		cout << res << endl;
	}
	return 0;
}
