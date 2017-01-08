                                            
  //File Name: 23.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 17时48分09秒
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 28124;
LL f[MAXN];
LL solve(){
	for(int i=1;i<MAXN;i++){
		for(int j=2*i;j<MAXN;j+=i)
			f[j] += i;
	}
	LL res = 0;
	for(int i=1;i<MAXN;i++){
		bool flag = false;
		for(int j=1;j+j<=i;j++){
			if(f[j] > j && f[i-j] > i - j){
				flag = true;
				break;
			}
		}
		if(!flag) res += i;
	}
	return res;
}
int main(){
	cout << solve() << endl;
	return 0;
}

