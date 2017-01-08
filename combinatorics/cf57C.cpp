                                            
  //File Name: cf57C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月23日 星期二 21时20分55秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long 

using namespace std;

const int MOD = (int)1e9+7;
const int MAXN = (int)1e5+5;

LL jie[MAXN << 1];

LL qp(LL x, LL y)
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

void init(int n)
{
	jie[0] = 1LL;
	for(int i=1;i<=n;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
}

LL comb(int x,int y)
{
	if(y < 0 || y > x)
		return 0;
	if(y == 0 || y == x)
		return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

void solve(int n)
{
	init(n * 2);
	LL ans = 0LL;
	for(int i=1;i<=n;i++){
		(ans += comb(n - 2 + i, i - 1)) %= MOD;
	}
	ans = (ans * 2 - n + MOD) % MOD;
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		solve(n);
	}
	return 0;
}
