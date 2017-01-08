//notice the function lcm()
//in order to avoid long long int overflow
// wa five times because long long overflow



#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

#define LL long long 

using namespace std;

LL a[15];
LL l,r;
LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

LL lcm(LL x,LL y)
{
	LL g = gcd(x,y);
	if(x / g > r / y)
		return r + 1;
	return x / g * y;
}

LL solve(LL sum,int n,LL cur)
{
	int ma = (1 << n);
	LL ret = 0;
	for(int i=1;i<ma;i++){
		int num = 0;
		LL cur1 = 1;
		for(int j=0;j<n;j++){
			if(i & (1 << j)){
				num++;
				cur1 = lcm(cur1,a[j]);
			}
		}
		LL cur2 = lcm(cur,cur1);
		//printf("%d %lld %lld\n",i,lcm,cur);
		if(num % 2)
			ret = ret + sum / cur1 - sum / cur2;
		else 
			ret = ret - sum / cur1 + sum / cur2;
	}
	//printf("%lld\n",ret);
	return ret;
}

int main()
{
	int n, m;
	while(~scanf("%d %d %lld %lld",&n,&m,&l,&r)){
		if(!n && !m && !l && !r)
			break;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		LL cur = 1;
		for(int i=0;i<m;i++){
			LL tmp;
			scanf("%lld",&tmp);
			cur = lcm(cur,tmp);
		}

		printf("%lld\n",solve(r,n,cur) - solve(l - 1,n,cur));
	}
	return 0;
}
