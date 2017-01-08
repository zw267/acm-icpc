                                            
  //File Name: light1234.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 14时47分59秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000;
const double C = 0.57721566490153286060651209;
double a[MAXN];
void init(){
	for(int i=1;i<MAXN;i++)
		a[i] = a[i - 1] + 1.0 / (i + 0.0);
}
double solve(int n){
	if(n < MAXN) return a[n];
	double res = log(n + 0.0) + 1.0 / (2.0 * n) + C;
	return res;
}
int main(){
	init();
	int t,n,cas = 1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("Case %d: %.14lf\n",cas++,solve(n));
	}
	return 0;
}
