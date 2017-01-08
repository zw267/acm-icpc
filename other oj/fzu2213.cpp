                                            
  //File Name: fzu2213.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 01时34分27秒
                                   

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define y1 y10
#define y0 y00

using namespace std;

int x1,y1,r1;
int x0,y0,r0;

inline int p(int x)
{
	return x * x;
}

void solve()
{
	int ans = 0;
	if(r1 > r0){
		swap(r1,r0);
		swap(x1,x0);
		swap(y1,y0);
	}
	int dis = p(x1 - x0) + p(y1 - y0);
	int cha = p(r1 - r0);
	int he = p(r1 + r0);
	if(x1 == x0 && y1 == y0 && r1 == r0)
		puts("-1");
	else if(dis < cha)
		puts("0");
	else if(dis == cha)
		puts("1");
	else if(cha < dis && dis < he)
		puts("2");
	else if(dis == he)
		puts("3");
	else
		puts("4");
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d",&x1,&y1,&r1);
		scanf("%d %d %d",&x0,&y0,&r0);
		solve();
	}
	return 0;
}
