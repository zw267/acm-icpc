                                            
  //File Name: poj3311.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月27日 星期日 18时50分19秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int f[11][1<<11];
int d[11][11];

void solve(int N){
	for(int k=0;k<=N;k++){
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	int ma = 1 << (N+1);
	for(int j=0;j<ma;j++)
		for(int i=0;i<=N;i++)
			f[i][j] = INF;
	f[0][1] = 0;
	for(int j=1;j<ma;j++){
		if((j & 1) == 0)
			continue;
		for(int i=1;i<=N;i++){
			if((j & (1 << i)) == 0)
				continue;
			int cur = j ^ (1 << i);
			for(int k=0;k<=N;k++){
				if(cur & (1 << k)){
					f[i][j] = min(f[i][j],f[k][cur] + d[k][i]);
				}
			}
		}
	}
	int ans = INF;
	for(int i=1;i<=N;i++){
		ans = min(ans,f[i][ma - 1] + d[i][0]);
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int N;
	while(~scanf("%d",&N)){
		if(!N)
			break;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				scanf("%d",&d[i][j]);
			}
		}
		solve(N);
	}
	return 0;
}
