                                            
  //File Name: cf396A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月19日 星期五 01时04分06秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 505;
const int MOD = 1e9+7;

int a[MAXN];
LL jie[1000000];
map<int,LL> dive;

void init()
{
	jie[0] = 1LL;
	for(int i=1;i<1000000;i++)
		jie[i] = jie[i-1] * i % MOD;
}

void get_dive(int x)
{
	for(int i=2;i*i<=x;i++){
		while(x % i == 0){
			dive[i]++;
			x /= i;
		}
	}	
	if(x != 1)
		dive[x]++;
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
	if(y == 0 || y == x)
		return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

void solve(int n)
{
	init();
	dive.clear();
	for(int i=1;i<=n;i++){
		get_dive(a[i]);
	}
	LL ans = 1LL;
	map<int,LL>::iterator it;
	for(it=dive.begin();it!=dive.end();it++){
		LL cur = it->second;
		if((it->first) == 1)
			continue;
		//printf("eeeeeee%d %d\n",it->first,it->second);
		ans = ans * comb(cur + n - 1, n - 1) % MOD;
	}
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n);
	}
	return 0;
}
