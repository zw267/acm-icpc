                                            
  //File Name: poj2115.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月13日 星期日 21时39分35秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y,x % y);
}

LL ext_gcd(LL a,LL b,LL &x,LL &y)
{
	LL d = a;
	if(b != 0){
		d = ext_gcd(b,a%b,y,x);
		y -= (a / b) * x;
	}
	else{
		x = 1;
		y = 0;
	}
	return d;
}

LL qp(LL x,LL y,LL P)
{
	LL res = 1;
	while(y){
		if(y & 1){
			res = res * x % P;
		}
		x = x * x % P;
		y >>= 1;
	}
	return res;
}

void solve(LL a,LL b,LL c,int k)
{
	LL K = (LL)1 << k;
	LL x,y;
	b = b - a;
	LL d = ext_gcd(c,K,x,y);
	if(b % d){
		puts("FOREVER");
	}
	else{
		x = x * (b / d) % K;
		x = (x % (K / d) + K / d) % (K / d);
		printf("%lld\n",x);
	}
	return ;
}

int main()
{
	LL a,b,c;
	int k;
	while(~scanf("%lld %lld %lld %d",&a,&b,&c,&k)){
		if(!a && !b && !c && !k)
			break;
		solve(a,b,c,k);
	}
	return 0;
}
