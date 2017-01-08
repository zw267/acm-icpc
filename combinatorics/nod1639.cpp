                                            
  //File Name: nod1639.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月13日 星期三 13时32分40秒
                                   

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 1002;

double f[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)){
		f[2] = 2.0 / 3.0;
		for(int i=3;i<=n;i++)
			f[i] = f[i-1] * (2.0 * i - 2.0) / (2.0 * i - 1.0);
		printf("%.8f\n",f[n]);
	}
	return 0;
}
