#include <cstdio>
#include <map>
#include <math.h>

using namespace std;

int gcd(int x,int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int qp(int x,int y)
{
	int ret = 1;
	while(y){
		if(y & 1)
			ret = ret * x;
		x *= x;
		y >>= 1;
	}
	return ret;
}

map<int,int> fact(int x)
{
	map<int,int> ret;
	for(int i=2;i * i <= x;i++){
		while(x % i == 0){
			ret[i]++;
			x /= i;
		}
	}
	if(x != 1)
		ret[x]++;
	return ret;
}

int solve(int a,int c)
{
	map<int,int> mc = fact(c);
	map<int,int> ma = fact(a);

	int res = 1;
	map<int,int>::iterator it;
	for(it=mc.begin();it != mc.end();it++){
		if(it->second == ma[it->first])
			;
		else
			res = res * qp(it->first,it->second);
	}
	return res;	
}

int main()
{
	//printf("%d\n",qp(3,4));
	int test;
	scanf("%d",&test);
	while(test--){
		int a,c;
		scanf("%d %d",&a,&c);
		if(c % a != 0)
			puts("NO SOLUTION");
		else
			printf("%d\n",solve(a,c));
	}
	return 0;
}
