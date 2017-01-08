                                            
  //File Name: hdu5616.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月31日 星期日 00时57分41秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int base = 2000;

int dp[21][4000+100];
int a[21];

void solve(int n)
{
	memset(dp,0,sizeof dp);
	dp[0][0+base] = 1;
	for(int i=1;i<=n;i++){
		for(int j=-2000;j<=2000;j++){
			dp[i][j+base] = dp[i][j+base] | dp[i-1][j+base];
			if(j - a[i] >= -2000)
				dp[i][j+base] = dp[i][j+base] | dp[i-1][j-a[i]+base];
			if(j + a[i] <= 2000)
				dp[i][j+base] = dp[i][j+base] | dp[i-1][j+a[i]+base];
		}
	}

	int q;
	scanf("%d",&q);
	int u;
	for(int i=0;i<q;i++){
		scanf("%d",&u);
		if(u < -2000 || u > 2000)
			puts("NO");
		else{
			if(dp[n][u+base])
				puts("YES");
			else
				puts("NO");
		}
	}
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
