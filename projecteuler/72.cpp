                                            
  //File Name: 72.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 11时51分13秒
                                   
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 1000000 + 1;
bool check[MAXN];
int prime[MAXN],phi[MAXN];
long long solve(){
	memset(check,false,sizeof(check));
	int tot = 0;
	phi[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for(int j=0;j<tot;j++){
			if(1LL * i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	long long res = 0;
	for(int i=2;i<MAXN;i++)
		res += phi[i];
	return res;
}
int main(){
	cout << solve() << endl;
}
