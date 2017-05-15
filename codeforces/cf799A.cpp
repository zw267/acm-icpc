                                            
  //File Name: cf799A.cpp
  //Created Time: 2017年05月15日 星期一 10时45分34秒
                                   
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t,k,d;
	cin >> n >> t >> k >> d;
	int u = (n + k - 1) / k * t;
	int v,w;
	if(n <= k) v = w = 1000000000;
	else{
		int tmp = d / t * k;
		w = d + (n - tmp + k + k - 1) / (k + k) * t;
		tmp = (d + t - 1) / t * k;
		v = (d + t - 1) / t * t + (n - tmp + k + k - 1) / (k + k) * t;
	}
	if(v < u || w < u) puts("YES");
	else puts("NO");
	return 0;
}
