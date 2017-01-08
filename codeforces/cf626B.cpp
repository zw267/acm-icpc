                                            
  //File Name: cf626B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月15日 星期一 16时08分49秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 203;

int dp[MAXN][MAXN][MAXN];
char str[MAXN];

void solve(int n)
{
	int b = 0,g = 0,r = 0;
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++){
		if(str[i] == 'R')
			r++;
		else if(str[i] == 'B')
			b++;
		else
			g++;
	}
	dp[n][b][g] = 1;
	//printf("%d %d\n",b,g);
	for(int i=n;i>=1;i--){
		for(int b=0;b<=i;b++){
			for(int g=0;g+b<=i;g++){
				if(dp[i][b][g] == 0)
					continue;
				//printf("i = %d b = %d g = %d\n",i,b,g);
				r = i - g - b;
				if(b > 0 && g > 0)
					dp[i-1][b-1][g-1] = 1;
				if(b > 0 && r > 0)
					dp[i-1][b-1][g+1] = 1;
				if(r > 0 && g > 0)
					dp[i-1][b+1][g-1] = 1;
				if(b > 1)
					dp[i-1][b - 1][g] = 1;
				if(g > 1)
					dp[i-1][b][g - 1] = 1;
				if(r > 1)
					dp[i-1][b][g] = 1;
			}
		}
	}
	if(dp[1][1][0] == 1)
		printf("B");
	if(dp[1][0][1] == 1)
		printf("G");
	if(dp[1][0][0] == 1)
		printf("R");
	puts("");
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	solve(n);
	return 0;	
}
