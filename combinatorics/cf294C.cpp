                                            
  //File Name: cf294C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月09日 星期六 00时47分38秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

#define LL long long
#define fir first
#define sec second
#define mp make_pair
#define pil pair<int,LL>

using namespace std;

const int MAXN = 1000 + 3;
const int MOD = (int)1e9 + 7;

LL p[MAXN],f[MAXN][MAXN];
pil b[MAXN];
int a[MAXN];

void init(){
	p[0] = 1;
	for(int i=1;i<MAXN;i++)
		p[i] = p[i-1] * 2 % MOD;
	memset(f,0,sizeof f);
	for(int i=0;i<MAXN;i++){
		f[i][0] = 1;
		for(int j=1;j<=i;j++){
			f[i][j] = (f[i-1][j] + f[i-1][j-1]) % MOD;
		}
	}
}

LL get(int x,int y){
	x++,y--;
	LL ans = 0;
	for(int j=0;j<x;j++){
		ans = (ans + f[x][j+1] * f[y][j] % MOD) % MOD;
	}
	return ans;
}

LL solve(int n,int m){
	if(n == m) 
		return 1;
	int tot = 0;
	int len = 0;
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(flag && len)
				b[tot++] = mp(len,p[len-1]);
			else if(len)
				b[tot++] = mp(len,1);
			len = 0;
			flag = true;
		}
		else{
			len++;
		}
	}
	if(len)
		b[tot++] = mp(len,1);
	LL ans = b[0].sec;
	int now_len = b[0].fir;
	for(int i=1;i<tot;i++){
		ans = ans * b[i].sec % MOD * get(now_len,b[i].fir) % MOD;
		now_len += b[i].fir;
	}
	//cout << now_len << endl;
	return ans;
}

int main(){
	init();
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		memset(a,0,sizeof a);
		int u;
		for(int i=0,u;i<m;i++){
			scanf("%d",&u);
			a[u] = 1;
		}
		printf("%d\n",(int)solve(n,m));
	}
	return 0;
}

