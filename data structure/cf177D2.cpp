                                            
  //File Name: cf177D2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月29日 星期二 18时07分18秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN];
int b[MAXN];
int pre[MAXN];
int post[MAXN];
int C;

void solve(int N,int M){
	pre[0] = 0;
	for(int i=1;i<=M;i++){
		pre[i] = (pre[i-1] + b[i]) % C;
	}
	post[M+1] = 0;
	for(int i=M;i>0;i--){
		post[i] = (post[i+1] + b[i]) % C;
	}
	if(2 * M > N){
		for(int i=1;i<=N-M+1;i++)
			a[i] = (a[i] + pre[i]) % C;
		for(int i=N-M+2;i<M;i++)
			a[i] = (a[i] + pre[i] - pre[M + i - N - 1] + C) % C;
		for(int i=M;i<=N;i++)
			a[i] = (a[i] + post[i+M-N]) % C;
	}
	else{
		for(int i=1;i<=M;i++)
			a[i] = (a[i] + pre[i]) % C;
		for(int i=N-M+1;i<=N;i++)
			a[i] = (a[i] + post[i-N+M]) % C;
		for(int i=M+1;i<=N-M;i++)
			a[i] = (a[i] + pre[M]) % C;
	}
	for(int i=1;i<N;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[N]);
	return ;
}

int main(){
	int N,M;
	while(~scanf("%d %d %d",&N,&M,&C)){
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=M;i++)
			scanf("%d",&b[i]);
		solve(N,M);
	}
	return 0;
}
