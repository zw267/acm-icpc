                                            
  //File Name: poj3104.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 18时40分39秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 100000 +5;

int a[MAXN];

bool ok(int n,int K,int x){
	LL res = 0;
	K--;
	for(int i=0;i<n;i++){
		if(a[i] <= x)
			continue;
		res += (LL)(a[i] - x) / K;
		if((a[i] - x) % K)
			res++;
	}
	if(res > x)
		return false;
	return true;
}

void solve(int n,int K,int ma){
	if(K == 1){
		printf("%d\n",ma);
		return ;
	}
	int l = 0,r = ma,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ok(n,K,mid))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n",r);
	return ;
}

int main(){
	int n,K;
	while(~scanf("%d",&n)){
		int ma = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] > ma)
				ma = a[i];
		}
		scanf("%d",&K);
		solve(n,K,ma);
	}
	return 0;
}
