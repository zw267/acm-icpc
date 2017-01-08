                                            
  //File Name: cf356C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月11日 星期一 20时37分01秒
                                   


#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;

int num[5];
int a[MAXN];

int solve(int n){
	//for(int i=1;i<=4;i++)
	//	printf("i = %d num[%d] = %d\n",i,i,num[i]);
	int ans = 0;
	if(num[1] >= num[2]){
		num[3] += num[2];
		num[1] -= num[2];
		ans += num[2];
		num[2] = 0;
		num[3] += num[1] / 3;
		ans += num[1] / 3 * 2;
		num[1] %= 3;
		if(num[1] <= num[3])
			ans += num[1];
		else if(num[4] && num[1] == 2)
			ans += 2;
		else if(num[4] >= 2 && num[1] == 1)
			ans += 2;
		else 
			ans = -1;
	}
	else{
		num[3] += num[1];
		num[2] -= num[1];
		ans += num[1];
		num[1] = 0;
		num[3] += num[2] / 3 * 2;
		ans += num[2] / 3 * 2;
		num[2] %= 3;
		if(num[2] == 1){
			if(num[4])
				ans++;
			else if(num[3] >= 2)
				ans += 2;
			else
				ans = -1;
		}
		else if(num[2] == 2)
			ans += 2;
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		printf("%d\n",solve(n));
	}
	return 0;
}
