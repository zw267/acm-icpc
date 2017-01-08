                                            
  //File Name: fzu2214.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月04日 星期五 23时47分49秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int INF = 0x3f3f3f3f;

LL f[505][5005];
LL w[505];
int v[505];

void solve(int n,LL B,int sum)
{
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++)
			f[i][j] = INF;
	}
	sum = 0;
	f[0][0] = 0;
	for(int i=1;i<=n;i++){
		sum += v[i];
		for(int j=0;j<=sum;j++){
			f[i][j] = f[i-1][j];
			if(j >= v[i]){
				f[i][j] = min(f[i][j],f[i-1][j-v[i]]+w[i]);
			}
		}
	}
	int ans = 0;
	for(int j=0;j<=sum;j++){
		if(f[n][j] <= B)
			ans = max(ans,j);
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n,sum = 0;
		LL B;
		scanf("%d %I64d",&n,&B);
		for(int i=1;i<=n;i++){
			scanf("%I64d %d",&w[i],&v[i]);
			sum += v[i];
		}
		solve(n,B,sum);
	}
	return 0;
}
