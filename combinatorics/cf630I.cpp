                                            
  //File Name: cf630I.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月10日 星期日 10时28分13秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL p4[30];

void init(){
	p4[0] = 1;
	for(int i=1;i<30;i++)
		p4[i] = p4[i-1] * 4;
}

int main(){
	init();
	int n;
	cin >> n;
	cout << p4[n-3] * (9 * n - 3) << endl;
	return 0;
}
