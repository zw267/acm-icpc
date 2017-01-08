//基本组合计数
//假设还有一个箱子，用来放没有放入前n个箱子的球
//对于红球，有comb(n+a,a)种方法
//篮球的放法与红球的放法没有关系，同样有comb（n+b,b)种
//则一共有comb(n+a,a) * comb(n+b,b)种
//注意，这道题会爆long long ,要用unsigned long long
//注意：提交代码的时候，记得把自己的debug时候的输出注释掉


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define ULL unsigned long long

using namespace std;

ULL dp[36][36];

void init()
{
	//memset(dp,0,sizeof dp);

	dp[0][0] = 1;
	for(int i=1;i<36;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	}
	//for(int i=0;i<35;i++){
	//	for(int j=0;j<=i;j++)
	//		printf("%llu\n",dp[i][j]);
	//}
}

ULL solve(int n,int a,int b)
{
	return dp[n+a][a] * dp[n+b][b];
}

int main()
{
	init();
	int n,a,b;
	while(~scanf("%d %d %d",&n,&a,&b)){
		cout << solve(n,a,b) << endl;
	}
	return 0;
}
