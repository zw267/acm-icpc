                                            
  //File Name: hdu1709.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 12时56分54秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 105;

int f[MAXN][MAXN * MAXN];
int a[MAXN];
int ans[MAXN * MAXN];

int ab(int x,int y){
	if(x > y)
		return x - y;
	return y - x;
}

void solve(int n,int S){
	memset(f,false,sizeof f);
	f[0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=S;j++){
			if(!f[i][j])
				continue;
			f[i+1][j] |= f[i][j];
			f[i+1][ab(j,a[i+1])] |= f[i][j];
			if(j + a[i+1] <= S)
				f[i+1][j+a[i+1]] |= f[i][j];
		}
	}	
	int tot = 0;
	for(int i=1;i<=S;i++){
		if(!f[n][i])
			ans[tot++] = i;
	}
	printf("%d\n",tot);
	if(tot > 0){
		for(int i=0;i<tot-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[tot-1]);
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		int S = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			S += a[i];
		}
		solve(n,S);
	}
	return 0;
}
