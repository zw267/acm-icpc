                                            
  //File Name: bc67A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月26日 星期六 19时44分18秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000000+5;

int dp[MAXN];
int a[MAXN];

void solve(int n)
{
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		if((dp[i-1] + a[i-1]) % 2 == 0){
			dp[i] = 1;
		}
		else
			dp[i] = 2;
	}

	if((dp[n] + a[n])% 2 == 0)
		puts("YES");
	else
		puts("NO");
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n);
	}
	return 0;
}
