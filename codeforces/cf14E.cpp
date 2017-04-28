                                            
  //File Name: cf14E.cpp
  //Created Time: 2017年04月27日 星期四 18时23分54秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int f[21][12][5][2];
int solve(int n,int t){
	f[2][0][2][1] = 1;
	f[2][0][3][1] = 2;
	f[2][0][4][1] = 3;
	for(int i=2;i<n;++i){
		for(int j=0;j<=t;++j){
			for(int k=1;k<=4;++k){
				for(int l=0;l<2;++l){
					if(!f[i][j][k][l]) continue;
					for(int x=1;x<=4;++x){
						if(l == 1 && x > k)
							f[i+1][j][x][1] += f[i][j][k][l];
						if(l == 1 && x < k)
							f[i+1][j+1][x][0] += f[i][j][k][l];
						if(l == 0 && x > k)
							f[i+1][j][x][1] += f[i][j][k][l];
						if(l == 0 && x < k)
							f[i+1][j][x][0] += f[i][j][k][l];
					}
				}
			}
		}
	}
	int res = 0;
	for(int i=1;i<=4;++i)
		res += f[n][t][i][0];
	return res;
}
int main(){
	int n,t;
	cin >> n >> t;
	cout << solve(n,t) << endl;
	return 0;
}
