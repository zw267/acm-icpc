                                            
  //File Name: cf626F.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月20日 星期六 15时33分02秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>

#define LL long long

using namespace std;

const int MOD = 1e9+7;
const int base = 50000;

LL f[2][1010][110];
int a[205];

bool cmp(int x,int y)
{
	return x > y;
}

void solve(int n,int sum)
{
	sort(a+1,a+n+1);
	a[0] = 0;
	memset(f,0,sizeof f);
	f[0][0][0] = 1LL;
	for(int i=0;i<n;i++){
		for(int j=0;j<=sum;j++){
			for(int k=0;k<=min(i,(n+1)/2);k++){
				if(f[i%2][j][k] == 0)
					continue;
				LL cur = f[i%2][j][k];
				int add = k * (a[i+1] - a[i]);
				int u = (i + 1) % 2;
				if(j + add <= sum){
					(f[u][j+add][k+1] += cur) %= MOD;
					(f[u][j+add][k] += cur * (k + 1) % MOD ) %= MOD;
					if(k > 0)
						(f[u][j+add][k-1] += cur * k % MOD) %= MOD;
				}
				f[i%2][j][k] = 0;
			}
		}
	}
	LL ans = 0;
	for(int j=0;j<=sum;j++)
		(ans += f[n%2][j][0]) %= MOD;
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n,k);
	}
	return 0;
}
