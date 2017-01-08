                                            
  //File Name: nod1672.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月15日 星期五 10时51分52秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

#define LL long long

using namespace std;

const int MAXN = 100000 + 2;

struct Line{
	int l,r;
	bool operator<(const Line &x) const{
		if(x.r == r)
			return x.l < l;
		return x.r < r;
	}
}line[MAXN];

int a[MAXN];
LL sum[MAXN];

bool cmp(Line x,Line y){
	if(x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

LL solve(int N,int K,int M){
	sort(line+1,line+M+1,cmp);
	sum[0] = 0;
	for(int i=1;i<=N;i++)
		sum[i] = sum[i-1] + a[i];
	int l = 0,r = 0,iter = 1;
	LL ans = 0;
	priority_queue<Line> que;
	while(iter <= M && l <= N){
		while(iter <= N && line[iter].l <= l){
			que.push(line[iter++]);
		}
		while(!que.empty() && que.top().r < r)
			que.pop();
		if(que.size() >= K){
			ans = max(ans,sum[r] - sum[l - 1]);
			if(r < N) r++;
			else break;
		}
		else{
			l++;
			if(r < l) r = l;
		}
	}
	return ans;
}

int main(){
	int N,K,M;
	while(~scanf("%d %d %d",&N,&K,&M)){
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=M;i++)
			scanf("%d %d",&line[i].l,&line[i].r);
		printf("%lld\n",solve(N,K,M));
	}
	return 0;
}
