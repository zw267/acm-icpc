                                            
  //File Name: 21.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 01时33分47秒
                                   
#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 10000;
int s[MAXN];
void init(){
	for(int i=1;i<MAXN;i++){
		for(int j=2*i;j<MAXN;j+=i)
			s[j] += i;
	}
}
int main(){
	init();
	int ans = 0;
	for(int i=1,j;i<MAXN;i++){
		if(s[i] < MAXN  && s[i] > i && s[s[i]] == i)
			ans += i + s[i];
	}
	cout << ans << endl;
}
