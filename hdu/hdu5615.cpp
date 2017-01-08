                                            
  //File Name: hdu5615.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月31日 星期日 00时07分54秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

#define LL long long

using namespace std;

LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y,x % y);
}

LL extgcd(LL a,LL b,LL& x,LL& y)
{
	LL d = a;
	if(b != 0){
		d = extgcd(b,a % b,y,x);
		y -= (a / b) * x;
	}
	else{
		x = 1;
		y = 0;
	}
	return d;
}

bool solve(const LL a,const LL b,const LL c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return false;
	LL e1 = sqrt(a + 0.0);
	LL e2 = sqrt(c + 0.0);
	for(LL q=1;q<=e1;q++){
		if(a % q)
			continue;
		LL p = a / q;
		for(LL x=1;x<=e2;x++){
			if(c % x)
				continue;
			LL y = c / x;
			if(q * x + p * y == b || q * y + p * x == b)
				return true;
		}
	}
	return false;
}

int main()
{
	int test;
	cin >> test;
	while(test--){
		LL a,b,c;
		cin >> a >> b >> c;
		if(solve(a,b,c))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
