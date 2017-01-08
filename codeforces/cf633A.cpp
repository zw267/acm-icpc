                                            
  //File Name: cf633A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月27日 星期六 21时47分43秒
                                   

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a,int b,int & x,int & y)
{
	int d = a;
	if(b != 0){
		d = gcd(b,a % b,y,x);
		y -= (a / b) * x;
	}
	else{
		x = 1;
		y = 0;
	}
	return d;
}

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	bool flag = false;
	for(int i=0;i*a <= c;i++){
		int y = c - i * a;
		if(y %b == 0){
			flag = true;
			break;
		}
	}	
	if(flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}
