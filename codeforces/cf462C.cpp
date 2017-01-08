#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long 

using namespace std;

const int MAXN = 300000+10;

int a[MAXN];

LL solve(int n)
{
	LL res = 0;
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		res = res + a[i] * 1LL * (i+1);
	}

	return res - a[n];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	//printf("%lld\n",solve(n));
	printf("%I64d\n",solve(n));

	return 0;
}
