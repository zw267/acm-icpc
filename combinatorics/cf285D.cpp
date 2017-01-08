                                            
  //File Name: cf285D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月09日 星期六 16时44分05秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = (int)1e9 + 7;

LL ans,n;
LL jie[17];
int res[17] = {0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};

void init(){
	jie[0] = 1;
	for(int i=1;i<17;i++)
		jie[i] = i * jie[i-1] % MOD;
	//ans = 0;
	//dfs(1,0,0);
}

void dfs(int a,int b,int c){
	if(a == n + 1){
		ans++;
		if(ans >= MOD) 
			ans -= MOD;
		return ;
	}
	int v;
	for(int i=0;i<n;i++){
		if(((1<<i) & b) == 0){
			v = (i + a - 1) % n;
			if(((1<<v) & c) == 0)
				dfs(a+1,b|(1<<i),c|(1<<v));
		}
	}
}


int main(){
	init();
	while(~scanf("%d",&n)){
		printf("%d\n",res[n]);
	}	
	return 0;
}
