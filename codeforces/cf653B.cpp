                                            
  //File Name: cf653B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 17时03分27秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int f[10][10];
int base = 'a';

LL dfs(int pos,int x,int n){
	if(pos == n + 1){
		return 1;
	}
	LL res = 0;
	for(int i=0;i<6;i++){
		if(f[i][x]){
			res += f[i][x] * dfs(pos+1,i,n);
		}
	}
	return res;
}

void solve(int n,int q){
	LL res = dfs(2,0,n);
	cout << res << endl;
	return ;
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	char s[5],t[5];
	memset(f,0,sizeof f);
	for(int i=1;i<=q;i++){
		scanf("%s %s",s,t);
		f[s[0]-'a'][t[0]-'a']++;		
	}
	solve(n,q);
	return 0;
}
