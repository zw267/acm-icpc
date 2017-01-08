                                            
  //File Name: 35.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 19时07分07秒
                                   
#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1000000;
bool check[MAXN],is[MAXN];
int prime[MAXN];
bool ok(int x){
	if(!is[x]) return false;
	int len = 0,y = x;
	while(y){
		y /= 10;
		len++;
	}
	int mod = 1;
	for(int i=1;i<len;i++) mod *= 10;
	for(int i=1;i<len;i++){
		x = (x % mod) * 10 + (x / mod);
		if(!is[x]) return false;
	}
	return true;
}
int solve(int n){
	memset(check,false,sizeof(check));
	memset(is,false,sizeof(is));
	int tot = 0;
	for(int i=2;i<n;i++){
		if(!check[i]){
			prime[tot++] = i;
			is[i] = true;
		}
		for(int j=0;j<tot;j++){
			if((long long)i * prime[j] >= n) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	int res = 0;
	for(int i=0;i<tot;i++){
		if(ok(prime[i]))
			res++;
	}
	return res;
}
int main(){
	cout << solve(1000000) << endl;
	return 0;
}
