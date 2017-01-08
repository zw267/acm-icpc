                                            
  //File Name: poj2976.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 20时13分45秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 1000 + 5;

LL a[MAXN];
LL b[MAXN];
double d[MAXN];

bool ok(int n,int k,double x){
	for(int i=0;i<n;i++){
		d[i] = (a[i] + 0.0) - x * (b[i] + 0.0);
	}
	sort(d,d+n);
	double g = 0.0;
	for(int i=n-1;i>=n-k;i--){
		g += d[i];
	}
	return g >= 0;
}

void solve(int n,int k){
	double l = 0.0,r = 1.1,mid;
	for(int i=0;i<100;i++){
		mid = (l + r) / 2.0;
		if(ok(n,n-k,mid))
			l = mid;
		else
			r = mid;
	}
	l = 100.0 * l;
	printf("%d\n",(int)(l + 0.5));
	return ;
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		if(!n && !k)
			break;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		solve(n,k);
	}
	return 0;
}
