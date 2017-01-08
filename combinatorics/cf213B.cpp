                                            
  //File Name: cf213B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月18日 星期四 21时58分03秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 105;
const int MOD = 1e9+7;

LL f[11][MAXN];
LL jie[MAXN];
int a[11];

void init(int n)
{
	jie[0] = 1LL;
	for(int i=1;i<=n;i++)
		jie[i] = jie[i-1] * i % MOD;
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

LL get(int i,int k,bool ok)
{
	if(k == 0)
		return 1;
	if(i == 0){
		if(ok)
			return k == 1;
		else
			return 1;
	}
	LL res = 1;
	for(int j=1;j<k;j++)
		res = res * (i + j) % MOD;
	if(!ok)
		res = res * (i + k) % MOD;
	else
		res = res * i % MOD;
	return res * qp(jie[k],MOD - 2) % MOD;
}

void solve(int n)
{
	init(n);
	a[10] = a[0];
	memset(f,0,sizeof f);
	int sum = 0;
	for(int i=a[1];i<=n;i++)
		f[1][i] = 1;
	for(int j=1;j<10;j++){
		sum += a[j];
		for(int i=sum;i<=n-a[j+1];i++){
			if(f[j][i] == 0)
				continue;
			for(int k=a[j+1];i+k<=n;k++){
				(f[j+1][i+k] += f[j][i] * get(i,k,j+1 == 10) % MOD) %= MOD;
			}
		}
	}
	//for(int j=1;j<=10;j++){
	//	for(int i=1;i<=n;i++)
	//		printf("%d  ",f[j][i]);
	//	puts("");
	//}
	sum += a[10];
	LL ans = 0LL;
	for(int i=sum;i<=n;i++)
		ans = (ans + f[10][i]) % MOD;
	bool flag = false;
	for(int i=1;i<=10;i++)
		if(a[i])
			flag = true;
	if(!flag)
		ans = (ans - 2 + MOD) % MOD;
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<10;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
