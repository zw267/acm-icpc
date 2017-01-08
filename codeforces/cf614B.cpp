#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000+10;

char str[MAXN];
char t[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	bool flag = false;
	int sum = 0;
	for(int i=0;i<n;i++){
		scanf("%s",str);
		int num1 = 0;
		int num0 = 0;
		int num2 = 0;
		for(int i=0;i<strlen(str);i++){
			if(str[i] == '0')
				num0++;
			else if(str[i] == '1')
				num1++;
			else
				num2++;
			
		}
		if(strlen(str) == 1 && num0 == 1){
			puts("0");
			return 0;
		}
		if(num2 > 0 || num1 > 1){
			for(int i=0;i<strlen(str);i++)
				t[i] = str[i];
			flag = true;
		}
		else{
			sum += num0;
		}
	}
	
	if(flag){
		printf("%s",t);
	}
	else{
		printf("1");
	}
	for(int i=0;i<sum;i++)
		printf("0");
	puts("");
	return 0;
}
