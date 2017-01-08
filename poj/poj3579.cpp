                                            
  //File Name: poj3579.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月26日 星期六 01时09分46秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 100000+5;

int a[MAXN];

LL bs(int l,int r,int x){
	if(a[r] <= x)
		return 0;
	if(a[l] > x)
		return r - l + 1;
	int init_l = l,init_r = r;
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(a[mid] > x)
			r = mid;
		else
			l = mid;
	}
	if(a[l] > x)
		r = l;
	return init_r - r + 1;
}

LL get(int n,int x){
	LL res = 0;
	for(int i=1;i<n;i++){
		int cur = x + a[i];
		res += bs(i + 1,n,cur);
	}
	return res;
}

void solve(int n){
	LL base = (LL)n * (n - 1) / 2;
	base = base - (base + 1) / 2;
	//printf("%lld\n",base);
	sort(a+1,a+n+1);
	int l = 0,r = a[n] + 1,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		LL sum = get(n,mid);
		//printf("%d  %lld\n",mid,sum);
		if(sum < base)
			r = mid;
		else
			l = mid;
	}
	int ans;
	if(get(n,l) <= base)
		ans = l;
	else
		ans = r;
	printf("%d\n",ans);
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
