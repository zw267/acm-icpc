                                            
  //File Name: cf119C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月13日 星期四 17时31分40秒

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#define LL long long
using namespace std;
LL f[52][52][102],val[52];
int ans[52],pre1[52][52][102],pre2[52][52][102],A;
struct Node{
	LL a,b;
	int c,t;
	bool operator <(const Node& x) const{
		return c < x.c;
	}
}node[52];
void solve(int n,int m){
	sort(node+1,node+m+1);
	for(int j=1;j<=m;j++){
		for(int k=0;k<=node[j].b-node[j].a;k++){
			f[1][j][k] = k + node[j].a;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			for(int k=0;k<=100;k++){
				if(!f[i][j][k]) continue;
				for(int l=j+1;l<=m;l++){
					if(node[j].c >= node[l].c) continue;
					LL x;
					for(int t=1;t<=2;t++){
						if(t == 1) x = node[j].a + k + A;
						else x = (node[j].a + k) * A;
						if(node[l].a <= x && x <= node[l].b){
							if(f[i][j][k] + x > f[i+1][l][x-node[l].a]){
								f[i+1][l][x-node[l].a] = f[i][j][k]+x;
								pre1[i+1][l][x-node[l].a] = j;
								pre2[i+1][l][x-node[l].a] = k;
							}
						}
					}
				}
			}
		}
	}
	LL sum = 0;
	int u = -1,v = -1;
	for(int j=1;j<=m;j++)
		for(int k=0;k<=100;k++){
			if(f[n][j][k] > sum){
				sum = f[n][j][k];
				u = j,v = k;
			}
		}
	if(sum == 0){
		puts("NO");
		return ;
	}
	for(int i=n;i>0;i--){
		ans[i] = node[u].t;
		val[i] = node[u].a + v;
		int preu = pre1[i][u][v];
		v = pre2[i][u][v];
		u = preu;
	}
	puts("YES");
//	cout << sum << endl;
	for(int i=1;i<=n;i++)
		cout << ans[i] << " " << val[i] << endl;
}
int main(){
	int n,m;
	scanf("%d %d %d",&n,&m,&A);
	for(int i=1;i<=m;i++){
		cin >> node[i].a >> node[i].b >> node[i].c;
		node[i].t = i;
	}
	solve(n,m);
	return 0;
}


