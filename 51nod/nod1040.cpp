                                            
  //File Name: nod1040.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月14日 星期二 00时50分55秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

#define LL long long

using namespace std;

vector<int> dive;

void get_dive(int x){
	dive.clear();
	int ma = (int)sqrt(x + 0.5);
	for(int i=1;i<=ma;i++){
		if(x % i == 0){
			dive.push_back(i);
			int j = x / i;
			if(j != i)
				dive.push_back(j);
		}
	}
	//for(int i=0;i<dive.size();i++)
	//	printf("%d\n",dive[i]);
}

int phi(int x){
	int ans = x;
	int ma = (int)sqrt(x + 0.5);
	for(int i=2;i<=ma;i++){
		if(x % i == 0){
			ans -= ans / i;
			while(x % i == 0)
				x /= i;
		}
	}
	if(x > 1)
		ans -= ans / x;
	return ans;
}

LL solve(int n){
	get_dive(n);
	LL ans = 0;
	for(int i=0;i<dive.size();i++){
		ans += (LL) n / dive[i] * (LL)phi(dive[i]);
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		printf("%lld\n",solve(n));
	}
	return 0;
}
