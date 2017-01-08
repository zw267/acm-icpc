                                            
  //File Name: cf293B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月15日 星期四 15时28分06秒
                                   

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
int a[15][15],mask[15][15],s[15],bin[2000];
int n,m,k;
LL dfs(int x,int y){
	if(x == n + 1) return 1;
	if(y == m + 1) return dfs(x+1,1);
	int t = mask[x][y-1] | mask[x-1][y];
	LL res = 0,f = -1;
	for(int i=(1<<k)-1-t;i;i-=i&-i){
		int u = bin[i & -i];
		if(a[x][y] && a[x][y] - 1 != u) continue;
		mask[x][y] = t | (1 << u);
		s[u]++;
		if(s[u] == 1){
			if(f == -1) f = dfs(x,y+1);
			res += f;
		}
		else
			res += dfs(x,y+1);
		if(res >= MOD) res -= MOD;
		s[u]--;
	}
	return res;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	if(n + m - 1 > k){
		for(int i=1;i<=n * m;i++) scanf("%d",&k);
		puts("0");
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]) s[a[i][j]-1]++;
			}
		for(int i=0;i<k;i++) bin[1<<i] = i;
		cout << dfs(1,1) << endl;
	}
	return 0;
}
