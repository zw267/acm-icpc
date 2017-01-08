                                            
  //File Name: nod1179.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月13日 星期三 22时51分43秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 50000 + 3;
const int N = 1000000 + 1;
int num[N];

int solve(int n,int ma){
	int now;
	for(int i=ma;i>0;i--){
		now = 0;
		for(int j=i;j<N;j+=i)
			now += num[j];
		if(now > 1)
			return i;
	}
	return -1;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(num,0,sizeof num);
		int u,ma = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&u);
			if(u > ma) 
				ma = u;
			num[u]++;
		}
		printf("%d\n",solve(n,ma));
	}
	return 0;
}
