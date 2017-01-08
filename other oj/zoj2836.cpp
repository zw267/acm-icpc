#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long 

using namespace std;

int a[10];

LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y,x % y);
}

LL solve(int n,LL m)
{
	int ma = (1 << n);
	LL res = 0;
	for(int i=1;i<ma;i++){
		int num = 0;
		int lcm = 1;
		for(int j = 0;j < n;j++){
			if(i & (1 << j)){
				num++;
				lcm = lcm / gcd(lcm,a[j]) * a[j];
			}
		}
		if(num % 2)
			res += m / lcm;
		else
			res -= m / lcm;
	}
	return res;
}

int main()
{
	int n;
	LL m;
	while(~scanf("%d %lld",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
