                                            
  //File Name: poj3111.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 23时06分40秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define fir first
#define sec second
#define mp make_pair
#define LL long long

using namespace std;

const int MAXN = 100000 + 5;
const int INF = 10000001;

int a[MAXN];
int b[MAXN];
double d[MAXN];
pair<double,int> ans[MAXN];
int print[MAXN];

bool ok(const int n,const int k,const double x){
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

void solve(const int n,const int k){
	double l = 0.0,r = INF + 0.0,mid;
	for(int i=0;i<50;i++){
		mid = (l + r) / 2.0;
		if(ok(n,k,mid))
			l = mid;
		else
			r = mid;
	}
	for(int i=0;i<n;i++){
		ans[i].fir = (a[i] + 0.0) - l * (b[i] + 0.0); 
		ans[i].sec = i + 1;
	}
	sort(ans,ans+n);
	int tot = 0;
	for(int i=n-1;i>=n-k;i--){
		print[tot++] = ans[i].sec;
	}
	for(int i=0;i<tot-1;i++){
		printf("%d ",print[i]);
	}
	printf("%d\n",print[tot-1]);
	return ;
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&a[i],&b[i]);
		}
		solve(n,k);
	}
	return 0;
}
