#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

using namespace std;

int num[26];
char str[100000+10];

LL solve(int n,int k)
{
	LL res = 0;
	for(int i=0;i<n;i++){
		num[str[i] - 'A']++;
	}
	sort(num,num+26);
	
	int cnt = 25;
	while(k){
		LL tmp = k<num[cnt] ? k:num[cnt];
		res = res + tmp * tmp;
		k -=tmp;
		cnt--;
	}

	return res;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",str);
	//printf("%lld\n",solve(n,k));
	printf("%I64d\n",solve(n,k));
	return 0;
}
