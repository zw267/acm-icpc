                                            
  //File Name: nod1105.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月12日 星期日 23时43分57秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 50000 + 3;

LL a[MAXN],b[MAXN];

LL bi(int n,LL x){
	if(b[n] <= x) return 0;
	if(b[1] > x) return n;
	int l = 1,r = n,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(b[mid] <= x)
			l = mid;
		else
			r = mid;
	}
	return n - r + 1;
}

LL get(int n,LL x){
	LL ans = 0;
	for(int i=1;i<=n;i++){
		//printf("now = %lld  %lld\n",now,bi(n,now));
		ans += bi(n,x / a[i]);
	}
	return ans;
}

LL solve(int n,LL K){
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	LL r = a[n] > b[n] ? a[n] * a[n] : b[n] * b[n];
	LL l = a[1] < b[1] ? a[1] * a[1] - 1 : b[1] * b[1] - 1;
	//printf("%lld %lld\n",l,r);
	LL mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		//printf("mid = %lld  %lld\n",mid,get(n,mid));
		if(get(n,mid) >= K)
			l = mid;
		else
			r = mid;
	}
	return r;
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=1;i<=n;i++){
			scanf("%lld %lld",&a[i],&b[i]);
		}
		printf("%lld\n",solve(n,k));
	}
	return 0;
}
