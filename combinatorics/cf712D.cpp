                                            
  //File Name: cf712D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月15日 星期六 23时16分47秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 200000 + 10;
const int MOD = (int)1e9 + 7;
LL f[MAXN],g[MAXN];
int a,b,k,t;
LL solve(){
	int ma = 2 * k * t;
	for(int i=0;i<=ma;i++) g[i] = 1;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=ma;j++){
			int u = j - 2 * k;
			if(u <= 0) f[j] = g[j];
			else f[j] = (g[j] - g[u - 1] + MOD) % MOD;
		}
		g[0] = f[0];
		for(int j=1;j<=ma;j++)
			g[j] = (g[j-1] + f[j]) % MOD;
	}
	LL ans = 0;
//	printf("ma = %d\n",ma);
//	for(int i=0;i<=ma;i++)
//		printf("i = %d f = %dg = %d\n",i,f[i],g[i]);
	for(int i=max(b-a+1,0);i<=ma;i++){
		int u = i - (b - a + 1);
		if(u < 0) continue;
		ans = (ans + f[i] * g[min(ma,u)] % MOD) % MOD;
	}
	return ans;
}
int main(){
	scanf("%d %d %d %d",&a,&b,&k,&t);
	cout << solve() << endl;
	return 0;
}
