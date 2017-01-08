                                            
  //File Name: hdu2152.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 14时47分37秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int f[101];
int g[101];
int l[101];
int r[101];

void init(int N,int M){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=l[1];i<=r[1];i++){
		f[i] = 1;
	}
	for(int i=2;i<=N;i++){
		for(int j=0;j<=M;j++){
			for(int k=l[i];k<=r[i] && k+j<=M;k++)
				g[j+k] += f[j];
		}
		for(int j=0;j<=M;j++){
			f[j] = g[j];
			g[j] = 0;
		}
	}
	return ;
}

void solve(int N,int M){
	init(N,M);
	printf("%d\n",f[M]);
	return ;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d %d",&l[i],&r[i]);
		}
		solve(n,m);
	}
	return 0;
}
