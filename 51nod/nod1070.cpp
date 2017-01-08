                                            
  //File Name: nod1070.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月12日 星期日 22时14分47秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>

#define LL long long

using namespace std;

set<int> st;
set<int>::iterator it;

void init(){
	st.clear();
	int a = 0,b = 1,c;
	while(a + b <= 1000000000){
		c = a + b;
		st.insert(c);
		a = b;
		b = c;
	}
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		if(st.find(n) != st.end()) puts("B");
		else puts("A");
	}
	return 0;
}
