                                            
  //File Name: cf794B.cpp
  //Created Time: 2017年05月14日 星期日 23时33分32秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
double ans[MAXN];
void solve(const double n,const double h){
	double area = h / n;
	for(int i(1);i<n;++i){
		double cur = i * area;
		ans[i] = sqrt(h * cur);
	}
}
int main(){
	double n,h;
	scanf("%lf %lf",&n,&h);
	solve(n,h);
	for(int i(1);i<n;++i)
		printf("%.12f ",ans[i]);
	puts("");
	return 0;
}
