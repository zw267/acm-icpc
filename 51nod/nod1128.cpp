                                            
  //File Name: nod1128.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月16日 星期四 00时08分03秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 50000 + 3;
const int INF = 0x3f3f3f3f;

LL a[MAXN];

int ok(LL ma,int n){
	int ans = 0;
	LL now = 0;
	for(int i=1;i<=n;i++){
		if(a[i] > ma) return INF;
		if(now + a[i] > ma){
			now = a[i];
			ans++;
		}
		else
			now += a[i];
	}
	return ans + 1;
}

LL solve(int n,int k){
	LL l = INF,r = 0,mid;
	for(int i=1;i<=n;i++){
		if(a[i] < l) l = a[i];
		r += a[i];
	}
	l--;
	while(r - l > 1){
		mid = (l + r) >> 1;
		//printf("mid = %lld %d\n",mid,ok(mid,n));
		if(ok(mid,n) <= k)
			r = mid;
		else 
			l = mid;
	}
	return r;
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		printf("%lld\n",solve(n,k));
	}
	return 0;
}

