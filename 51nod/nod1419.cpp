                                            
  //File Name: nod1419.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 12时47分13秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL unsigned long long

using namespace std;

LL gcd(LL x,LL y){
	if(!y) return x;
	return gcd(y,x % y);
}

int main(){
	LL n;
	while(cin >> n){
		if(n == 1) 
			puts("1");
		else if(n == 2)
			puts("2");
		else{
			LL now = n / gcd(n,n-1) * (n - 1);
			LL ans = 1,cnt;
			for(int i=1;i<=n;i++){
				cnt = now / gcd(now,i) * i;
				if(cnt > ans) ans = cnt;
			}
			now = (n-1) / gcd(n-1,n-2) * (n-2);
			now = now / gcd(now,n-3) * (n-3);
			if(now > ans) ans = now;
			cout << ans << endl;
		}
	}
	return 0;
}
