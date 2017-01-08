                                            
  //File Name: 10.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 22时49分00秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 10000000;
bool check[MAXN];
int prime[1000000];
LL solve(int x){
	memset(check,false,sizeof(check));
	int tot = 0;
	LL res = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			if(i >= x) return res;
			res += prime[tot-1];
		}	
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN)
				break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
