                                            
  //File Name: hdu1284.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 13时20分08秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define LL long long

using namespace std;

const int MAXN = 32769;

LL f[MAXN];

void init(){
	memset(f,0,sizeof f);
	f[0] = 1;
	for(int i=1;i<=3;i++){
		for(int j=0;j<MAXN;j++){
			if(j - i >= 0)
				f[j] += f[j-i];
		}
	}
	return ;
}

void solve(){
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%lld\n",f[n]);
	}
	return ;
}

int main(){
	solve();
	return 0;
}
