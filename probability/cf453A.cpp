                                            
  //File Name: cf453A.cpp
  //Created Time: 2017年02月26日 星期日 13时35分50秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 2;
double f[MAXN];
double qp(double x,int y){
	double res = 1.0;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x;
		x = x * x;
	}
	return res;
}
double solve(int m,int n){
	for(int i=0;i<=m;++i){
		f[i] = qp(i * 1.0 / m,n);
//		printf("i = %d f = %.10f\n",i,f[i]);
	}
	double res = 0;
	for(int i=1;i<=m;++i)
		res += i * (f[i] - f[i - 1]);
	return res;
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	printf("%.15f\n",solve(m,n));
	return 0;
}
