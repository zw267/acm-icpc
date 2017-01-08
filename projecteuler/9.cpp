                                            
  //File Name: 9.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时42分56秒
                                   
#include <iostream>
using namespace std;
int solve(){
	for(int a=1;a<1000;a++){
		for(int b=a;b<1000;b++){
			int c = 1000 - a - b;
			if(c > b && a * a + b * b == c * c)
				return a * b * c;
		}
	}
	return -1;
}
int main(){
	cout << solve() << endl;
	return 0;
}
