#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[3];

char str[1000+10];

void solve()
{
	int len = strlen(str);
	num[0] = num[1] = num[2] = 0;
	int sum = 0;
	for(int i=0;i<len;i++){
		int cur = str[i] - '0';
		sum += cur;
		num[cur % 3]++;
	}
	if(sum % 3 == 0){
		if(num[0]% 2)
			puts("S");
		else
			puts("T");
	}
	else if(sum % 3 == 1){
		if(num[1] > 0 && num[0] % 2 == 0)
			puts("S");
		else
			puts("T");
	}
	else{
		if(num[2] > 0 && num[0] % 2 == 0)
			puts("S");
		else
			puts("T");
	}
	return ;
}

int main()
{
	int test;
	int cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case %d: ",cas++);
		scanf("%s",str);
		solve();
	}
	return 0;
}
