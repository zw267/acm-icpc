                                            
  //File Name: cf336D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月17日 星期三 20时38分47秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

LL f[MAXN];
LL jie[MAXN << 1];

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
	if(y == 0 || y == x)
		return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD  - 2) % MOD;
}

void init()
{
	jie[0] = 1;
	for(int i=1;i<MAXN * 2;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
}

void solve(int n,int m,int g)
{
	if(m == 0){
		int num_0 = 0,num_1 = 0;
		if(n % 2)
			num_0 = 1;
		else
			num_1 = 1;
		printf("%d\n",g ? num_1:num_0);
		return ;
	}
	init();
	memset(f,0,sizeof f);
	f[0] = (m == 1 ? 1: 0);
	for(int i=0;i<n;i++){
		f[i+1] =((comb(i + m, i) - f[i] + MOD ) % MOD + MOD) % MOD;
	}
	LL ans = f[n];
	if(!g)
		ans = ((comb(n+m,n) - f[n] + MOD) % MOD + MOD) % MOD;
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n,m,g;
	while(~scanf("%d %d %d",&n,&m,&g)){
		solve(n,m,g);
	}
	return 0;
}
