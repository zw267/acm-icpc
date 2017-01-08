                                            
  //File Name: poj3273.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月25日 星期五 17时43分12秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN];

bool ok(int n,int m,int x){
	int cur_sum = a[0];
	int res = 1;
	int pos = 1;
	while(true){
		while(pos < n && cur_sum + a[pos] <= x){
			cur_sum += a[pos++];
		}
		if(pos == n)
			break;
		res++;
		cur_sum = a[pos++];
	}
	if(res <= m)
		return true;
	return false;
}

void solve(int n,int m,int ma,int sum){
	int l = ma - 1,r = sum, mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ok(n,m,mid))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n",r);
	return ;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		int ma = 0,sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] > ma)
				ma = a[i];
			sum += a[i];
		}
		solve(n,m,ma,sum);
	}
	return 0;
}
