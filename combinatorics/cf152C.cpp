                                            
  //File Name: cf152C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 12时59分18秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 101;
const int MOD = (int)1e9 + 7;
bool vis[26];
char str[MAXN][MAXN];

LL solve(int n,int m){
	LL ans = 1;
	for(int i=0;i<m;i++){
		memset(vis,false,sizeof vis);
		for(int j=0;j<n;j++){
			vis[str[j][i] - 'A'] = true;
		}
		int now = 0;
		for(int j=0;j<26;j++)
			if(vis[j]) now++;
		ans = ans * now % MOD;
	}
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%s",str[i]);
		}
		printf("%d\n",(int)solve(n,m));
	}
	return 0;
}
