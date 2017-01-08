                                            
  //File Name: poj3254.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月27日 星期日 09时42分20秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MOD = 1000000000;

LL f[12][1<<12];
int row[12];

void solve(int N,int M){
	memset(f,0,sizeof f);
	int ma = (1<<M);
	for(int j=0;j<ma;j++){
		if(j & row[0] || j & (j << 1))
			continue;
		f[0][j] = 1;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<ma;j++){
			if(j & row[i] || j & (j << 1))
				continue;
			for(int k=0;k<ma;k++){
				if(!f[i-1][k] || j & k)
					continue;
				f[i][j] = (f[i][j] + f[i-1][k]) % MOD;
			}
		}
	}	
	LL ans = 0;
	for(int j=0;j<ma;j++){
		ans = (ans + f[N-1][j]) % MOD;
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	int N,M;
	while(~scanf("%d %d",&N,&M)){
		memset(row,0,sizeof row);
		for(int i=0,u;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&u);
				if(!u){
					row[i] |= (1<<j);
				}
			}
		}
		solve(N,M);
	}
	return 0;
}
