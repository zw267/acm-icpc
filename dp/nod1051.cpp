                                            
  //File Name: nod1051.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月28日 星期六 21时22分03秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 501;

LL b[MAXN],f[MAXN];
int a[MAXN][MAXN];

LL get(int n){
	LL ans = 0;
	f[0] = 0;
	for(int i=1;i<=n;i++){
		f[i] = max(f[i-1],0LL) + b[i];
		if(f[i] > ans) ans = f[i];
	}
	return ans;
}

LL solve(int n,int m){
	LL ans = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) b[j] = 0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++)
				b[k] = b[k] + a[j][k];
			LL now = get(m);
			if(now > ans) ans = now;
		}
	}
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&m,&n)){
		bool flag = false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j] >= 0) flag = true;
			}
		}
		if(!flag) puts("0");
		else printf("%lld\n",solve(n,m));
	}
	return 0;
}
