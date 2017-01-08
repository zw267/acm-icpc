                                            
  //File Name: cf429C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月13日 星期四 13时57分02秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
bool f[14][1<<14][25];
int s[1<<14],num[1<<14];
int a[25];
bool cmp(int x,int y){
	return x > y;
}
void update(int i,int j,int k,int tot){
	for(int u=0;u<(1<<tot);u++){
		if(!(j & u)){
			int v = a[i] - 1 - s[u];
			if(v >= 0 && v <= k){
				if(v + num[u] > 1)
					f[i+1][j|u][k-v] = true;
			}
		}
	}
}
bool solve(int n,int lef,int tot){
	if(n == 1 && lef == 1) return true;
	sort(a,a+tot,cmp);
	if(lef < n / 2 || lef == n || a[0] != n) return false;
	for(int i=0;i<(1<<tot);i++){
		for(int j=0;j<tot;j++){
			if(i & (1<<j)){
				s[i] += a[j];
				num[i]++;
			}
		}
	}
	f[0][1][lef] = true;
	for(int i=0;i<tot;i++){
		for(int j=1;j<(1<<tot);j++){
			for(int k=0;k<=lef;k++){
				if(f[i][j][k])
					update(i,j,k,tot);
			}
		}
	}	
	return f[tot][(1<<tot)-1][0];
}
int main(){
	int n,lef = 0,tot = 0;
	scanf("%d",&n);
	for(int i=0,u;i<n;i++){
		scanf("%d",&u);
		if(u == 1) lef++;
		else a[tot++] = u;
	}
	if(solve(n,lef,tot)) puts("YES");
	else puts("NO");
	return 0;
}
