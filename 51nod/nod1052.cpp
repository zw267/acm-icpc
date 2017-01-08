                                            
  //File Name: nod1052.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月14日 星期二 10时08分34秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int  MAXN = 5000 + 1;
const int INF = 0x3f3f3f3f;

LL f[MAXN][2];
int a[MAXN];
LL sum[MAXN];

void solve(int n,int m){
	sum[0] = 0;
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + a[i];
	if(m > n) m = n;
	for(int i=0;i<=n;i++)
		f[i][0] = 0,f[i][1] = -INF;
		
	for(int j=1;j<=m;j++){
		LL now = j == 1? 0 : -INF;
		for(int i=1;i<=n;i++){
			f[i][j%2] = max(f[i-1][j%2],now + sum[i]);
			//printf("i = %d j = %d f = %lld now = %lld\n",i,j,f[i][j%2],now);
			now = max(now,f[i][(j+1)%2] - sum[i]);	
		}
	}
	//while(true){
	//	int u,v;
	//	scanf("%d %d",&u,&v);
	//	printf("%lld\n",f[u][v]);
	//}
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n,m);
		printf("%lld\n",f[n][m%2]);
	}
	return 0;
}
