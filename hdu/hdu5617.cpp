                                            
  //File Name: hdu5617.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月31日 星期日 01时59分02秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 505;
const int MOD = 5201314;

char a[MAXN][MAXN];
LL dp1[MAXN][MAXN];
LL dp2[MAXN][MAXN];
int N;

bool is(int x)
{
	if(1 <= x && x <= N)
		return true;
	return false;
}

void solve()
{
	memset(dp1,0,sizeof dp1);
	memset(dp2,0,sizeof dp2);
	if(a[1][1] != a[N][N]){
		puts("0");
		return ;
	}
	dp1[1][1] = 1;
	dp2[N][N] = 1;
	for(int len=0;len<N;len++){
		for(int i=1;i<=N;i++){
			int ii = len+2-i;
			if(!is(ii))
				continue;
			for(int j=N;j>0;j--){
				int jj = 2*N-len-j;
				if(!is(jj))
					continue;
				if(dp1[i][ii] == 0 || dp2[j][jj] == 0)
					continue;
				LL cnt = dp1[i][ii] * dp2[j][jj] % MOD;
				if(is(ii+1) && is(jj-1) && a[i][ii+1] == a[j][jj-1]){
					dp1[i][ii+1] = (dp1[i][ii+1] + cnt) % MOD;
					dp2[j][jj-1] = (dp2[j][jj-1] + cnt) % MOD;
				}
				if(is(ii+1) && is(j-1) && a[i][ii+1] == a[j-1][jj]){
					dp1[i][ii+1] = (dp1[i][ii+1] + cnt) % MOD;
					dp2[j-1][jj] = (dp2[j-1][jj] + cnt) % MOD;
				}
				if(is(i+1) && is(jj-1) && a[i+1][ii] == a[j][jj-1]){
					dp1[i+1][ii] = (dp1[i+1][ii] + cnt) % MOD;
					dp2[j][jj-1] = (dp2[j][jj-1] + cnt) % MOD;
				}
				if(is(i+1) && is(j-1) && a[i+1][ii] == a[j-1][jj]){
					dp1[i+1][ii] = (dp1[i+1][ii] + cnt) % MOD;
					dp2[j-1][jj] = (dp2[j-1][jj] + cnt) % MOD;
				}
			}
		}
	}
	int res = 0;
	
	for(int i=1;i<=N;i++){
		res = (res + dp1[i][N+1-i]) % MOD;
		printf("%d\n",(int)dp1[i][N+1-i]);
	}

	printf("%d\n",res);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			scanf("%s",a[i]+1);
		}
		solve();
	}
	return 0;
}
