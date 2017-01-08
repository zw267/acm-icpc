                                            
  //File Name: hdu2065.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 16时21分55秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL unsigned long long

using namespace std;

const int M = 100;

LL qp(int x,LL y){
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % M;
		x = x * x % M;
		y >>= 1;
	}
	return res;
}

void solve(LL n){
	int res = (qp(4,n-1) + qp(2,n-1)) % M;
	printf("%d\n",res);
	return ;
}

int main(){
	int test;
	while(~scanf("%d",&test)){
		if(!test)
			break;
		int cas = 1;
		LL n;
		for(int i=0;i<test;i++){
			scanf("%llu",&n);
			printf("Case %d: ",cas++);
			solve(n);
		}
		puts("");
	}
	return 0;
}
