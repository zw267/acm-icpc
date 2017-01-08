                                            
  //File Name: 5.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时19分09秒
                                   
#include <iostream>
using namespace std;
int gcd(int x,int y){
	return y ==0 ? x : gcd(y,x % y);
}
int main(){
	int lcm = 1;
	for(int i=1;i<=20;i++){
		lcm = lcm / gcd(lcm,i) * i;
	}
	cout << lcm << endl;
	return 0;
}
