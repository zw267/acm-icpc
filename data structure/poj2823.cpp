                                            
  //File Name: poj2823.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月28日 星期一 15时24分21秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1000000 + 5;

int a[MAXN];
int ans_ma[MAXN];
int ans_mi[MAXN];
int deq[MAXN];

void solve(int N,int K){
	int s = 0,t = 0;
	for(int i=0;i<N;i++){
		while(s < t && a[deq[t-1]] < a[i]){
			t--;
		}
		deq[t++] = i;
		if(i - K + 1 >= 0)
			ans_ma[i] = a[deq[s]];
		if(deq[s] + K -1 == i)
			s++;
	}
	s = t = 0;
	for(int i=0;i<N;i++){
		while(s < t && a[deq[t - 1]] > a[i])
			t--;
		deq[t++] = i;
		if(i - K + 1 >= 0)
			ans_mi[i] = a[deq[s]];
		if(deq[s] + K - 1 == i)
			s++;
	}
	for(int i=K-1;i<N;i++){
		printf("%d",ans_mi[i]);
		if(i == N - 1)
			puts("");
		else
			printf(" ");
	}
	for(int i=K-1;i<N;i++){
		printf("%d",ans_ma[i]);
		if(i == N - 1)
			puts("");
		else
			printf(" ");
	}
	return ;
}

int main(){
	int N,K;
	while(~scanf("%d %d",&N,&K)){
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
		}
		solve(N,K);
	}
	return 0;
}
