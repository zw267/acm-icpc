                                            
  //File Name: cf134B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月09日 星期三 20时59分16秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int tmp;
int gcd(int x,int y){
	if(x < y) swap(x,y);
	if(y == 0) return x;
	if(y == 1)
		tmp += x - y;
	else
		tmp += x / y;
	return gcd(y, x % y);
}
int solve(int n){
	int res = n - 1;
	for(int i=2;i<n;i++){
		tmp = 0;
		int d = gcd(n,i);
		if(d == 1)
			res = min(res,tmp);
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
}
