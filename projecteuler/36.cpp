                                            
  //File Name: 36.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 18时23分16秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
int a[25];
bool ok(int x){
	int y = x,n = 0;;
	while(y){
		a[++n] = y % 10;
		y /= 10;
	}
	for(int i=1;i+i<=n;i++)
		if(a[i] != a[n+1-i]) return false;
	y = x,n = 0;
	while(y){
		a[++n] = y & 1;
		y >>= 1;
	}
	for(int i=1;i+i<=n;i++)
		if(a[i] != a[n+1-i]) return false;
	return true;
}
LL solve(int n){
	LL res = 0;
	for(int i=1;i<n;i++)
		if(ok(i)) res += i;
	return res;
}
int main(){
	cout << solve(1000000) << endl;
	return 0;
}
