                                            
  //File Name: cf150B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月13日 星期六 16时39分34秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>

#define LL long long

using namespace std;

const int MOD = 1e9+7;

LL qp(LL x,LL y)
{
	LL res = 1LL;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void solve(int n,int m,int k)
{
	LL ans = 0;
	if(k > n){
		ans = qp(m,n);
	}
	else if(k == n){
		if(n % 2 == 0)
			ans = qp(m,n / 2);
		else
			ans = qp(m,n / 2 + 1);
	}
	else{
		if(k == 1)
			ans = qp(m,n);
		else if(k % 2)
			ans = m * m;
		else
			ans = m;
	}
	
	cout << ans << endl;
	return ;
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	solve(n,m,k);
	return 0;
}
