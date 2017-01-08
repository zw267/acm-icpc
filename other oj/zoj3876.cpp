                                            
  //File Name: zoj3876.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 14时42分31秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int a[10000];

bool ok(int y)
{
	if(y % 400 == 0)
		return true;
	if(y % 4 == 0 && y % 100 != 0)
		return true;
	return false;
}

void init()
{
	a[1928] = 2;
	int cur;
	for(int i=1929;i<10000;i++){
		if(ok(i))
			cur = 366;
		else
			cur = 365;
		a[i] = (a[i-1] + cur % 7) % 7;
	}
}

int solve(int y)
{
	if(a[y] == 1)
		return 9;
	if(a[y] == 0 || a[y] == 2)
		return 6;
	return 5;
}

int main()
{
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int y;
		scanf("%d",&y);
		printf("%d\n",solve(y));
	}
	return 0;
}
