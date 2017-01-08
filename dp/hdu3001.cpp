                                            
  //File Name: hdu3001.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月27日 星期日 19时46分01秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const LL INF = 0x3f3f3f3f3f3f3f3f;

LL f[10][1<<10];
LL d[10][10];

void solve(int N){
	int ma = 1 << N;
	for(int i=0;i<N;i++){
		for(int j=0;j<ma;j++)
			f[i][j] = INF;
	}
	for(int i=0;i<N;i++){
		f[i][1<<i] = 0;
	}
	for(int j=1;j<ma;j++){
		for(int i=0;i<N;i++){
			if(j & (1 << i) == 0)
				continue;
			int cur = j ^ (1 << i);
			for(int k=0;k<N;k++){
				if(cur & (1 << k) && f[k][cur] < INF && d[k][i] < INF){
					f[i][j] = min(f[i][j],f[k][cur] + d[k][i]);
				}
			}
		}
	}
	LL ans = INF;
	for(int i=0;i<N;i++){
		ans = min(ans,f[i][ma - 1]);
	}
	if(ans >= INF)
		puts("-1");
	else
		printf("%lld\n",ans);
	return ;
}

int main(){
	int N,M;
	while(~scanf("%d %d",&N,&M)){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(i == j)
					d[i][j] = 0;
				else
					d[i][j] = INF;
			}
		for(int i=0,u,v,w;i<M;i++){
			scanf("%d %d %d",&u,&v,&w);
			u--;
			v--;
			d[u][v] = min(d[u][v],(LL)w);
			d[v][u] = min(d[v][u],(LL)w);
		}
		solve(N);
	}
	return 0;
}
