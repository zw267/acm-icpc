                                            
  //File Name: cf614A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 00时41分22秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LL unsigned long long

using namespace std;

LL qp(LL x,LL y)
{
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

void solve(LL l,LL r,LL k)
{
	LL a = log10(l+0.0) / log10(k+0.0);
	LL b = log10(r+0.0) / log10(k+0.0);
	if(qp(k,a) < l)
		a++;
	if(qp(k,b) > r)
		b--;
	if(a > b){
		cout << "-1" << endl;
		return ;
	}

	for(LL i=a;i<b;i++){
		cout << qp(k,i) << " ";
	}
	cout << qp(k,b) << endl;


	return ;


}

int main()
{
	LL l,r;
	cin >> l >> r;
	LL k;
	cin >> k;
	solve(l,r,k);
	return 0;
}

