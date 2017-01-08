                                            
  //File Name: 179.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月05日 星期六 23时38分58秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 10000000 + 1;
bool check[MAXN];
int prime[MAXN],fir[MAXN];
int cal(int x){
	int res = 1,pre = fir[x];
	while(fir[x] > 0){
		int num = 0;
		while(fir[x] == pre){
			x /= fir[x];
			num++;
		}
		res *= (num + 1);
		pre = fir[x];
	}
	return res;
}
int solve(int n){
	memset(check,false,sizeof(check));
	int tot = 0;
	fir[1] = -1;
	for(int i=2;i<=n;i++){
		if(!check[i])
			prime[tot++] = i,fir[i] = i;
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] > n) break;
			check[i * prime[j]] = 1;
			fir[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	int res = 0,pre = 2,now;
	for(int i=3;i<=n;i++){
		now = cal(i);
		if(now == pre) res++;
		pre = now;
	}
	return res;
}
int main(){
	int n = MAXN - 1;
	cout << solve(n) << endl;
	return 0;
}
