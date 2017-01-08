                                            
  //File Name: cf507D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月06日 星期三 00时34分23秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

LL f[1001][101][2];
LL pk[1001];
LL pm[1001];
int K,M;

void init(int n){
	pk[0] = 1 % K;
	pm[0] = 1 % M;
	for(int i=1;i<=n;i++){
		pk[i] = (pk[i-1] * 10) % K;
		pm[i] = (pm[i-1] * 10) % M;
	}
}

void up(LL &x){
	x = x % M;
}

void solve(int n){
	init(n);
	memset(f,0,sizeof f);
	for(int j=1;j<10;j++)
		f[1][j%K][0]++;
	for(int i=2;i<=n;i++){
		for(int j=1;j<10;j++){
			f[i][j * pk[i-1]%K][0]++;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<K;j++){
			for(int h=0;h<2;h++){
				if(!f[i][j][h])
					continue;
				up(f[i+1][j][1] += f[i][j][h]);
				for(int l=1;l<10;l++){
					int cur = (l * pk[i] + j) % K;
					up(f[i+1][cur][0] += f[i][j][h]);
				}
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	cout << f[i][0][0] << endl;
	//}
	LL ans = 0;
	for(int i=1;i<n;i++){
		up(ans += f[i][0][0] * pm[n-i-1] % M * 9 % M);
	}
	up(ans += f[n][0][0]);
	cout << ans << endl;
}

int main(){
	int n;
	cin >> n >> K >> M;
	solve(n);
	return 0;
}
