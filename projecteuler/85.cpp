                                            
  //File Name: 85.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 23时14分29秒
                                   
#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
int solve(int n){
	int ma = 2000;
	LL res = 0;
	LL dif = 10000000;
	for(int i=1;i<ma;i++){
		for(int j=1;j<ma;j++){
			LL now = (1LL + i) * i / 2 * (1LL + j) * j / 2;
			if(abs(now - n) < dif){
				dif = abs(now - n);
				res = i * j;
			}
		}
	}
	return res;
}
int main(){
	cout << solve(2000000) << endl;
	return 0;
}
