                                            
  //File Name: poj1742.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月28日 星期一 20时57分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000 + 5;

bool f[MAXN];
bool deqv[MAXN];
int deq[MAXN];
int v[105];
int c[105];

void solve(int N,int M){
	memset(f,false,sizeof f);
	f[0] = true;
	for(int i=0;i<N;i++){
		for(int x = 0;x < v[i];x++){
			int s = 0,t = 0;
			for(int j=0;j*v[i] + x <= M;j++){
				bool val = f[j * v[i] + x];
				while(s < t && deqv[t - 1] <= val)
					t--;
				deqv[t] = val;
				deq[t++] = j;
				f[j * v[i] + x] = deqv[s];
				if(deq[s] + c[i] == j)
					s++;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=M;i++){
		if(f[i])
			ans++;
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int N,M;
	while(~scanf("%d %d",&N,&M)){
		if(!N && !M)
			break;
		for(int i=0;i<N;i++){
			scanf("%d",&v[i]);
		}
		for(int i=0;i<N;i++){
			scanf("%d",&c[i]);
		}
		solve(N,M);
	}
	return 0;
}
