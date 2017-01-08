                                            
  //File Name: cf570E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月16日 星期二 11时51分01秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 503;

LL f[2][MAXN][MAXN];
char s[MAXN][MAXN];
int n,m;

bool ok1(int x)
{
	if(1 <= x && x <= n)
		return true;
	return false;
}

bool ok2(int y)
{
	if(1 <= y && y <= m)
		return true;
	return false;
}

void solve()
{
	memset(f,0,sizeof f);
	if(s[1][1] != s[n][m]){
		puts("0");
		return ;
	}
	f[0][1][n] = 1LL;
	int ma = (n + m - 2) / 2;
	int y1,y2;
	for(int i=0;i<ma;i++){
		for(int x1=1;x1<=n;x1++){
			for(int x2=x1;x2<=n;x2++){
				if(f[i%2][x1][x2] == 0)
					continue;
				y1 = i + 2 - x1;
				y2 = n + m - i - x2;
				if(!ok2(y1) || !ok2(y2))
					continue;
				if(ok2(y1+1) && ok1(x2-1) && s[x1][y1+1] == s[x2-1][y2]){
					(f[(i+1)%2][x1][x2-1] += f[i%2][x1][x2]) %= MOD;
				}
				if(ok2(y1+1) && ok2(y2-1) && s[x1][y1+1] == s[x2][y2-1]){
					(f[(i+1)%2][x1][x2] += f[i%2][x1][x2]) %= MOD;
				}
				if(ok1(x1+1) && ok1(x2-1) && s[x1+1][y1] == s[x2-1][y2]){
					(f[(i+1)%2][x1+1][x2-1] += f[i%2][x1][x2]) %= MOD;
				}
				if(ok1(x1+1) && ok2(y2-1) && s[x1+1][y1] == s[x2][y2-1]){
					(f[(i+1)%2][x1+1][x2] += f[i%2][x1][x2]) %= MOD;
				}
				f[i%2][x1][x2] = 0LL;
			}
		}
	}

	LL ans = 0LL;
	for(int i=1;i<=n;i++){
		ans = (ans + f[ma%2][i][i]) % MOD;
		if((n+m) % 2)
			ans = (ans + f[ma%2][i][i+1]) % MOD;
		//printf("i = %d  %d  %d\n",i,f[ma][i][i],f[ma][i][i+1]);
	}

	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	//int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i] + 1);
	}	
	solve();
	return 0;
}
