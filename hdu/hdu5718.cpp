                                            
  //File Name: hdu5718.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月26日 星期二 20时42分40秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 10000000 + 2;

char str[MAXN];
int num[10];
int ans[MAXN];

int solve(){
	int n = strlen(str);
	for(int i=0;i<10;i++) num[i] = 0;
	int sum = 0;
	for(int i=0,u;i<n;i++){
		u = str[i] - '0';
		if(u) sum++;
		num[u]++;
	}
	if(sum <= 1){
		printf("Uncertain");
		return -1;
	}
	int u = -1;
	for(int i=1;i<10;i++){
		if(num[i] > 0){
			u = i;
			num[i]--;
			break;
		}
	}
	int tot = 0;
	for(int i=0;i<10;i++){
		while(num[i]){
			ans[tot++] = i;
			num[i]--;
		}
	}
	ans[0] += u;
	int i = 0;
	while(i < tot - 1 && ans[i] >= 10){
		ans[i+1] += ans[i] / 10;
	    ans[i] = ans[i] % 10;
		i++;	
	}
	if(ans[tot-1] >= 10){
		ans[tot] = ans[tot-1] / 10;
		ans[tot-1] = ans[tot-1] % 10;
		tot++;
	}
	return tot;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int tot = solve();
		for(int i=tot-1;i>=0;i--)
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
