                                            
  //File Name: 7.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 15时34分10秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = (int)1e7;
bool check[MAXN];
int prime[MAXN / 10];
int solve(int ma){
	memset(check,false,sizeof(check));
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[++tot] = i;
			if(tot == ma) return i;
		}
		for(int j=1;j<=tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	return -1;
}
int main(){
	cout << solve(10001) << endl;
	return 0;
}

