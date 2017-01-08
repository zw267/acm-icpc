                                            
  //File Name: 3.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时08分27秒

#include <iostream>
#define LL long long
using namespace std;
LL solve(LL n){
	LL res = 0;
	for(LL i=2;i*i<=n;i++){
		if(n % i == 0){
			res = max(res,i);
			while(n % i == 0)
				n /= i;
		}
	}
	res = max(res,n);
	return res;
}
int main(){
	cout << solve((LL)600851475143) << endl;
	return 0;
}

