                                            
  //File Name: 70.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 11时34分32秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 10000000;
int phi[MAXN],prime[MAXN];
bool check[MAXN];
bool ok(int x,int y){
	int a[10],b[10],la = 0,lb = 0;
	while(x){
		a[la++] = x % 10;
		x /= 10;
	}
	while(y){
		b[lb++] = y % 10;
		y /= 10;
	}
	if(la != lb) return false;
	sort(a,a+la);
	sort(b,b+lb);
	for(int i=0;i<la;i++)
		if(a[i] != b[i])
			return false;
	return true;
}
int solve(){
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
				prime[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	int res = MAXN;
	double radio = MAXN + 0.0;
	for(int i=2;i<MAXN;i++){
		if(ok(i,phi[i]) && (double)i / phi[i] < radio){
			radio = (double)i / phi[i];
			res = i;
		}
	}
	return res;
}
int main(){
	cout << solve() << endl;
	return 0;	
}
