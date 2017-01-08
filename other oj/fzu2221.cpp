                                            
  //File Name: fzu2221.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 01时51分33秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int x[3];

void solve(int n,int m)
{
	x[0] = x[1] = x[2] = n / 3;
	if(n % 3 == 2)
		x[1]++;
	if(m >= x[0] + x[1] + 2)
		puts("No");
	else
		puts("Yes");
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d %d",&n,&m);
		solve(n,m);
	}
	return 0;
}
