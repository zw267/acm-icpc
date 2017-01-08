                                            
  //File Name: poj2407.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月30日 星期日 14时25分23秒
                                   
#include <iostream>
#define LL long long
using namespace std;
int phi(int n){
	int ans = n;
	for(int i=2;(LL)i*i<=n;i++){
		if(n % i == 0){
			ans -= ans / i;
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) ans -= ans / n;
	return ans;
}
int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		cout << phi(n) << endl;
	}
	return 0;
}
