                                            
  //File Name: hdu1028.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 12时38分20秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 125;

int f[MAXN][MAXN];

void init(){
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=0;i<120;i++){
		for(int j=0;j<=120;j++){
			for(int k=0;j+k*(i+1)<=120;k++)
				f[i+1][j+k*(i+1)] += f[i][j];
		}
	}
	return ;
}

void solve(){
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",f[n][n]);
	}
	return ;
}

int main(){
	solve();
	return 0;
}
