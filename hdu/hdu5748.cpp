                                            
  //File Name: hdu5748.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月25日 星期一 20时43分17秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 3;
const int INF = 0x3f3f3f3f;

int a[MAXN],f[MAXN],g[MAXN];

int get(int r,int x){
	if(g[r] < x){
		g[r + 1] = x;
		return r + 1;
	}
	int l = 0,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(g[mid] < x)
			l = mid;
		else
			r = mid;
	}
	g[l + 1] = x;
	return l + 1;
}

void solve(int n){
	for(int i=1;i<=n;i++)
		g[i] = INF;
	g[0] = 0;
	for(int i=1,u;i<=n;i++){
		u = get(i,a[i]);
		f[i] = u;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n);
		for(int i=1;i<=n;i++){
			printf("%d",f[i]);
			if(i == n) puts("");
			else printf(" ");
		}
	}
	return 0;
}
