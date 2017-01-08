                                            
  //File Name: cf630C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 12时50分11秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL p2[56];

void init(){
	p2[0] = 0;
	p2[1] = 2;
	for(int i=2;i<56;i++)
		p2[i] = p2[i-1] * 2LL;
	for(int i=1;i<56;i++)
		p2[i] += p2[i - 1];
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		cout << p2[n] << endl;
	}
	return 0;
}


