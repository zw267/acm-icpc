                                            
  //File Name: uva11609.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月23日 星期三 17时57分06秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long 

using namespace std;

const int MOD = 1000000007;

LL qp(LL x,LL y)
{
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x *x % MOD;
		y >>= 1;
	}
	return res;
}

LL solve(LL n)
{
	return n * qp(2,n - 1) % MOD;
}

int main()
{
	int test;
	int cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case #%d: ",cas++);
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}
