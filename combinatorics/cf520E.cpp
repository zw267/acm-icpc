                                            
  //File Name: cf520E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月14日 星期日 12时55分30秒
                                   
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

LL jie[MAXN];
LL f[10][MAXN];
int num[10];
int s[MAXN];
char str[MAXN];

void init(int n)
{
	for(int i=0;i<10;i++)
		f[i][0] = i;
	for(int j=1;j<=n;j++){
		for(int i=0;i<10;i++){
			f[i][j] = f[i][j-1] * 10LL % MOD;
		}
	}
	jie[0] = 1;
	for(int i=1;i<=n;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
}

LL qp(LL x,LL y)
{
	LL res = 1LL;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL comb(int x,int y)
{
	if(y < 0 || y > x)
		return 0;
	if(y ==0 || y == x)
		return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

void solve(int n,int k)
{
	init(n);
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++){
		s[i] = str[i-1] -'0';
		num[s[i]]++;
	}
	LL ans = 0LL;
	for(int j=0;j<n-k;j++){
		num[s[n-j]]--;
		LL cur = comb(n-2-j,k-1);
		if(cur <= 0)
			continue;
		for(int i=1;i<10;i++){
			ans = (ans + f[i][j] * num[i] % MOD *cur % MOD) % MOD;
		}
	}
	for(int j=0;j<n-k;j++){
		ans = (ans + f[s[n-j]][j] * comb(n-1-j,k) % MOD) % MOD;
	}
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n,k;
	scanf("%d %d %s",&n,&k,str);
	solve(n,k);
	return 0;
}
