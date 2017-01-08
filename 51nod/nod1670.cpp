                                            
  //File Name: nod1670.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月26日 星期六 10时35分37秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

#define LL long long 

using namespace std;

const int MAXN = 100000+5;
const int MOD = 1e9+7;

int num[MAXN];
int a[MAXN];
LL cur[MAXN];
LL jc[MAXN];

void init()
{
	jc[0] = jc[1] = 1;
	for(int i=2;i<MAXN;i++)
		jc[i] = jc[i-1] * i % MOD;
}

void solve(int n)
{
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++){
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		num[i] += num[i-1];
	}

	cur[1] = 1;
	for(int i=2;i<=n;i++){
		cur[i] = cur[i-1] * (num[i-2] - i + 2) % MOD;
	}

	LL res = 0;
	for(int i=2;i<=n;i++){
		res = (res + (i - 1) * cur[i] % MOD * (n - num[i-1]) % MOD * jc[n - i] % MOD) % MOD;
	}
	res = (res + n * cur[n] % MOD) % MOD;

	printf("%lld\n",res);
	return ;
}

int main()
{
	init();
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}

