                                            
  //File Name: hdu1992.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月05日 星期二 21时13分23秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;

int f[MAXN][16];

void solve(int n){
	memset(f,0,sizeof f);
	f[0][15] = 1;
	for(int i=1;i<=n;i++){
		f[i][0] = f[i-1][15];
		f[i][1] = f[i-1][14];
		f[i][2] = f[i-1][13];
		f[i][3] = f[i-1][12] + f[i-1][15];
		f[i][4] = f[i-1][11];
		f[i][5] = f[i-1][10];
		f[i][6] = f[i-1][15] + f[i-1][9];
		f[i][7] = f[i-1][14] + f[i-1][11] + f[i-1][8];
		f[i][8] = f[i-1][7];
		f[i][9] = f[i-1][6];
		f[i][10] = f[i-1][5];
		f[i][11] = f[i-1][4] + f[i-1][7];
		f[i][12] = f[i-1][3] + f[i-1][15];
		f[i][13] = f[i-1][14] + f[i-1][2];
		f[i][14] = f[i-1][1] + f[i-1][7] + f[i-1][13];
		f[i][15] = f[i-1][15] + f[i-1][0] + f[i-1][12] + f[i-1][6] + f[i-1][3];
	}
	//printf("%d\n",f[n][15]);
	return ;
}

void work(){
	int a,b;
	while(cin >> a >> b){
		cout << (a ^ b) << endl;
	}
	return ;
}

int main(){
	solve(MAXN - 1);
	int test,cas = 1;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		printf("%d %d\n",cas++,f[n][15]);
	}
	return 0;
}
