                                            
  //File Name: 12.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 00时26分44秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
int cal(LL s){
	int res = 0;
	for(LL i=1;i*i<=s;i++){
		if(s % i == 0){
			res++;
			if(s / i != i)
				res++;
		}
	}
	return res;
}
int main(){
	int n;
	LL s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s = (i + 1LL) * i / 2;
		int now = cal(s);
		if(now > 500)	
			break;
	}
	if(cal(s) <= 500) s = -1;
	printf("%lld\n",s);
	return 0;
}
