                                            
  //File Name: 34.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 18时14分22秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
int jie[10];
bool ok(int x){
	int y = x,res = 0;
	while(y){
		res += jie[y % 10];
		y /= 10;
	}
	if(res == x) return true;
	return false;
}
int main(){
	int ma = 2540160;
	jie[0] = 1;
	for(int i=1;i<10;i++)
		jie[i] = jie[i-1] * i;
	LL res = 0;
	for(int i=10;i<ma;i++){
		if(ok(i)) res += i;
	}
	cout << res << endl;
	return 0;
}
