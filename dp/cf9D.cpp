                                            
  //File Name: cf9D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月05日 星期二 23时03分05秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 36;

LL f[MAXN][MAXN][MAXN];

void init(){
	memset(f,0,sizeof f);
	f[1][1][1] = 1LL;
	f[0][0][0] = 1LL;
	for(int k=2;k<MAXN;k++){
		for(int i=k;i<MAXN;i++){
			for(int j=1;j<=i;j++){
				for(int ls=0;ls<=j-1;ls++){
					for(int rs = 0;rs<=i - j;rs++){
						f[k][i][j] = f[k-1][j-1][ls] * f[1][i-j][rs] +
							f[1][j-1][ls] * f[k-1][i-j][rs] -
							f[k-1][j-1][ls] * f[k-1][i-j][rs];
					}
				}
			}
		}
	}
}

int main(){
	init();
	int n,h;
	while(~scanf("%d %d",&n,&h)){
		LL ans = 0;
		for(int i=1;i<=n;i++){
			ans += f[h][n][i];
		}
		cout << ans << endl;
	}
	return 0;
}
