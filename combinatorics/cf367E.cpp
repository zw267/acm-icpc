                                            
  //File Name: cf367E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月12日 星期五 14时33分09秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 320;
LL f[2][MAXN][MAXN];
void up(LL &x){
	if(x >= MOD) x %= MOD;
}
LL solve(int n,int m,int x){
	if(m < n || n >= MAXN - 1) return 0;
	memset(f,0,sizeof f);
	f[0][0][0] = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=i && j <= n;j++){
			for(int k=0;k<=j;k++){
				if(i + 1 != x){
					if(j > k) up(f[(i+1)&1][j][k+1] += f[i&1][j][k]);
					up(f[(i+1)&1][j+1][k] += f[i&1][j][k]);
					up(f[(i+1)&1][j+1][k+1] += f[i&1][j][k]);
					up(f[(i+1)&1][j][k] += f[i&1][j][k]);
				}
				else{
					up(f[(i+1)&1][j+1][k] += f[i&1][j][k]);
					up(f[(i+1)&1][j+1][k+1] += f[i&1][j][k]);
				}
				f[i&1][j][k] = 0;
			}
		}
	}
	LL ans = f[m&1][n][n];
	for(int i=2;i<=n;i++) up(ans *= i);
	return ans;
}
int main(){
	int n,m,x;
	cin >> n >> m >> x;
	cout << solve(n,m,x) << endl;
	return 0;
}
