                                            
  //File Name: cf123C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月20日 星期三 08时44分03秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#define LL unsigned long long
#define fir first
#define sec second
#define pii pair<int,int>

using namespace std;

const LL INF = 1000000000000000001;

char c[202],ans[102][102];
int p[202],pri[102][102];
LL f[202][202];
pii tmp[202];

void up(LL &x,LL y){
	if(y >= INF)
		x = INF;
	else if(x >= INF - y)
		x = INF;
	else
		x += y;
}

void solve(int n,int m,LL K){
	int ma = n + m;
	for(int i=1,x,y,u;i<ma;i++){
		if(i <= m)
			x = 1,y = i;
		else
			x = i - m  + 1, y = m;
		tmp[i] = make_pair(pri[x][y],i);
		while(x < n && y > 1){
			x++,y--;
			tmp[i].fir = min(tmp[i].fir,pri[x][y]);
		}
	}
	sort(tmp+1,tmp+ma);
	int tot = 0;
	for(int i=1;i<ma;i++)
		tmp[i].fir = ++tot;
	for(int i=1;i<ma;i++)
		p[tmp[i].fir] = tmp[i].sec;
	for(int i=0;i<ma;i++)
		c[i] = '*';
	for(int k=1;k<ma;k++){
		c[p[k]] = '(';
		memset(f,0,sizeof f);
		f[0][0] = 1;
		for(int i=1;i<ma;i++){
			for(int j=0;j<=i;j++){
				if(c[i] == '('){
					if(j > 0)
						f[i][j] = f[i-1][j-1];
				}
				else if(c[i] == ')')
					f[i][j] = f[i-1][j+1];
				else{
					f[i][j] = f[i-1][j+1];
					if(j > 0)
						up(f[i][j],f[i-1][j-1]);
				}
			}
		}
		if(f[ma-1][0] >= K)
			c[p[k]] = '(';
		else{
			c[p[k]] = ')';
			K -= f[ma-1][0];
		}
	}
	//for(int i=1;i<ma;i++)
	//	printf("%c  ",c[i]);
	for(int i=1,x,y;i<ma;i++){
		if(i <= m)
			x = 1,y = i;
		else
			x = i - m + 1,y = m;
		ans[x][y] = c[i];
		while(x < n && y > 1){
			x++,y--;
			ans[x][y] = c[i];
		}
	}
}

int main(){
	int n,m;
	LL k;
	while(cin >> n >> m >> k){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&pri[i][j]);
		solve(n,m,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%c",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}

