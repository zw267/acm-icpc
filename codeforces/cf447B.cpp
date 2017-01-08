#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1000+10;

char str[MAXN];
int w[27];
int val[MAXN];

int solve(int k)
{
	int len = strlen(str);
	int res = 0; 

	for(int i=1;i<=len;i++){
		val[i] = w[str[i-1]-'a'];
		res = res +val[i] * i;
	}
	for(int i=len-1;i>0;i--)
		val[i] = val[i+1] + val[i];

	int ma = w[0];
	for(int i=1;i<26;i++){
		if(w[i] > ma)
			ma = w[i];
	}

	int tmp = 0;
	for(int i=1;i<=len;i++){
		tmp = max(tmp,val[i] * k + ma * (k * i + (k-1) * k / 2));
	}
	tmp = max(tmp,ma * (k * len + (1 + k) * k / 2));

	return res + tmp;
}

int main()
{
	scanf("%s",str);
	int k;
	scanf("%d",&k);
	for(int i=0;i<26;i++)
		scanf("%d",&w[i]);

	printf("%d\n",solve(k));

	return 0;
}
