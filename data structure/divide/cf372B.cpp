                                            
  //File Name: cf372B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月17日 星期四 19时32分36秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 43;
int a[MAXN][MAXN];
int lef[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
char str[MAXN];
void init(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j] == 1) 
				lef[i][j] = 0;
			else
				lef[i][j] = lef[i][j-1] + 1;
		}
	}
	for(int a=1;a<=n;a++){
		for(int c=a;c<=n;c++){
			for(int b=1;b<=m;b++){
				for(int d=b;d<=m;d++){
					f[a][b][c][d] = f[a][b][c-1][d] + f[a][b][c][d-1] - 
						f[a][b][c-1][d-1];
					int sum = 0,now = c,mi = d - b + 1;
					while(now >= a && lef[now][d]){
						mi = min(mi,lef[now][d]);
						if(!mi) break;
						sum += mi;
						now--;
					}
					f[a][b][c][d] += sum;
				}
			}
		}
	}
}
void solve(int n,int m,int q){
	init(n,m);
	int a,b,c,d;
	while(q--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",f[a][b][c][d]);
	}
}
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str + 1);
		for(int j=1;j<=m;j++)
			a[i][j] = str[j] - '0';
	}
	solve(n,m,q);
	return 0;
}
