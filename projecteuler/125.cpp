                                            
  //File Name: 125.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月06日 星期日 00时30分56秒
                                   
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <set>
#define LL long long
using namespace std;
set<int> rem;
LL sum(int n){
	return 1LL * n * (n + 1) * (2 * n + 1) / 6;
}
bool ok(int x){
	int a[15],n = 0;
	while(x){
		a[++n] = x % 10;
		x /= 10;
	}
	for(int i=1;i+i<=n;i++)
		if(a[i] != a[n+1-i]) return false;
	return true;
}
LL solve(int n){
	int r = sqrt(n + 0.5);
	for(int i = 1;i<=r;i++){
		for(int j=1;j<i;j++){
			LL now = sum(i) - sum(j - 1);
			if(now < n && ok(now))
				rem.insert(now);
		}
	}
	LL res = 0;
	for(set<int>::iterator it=rem.begin();it!=rem.end();it++)
		res += *it;
	return res;
}
int main(){
	int n = 100000000;
	cout << solve(n) << endl;
	return 0;
}
