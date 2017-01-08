                                            
  //File Name: 62.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 21时58分56秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#define LL long long
using namespace std;
map<string,int> rem;
string get(LL x){
	char res[20];
	int n = 0;
	while(x){
		res[n++] = x % 10 + '0';
		x /= 10;
	}
	sort(res,res+n);
	return string(res);
}
LL solve(int n){
	int ma = 100000;
	LL res = 1000000000000000;
	for(int i=1;i<ma;i++){
		string str = get(1LL * i * i * i);
		rem[str]++;
	}
	for(int i=1;i<ma;i++){
		string str = get(1LL * i * i * i);
		if(rem[str] == n)
			res = min(res,1LL * i * i * i);
	}
	return res;
}
int main(){
	cout << solve(5) << endl;
}
