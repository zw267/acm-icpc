                                            
  //File Name: cf285E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月29日 星期四 14时56分32秒

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 1010;
const int MOD = (int)1e9 + 7;
LL f[MAXN][MAXN][2][2],g[MAXN],h[MAXN];
LL c[MAXN][MAXN],jie[MAXN];
void up(LL &x){
	while(x >= MOD) x -= MOD;
}
void solve(int n,int K){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		up(jie[i]=jie[i-1]*i);
	for(int i=0;i<MAXN;i++){
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			up(c[i][j] = c[i-1][j] + c[i-1][j-1]);
	}
	memset(f,0,sizeof f);
	f[0][0][1][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			up(f[i+1][j+1][0][0]+=f[i][j][0][0]);
			up(f[i+1][j+1][0][1]+=f[i][j][0][0]);
//			up(f[i+1][j][1][0]+=f[i][j][0][0]);
			up(f[i+1][j][0][0]+=f[i][j][0][0]);
			up(f[i+1][j+1][1][0]+=f[i][j][0][1]);
			up(f[i+1][j+1][1][1]+=f[i][j][0][1]);
			up(f[i+1][j][1][0]+=f[i][j][0][1]);
			up(f[i+1][j+1][0][1]+=f[i][j][1][0]);
//			up(f[i+1][j][1][0]+=f[i][j][1][0]);
			up(f[i+1][j][0][0]+=f[i][j][1][0]);
			up(f[i+1][j+1][1][1]+=f[i][j][1][1]);
			up(f[i+1][j][1][0]+=f[i][j][1][1]);
		}
	}
	for(int j=0;j<=n;j++)
		g[j] = (f[n][j][1][0]+f[n][j][0][0]) * jie[n-j] % MOD;
//	for(int i=0;i<=n;i++)
//		printf("i = %d g = %lld\n",i,g[i]);
	K = 0;
	for(int i=n;i>=K;i--){
		h[i] = 0;
		for(int j=i+1;j<=n;j++)
			up(h[i] += c[j][i] * h[j] % MOD);
		up(h[i] = g[i] - h[i] + MOD);
	}
//	for(int i=K;i<=n;i++)
//		cout << i << " " << h[i] << endl;
}
int main(){
	int n,K;
	scanf("%d %d",&n,&K);
	solve(n,K);	
	printf("%d\n",(int)h[K]);
	return 0;
}

