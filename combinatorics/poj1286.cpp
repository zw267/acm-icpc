                                            
  //File Name: poj1286.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月30日 星期日 14时56分12秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#define LL long long
using namespace std;
LL p3[25];
void init(){
	p3[0] = 1;
	for(int i=1;i<25;i++)
		p3[i] = p3[i-1] * 3;
}
int gcd(int x,int y){
	return y == 0 ? x : gcd(y,x % y);
}
LL solve(int n){
	if(n == 0) return 0;
	LL ans = 0;
	for(int i=0;i<n;i++){
		int d = gcd(i,n);
		ans += p3[d];
	}
	if(n & 1)
		ans += p3[n / 2 + 1] * n;
	else
		ans += (n / 2) * p3[n / 2] + (n / 2) * p3[n / 2 + 1];
	ans = ans / (2 * n);
	return ans;
}
int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		if(n == -1) break;
		printf("%lld\n",solve(n));
	}
	return 0;
}
