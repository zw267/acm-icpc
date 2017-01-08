                                            
  //File Name: nod1086.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月16日 星期六 17时14分14秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 101;

int f[2][50000 + 1];
int w[MAXN],p[MAXN],c[MAXN];
int v[800],val[800];

int solve(int n,const int m){
	int tot = 0;
	for(int i=1;i<=n;i++){
		int now = 1;
		while(c[i] >= now){
			v[++tot] = now * w[i];
			val[tot] = now * p[i];
			c[i] -= now;
			now *= 2;
		}
		if(c[i]){
			v[++tot] = c[i] * w[i];
			val[tot] = c[i] * p[i];
		}
	}
	//for(int i=1;i<=tot;i++){
	//	printf("v = %d val = %d\n",v[i],val[i]);
	//}
	memset(f,0,sizeof f);
	for(int i=1;i<=tot;i++){
		for(int j=m;j>=0;j--){
			f[i%2][j] = max(f[(i+1)%2][j],f[i%2][j]);
			if(j >= v[i])
				f[i%2][j] = max(f[i%2][j],f[(i+1)%2][j-v[i]] + val[i]);
		}
	}
	return f[tot%2][m];
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i =1;i<=n;i++)
			scanf("%d %d %d",&w[i],&p[i],&c[i]);
		printf("%d\n",solve(n,m));
	}
	return 0;
}
