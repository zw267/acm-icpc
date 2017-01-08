                                            
  //File Name: cf167B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月23日 星期六 11时44分11秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <map>

#define fir first
#define sec second
#define pid pair<int,double>

using namespace std;

const int MAXN = 202;

double f[MAXN][MAXN][MAXN];
pid a[MAXN];

bool cmp(pid x,pid y){
	if(x.fir == y.fir)
		return x.sec < y.sec;
	return x.fir > y.fir;
}

double solve(int N,int L,int K){
	sort(a+1,a+N+1,cmp);
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++)
			for(int k=0;k<MAXN;k++)
				f[i][j][k] = 0.0;
	}
	f[0][0][K] = 1.0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<MAXN;k++){
				if(f[i][j][k] == 0.0)
					continue;
				f[i+1][j][k] += f[i][j][k] * (1.0 - a[i+1].sec);
				if(a[i+1].fir == -1 && k > 0)
					f[i+1][j+1][k-1] += f[i][j][k] * a[i+1].sec;
				else if(a[i+1].fir > 0)
					f[i+1][j+1][min(201,k+a[i+1].fir)] += f[i][j][k] * a[i+1].sec;
			}
		}
	}
	double ans = 0.0;
	for(int j=L;j<=N;j++){
		//ans = 0.0;
		for(int k=0;k<MAXN;k++)
			ans += f[N][j][k];
		//printf("int i = %d ans = %.3f\n",j,ans);
	}
	return ans;
}

int main(){
	int N,L,K;
	while(~scanf("%d %d %d",&N,&L,&K)){
		for(int i=1,u;i<=N;i++){
			scanf("%d",&u);
			a[i].sec = (u + 0.0) / 100.0;
		}
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i].fir);
		}
		printf("%.8f\n",solve(N,L,K));
	}
	return 0;
}
