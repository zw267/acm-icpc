                                            
  //File Name: cf128C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月29日 星期一 21时28分16秒
                                   
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 1005;
const int MOD = (int)1e9+7;

LL f[MAXN][MAXN];

void solve(int n,int m,int K)
{
	memset(f,0,sizeof f);
	int ma = max(n,m);
	for(int i=1;i<=ma;i++)
		f[i][0] = 1;
	for(int i=2;i<=ma;i++){
		for(int j=1;2*j+1<=i;j++){
			for(int k=2*j-1;k<=i-2;k++){
				(f[i][j] += f[k][j-1] * (i - k - 1) % MOD) %= MOD;
			}
		}
	}

	printf("%d\n",(int)(f[n][K] * f[m][K] % MOD));
	return ;
}

int main()
{
	int n,m,k;
	while(~scanf("%d %d %d",&n,&m,&k)){
		solve(n,m,k);
	}
	return 0;
}
