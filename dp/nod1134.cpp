                                            
  //File Name: nod1134.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月28日 星期六 20时45分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 50000 + 5;
const int INF = 0x3f3f3f3f;

int d[MAXN];
int a[MAXN];

int bs(int l,int r,int x){
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(d[mid] < x) l = mid;
		else r = mid;
	}
	return l;
}

int solve(int n){
	int len = 0;
	d[0] = -INF;
	for(int i=1,j;i<=n;i++){
		if(a[i] > d[len]){
			d[++len] = a[i];
		}
		j = bs(0,len,a[i]);
		d[++j] = a[i];
	}
	return len;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",solve(n));
	}
	return 0;
}
