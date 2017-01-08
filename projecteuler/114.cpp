                                            
  //File Name: 114.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月06日 星期日 00时00分06秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 51;
LL f[MAXN];
LL solve(int n){
	f[0] = f[3] = 1;
	for(int i=4;i<=n;i++){
		f[i] = i - 2;
		for(int j=i-4;j>=1;j--){
			f[i] += f[j] * (i - j - 3);
		}
	}
	LL res = 0;
	for(int i=0;i<=n;i++)
		res += f[i];
	return res;
}
int main(){
	int n = 50;
	printf("%lld\n",solve(n));
	return 0;
}
