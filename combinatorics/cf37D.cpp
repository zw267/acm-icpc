                                            
  //File Name: cf37D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月13日 星期六 21时03分56秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 1005;
LL f[110][MAXN],c[MAXN][MAXN],jie[MAXN];
int x[110],s[110],y[110];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
LL solve(int m){
	c[0][0] = 1;
	for(int i=1;i<MAXN;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
	}
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		jie[i] = jie[i-1] * i % MOD; 
	s[0] = 0;
	for(int i=1;i<=m;i++)
		s[i] = s[i-1] + x[i];
	f[0][0] = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=s[i];j++){
			if(f[i][j] == 0) continue;
			for(int k=0;k<=min(y[i+1],s[i+1]-j);k++){
				(f[i+1][j+k] += f[i][j] * c[s[i+1]-j][k] % MOD) %= MOD;
			}
		}
	}
	//cout << f[m][s[m]] << endl;
	LL ans = f[m][s[m]] * jie[s[m]] % MOD;
	//cout << ans << endl;
	for(int i=1;i<=m;i++)
		ans = ans * qp(jie[x[i]],MOD - 2) % MOD;
	return ans;
}
int main(){
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	cout << solve(m) << endl;
	return 0;
}
