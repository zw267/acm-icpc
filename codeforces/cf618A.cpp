                                            
  //File Name: cf618A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月04日 星期四 21时37分49秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a[21];

void solve(int n)
{
	int len = 1;
	while(n){
		a[len++] = n % 2;
		n /= 2;
	}
	//[1,len)
	bool flag = false;
	for(int i=len-1;i>0;i--){
		if(a[i] == 0)
			continue;
		if(flag){
			printf(" ");
		}
		flag = true;
		printf("%d",i);
	}
	puts("");
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
