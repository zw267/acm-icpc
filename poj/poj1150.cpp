                                            
  //File Name: poj1150.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月13日 星期日 19时46分50秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n,m;
	long long ans = 1;
	for(int i=10;i>=1;i--){
		ans = ans * i;
	}
	cout << ans << endl;
}
