                                            
  //File Name: poj2409.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月30日 星期日 15时07分33秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
LL p[33];
int gcd(int x,int y){
	return y == 0 ? x : gcd(y, x % y);
}
LL solve(int c,int s){
	p[0] = 1;
	for(int i=1;i<=c*s;i++)
		p[i] = p[i-1] * c;
	LL ans = 0;
	for(int i=0;i<s;i++){
		int d = gcd(i,s);
		ans += p[d];
	}
	if(s & 1)
		ans += s * p[s / 2 + 1];
	else
		ans += s / 2 * p[s / 2] + s / 2 * p[s / 2 + 1];
	ans /= (2 * s);
	return ans;
}
int main(){
	int c,s;
	while(~scanf("%d %d",&c,&s)){
		if(!c && !s) break;
		printf("%lld\n",solve(c,s));
	}
	return 0;
}
