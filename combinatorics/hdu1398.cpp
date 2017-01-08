                                            
  //File Name: hdu1398.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 10时50分10秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 301;

LL ans[MAXN];
LL c[MAXN];

void init(){
	for(int i=0;i<MAXN;i++)
		ans[i] = 1;
	memset(c,0,sizeof c);
	for(int ii=2;ii<=17;ii++){
		int i = ii * ii;
		for(int j=0;j<MAXN;j++){
			for(int k=0;k*i+j<MAXN;k++){
				c[k*i+j] += ans[j];
			}
		}
		for(int j=0;j<MAXN;j++){
			ans[j] = c[j];
			c[j] = 0;
		}
	}
	return ;
}

void solve(){
	init();
	int n;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		printf("%lld\n",ans[n]);
	}
	return ;
}

int main(){
	solve();
	return 0;
}
