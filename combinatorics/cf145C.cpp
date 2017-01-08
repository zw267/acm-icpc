                                            
  //File Name: cf145C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月28日 星期日 11时46分14秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define LL long long

using namespace std;

const int MAXN = (int)1e5+5;
const int MOD = (int)1e9+7;

int a[MAXN];
LL f[1024][1024];
int sum[1024];
LL jie[MAXN];

bool ok(int x)
{
	int cur;
	while(x){
		cur = x % 10;
		if(cur !=4 && cur != 7)
			return false;
		x /= 10;
	}
	return true;
}

void init(int n)
{
	jie[0] = 1;
	for(int i=1;i<=n;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
}

LL qp(LL x,LL y)
{
	LL res = 1;
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

void solve(int n,int K)
{
	init(n);
	memset(sum,0,sizeof sum);
	sort(a+1,a+n+1);
	a[0] = 0;
	int tot = 0;
	int unlucky = 0;
	for(int i=1;i<=n;i++){
		if(ok(a[i])){
			if(a[i] == a[i-1]){
				sum[tot]++;
			}
			else{
				sum[++tot] = 1;
			}
		}
		else
			unlucky++;
	}

	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=1;i<=tot;i++){
		f[i][0] = 1;
		for(int j=1;j<=i;j++){
			f[i][j] = (f[i-1][j] + f[i-1][j-1] * sum[i] % MOD) % MOD;
		}
	}
	//printf("eeeeeeeeeeeee");
	LL ans = 0;
	int ma = min(K,tot);
	for(int j=0;j<=ma;j++){
		(ans += f[tot][j] * comb(unlucky,K-j) % MOD) %= MOD;
	}
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
