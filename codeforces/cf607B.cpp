                                            
  //File Name: cf607B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 11时37分48秒

/*
题意：
给出一个序列,长度为n,n <= 500，我们每次可以从这个序列里面拿出一个连续的子序列，只要这个子序列是回文的，问，最少需要拿的次数
思路：
明显的区间dp
设dp[l][r] 表示把子序列[l,r]拿掉最少需要的次数
首先，很明显的转移：
初始化：dp[l][r] = INF
if(is[l][r])
	dp[l][r] = 1;
else
	枚举断点k，dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]);

但是这样的转移还不够，比如这一组数据：1 2 8 9 8 3 4 3 2 1
其实只需要拿2次
注意到这组数据的转移：
1 2 8 9 8 3 4 3 2 1
2 8 9 8 3 4 3 2 
8 9 8 3 4 3
8 9 8 + 3 4 3
所以还有一个转移：
if(c[l] == c[r] && l + 1 <= r - 1)
	dp[l][r] = min(dp[l][r],dp[l+1][r-1])；

复杂度：O(n^3)
cf上这样的复杂度是可以的

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 505;

int dp[MAXN][MAXN];
int c[MAXN];
bool is[MAXN][MAXN];

bool judge(int l,int r)
{
	while(l < r){
		if(c[l] != c[r])
			return false;
		l++;
		r--;
	}
	return true;
}

void solve(int n)
{
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			is[i][j] = judge(i,j);
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=i;j<=n;j++)
	//		printf("%d %d %d\n",i,j,is[i][j]);
	//}

	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r = l + len - 1;
			dp[l][r] = MAXN;

			if(is[l][r])
				dp[l][r] = 1;
			else{
				for(int k=l;k<r;k++){
					dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]);
				}
				if(c[l] == c[r] && r - l >1){
					dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	solve(n);

	return 0;
}
