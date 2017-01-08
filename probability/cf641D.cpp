                                            
  //File Name: cf641D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月24日 星期日 18时30分30秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 100000 + 5;

double ans1[MAXN],ans2[MAXN];
double p[MAXN],q[MAXN];

void get(double &x1,double &x2,double b,double c){
	double u = b * b - 4.0 * c;
	if(u < 0) u = 0;
	u = sqrt(u);
	x1 = (-b - u) / 2.0;
	x2 = (-b + u) / 2.0;
}

void solve(int n){
	for(int i=1;i<=n;i++){
		if(i & 1)
		get(ans1[i],ans2[i],q[i+1]-p[i]-1,p[i]);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%lf",&p[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&q[i]);
		}
		for(int i=2;i<=n;i++)
			p[i] += p[i-1];
		for(int i=n-1;i>0;i--)
			q[i] += q[i+1];
		solve(n);
		for(int i=1;i<=n;i++){
			printf("%.10f",ans1[i] - ans1[i-1]);
			if(i == n) puts("");
			else printf(" ");
		}
		for(int i=1;i<=n;i++){
			printf("%.10f",ans2[i] - ans2[i-1]);
			if(i == n) puts("");
			else printf(" ");
		}
	}
	return 0;
}
