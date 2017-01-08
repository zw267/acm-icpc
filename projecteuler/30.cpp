                                            
  //File Name: 30.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 11时18分08秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int p5[10];
bool good(int x){
	int y = x,res = 0;
	while(y > 0){
		res += p5[y % 10];
		y /= 10;
	}
	if(res == x) return true;
	return false;
}
int solve(){
	for(int i=0;i<10;i++)
		p5[i] = i * i * i * i * i;
	int res = 0;
	for(int i=2;i<10000000;i++){
		if(good(i))
			res += i;
	}
	return res;
}
int main(){
	cout << solve() << endl;
	return 0;
}
