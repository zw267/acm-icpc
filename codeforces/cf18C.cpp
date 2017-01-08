//水题


#include <cstdio>

const int MAXN = 100000+10;

int sum[MAXN];

int solve(int n)
{
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		sum[i] += sum[i-1];
	}

	int ret = 0;
	for(int i=1;i<n;i++){
		if(sum[i] * 2 == sum[n])
			ret++;
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&sum[i]);

	printf("%d\n",solve(n));

	return 0;
}
