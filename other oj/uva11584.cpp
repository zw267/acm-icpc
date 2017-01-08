                                            
  //File Name: uva11584.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 20时48分19秒
                                   


#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1005;

char str[MAXN];
int dp[MAXN];

bool is(int l,int r)
{
	while(l < r){
		if(str[l] != str[r])
			return false;
		l++;
		r--;
	}
	return true;
}

void solve()
{
	int n = strlen(str);
	for(int i=0;i<n;i++)
		dp[i+1] = n;
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(is(j-1,i-1))
				dp[i] = min(dp[i],dp[j-1] + 1);
		}
	}
	printf("%d\n",dp[n]);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",str);
		solve();
	}
	return 0;
}
