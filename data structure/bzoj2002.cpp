                                            
  //File Name: bzoj2002.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月07日 星期四 20时00分25秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

const int MAXN = 200000 + 3;

int a[MAXN];
int to[MAXN];
int sum[MAXN];

void build(int l,int r){
	for(int i=r;i>=l;i--){
		if(i + a[i] > r){
			to[i] = i + a[i];
			sum[i] = 1;
		}
		else{
			to[i] = to[i+a[i]];
			sum[i] = sum[i+a[i]] + 1;
		}
	}
}

int query(int p,int n){
	int res = 0;
	while(p < n){
		res += sum[p];
		p = to[p];
	}
	return res;
}

void update(int p,int k,int s,int n){
	int l = p / s * s;
	int r = min(l + s - 1,n-1);
	a[p] = k;
	for(int i=p;i>=l;i--){
		if(i + a[i] > r){
			to[i] = i + a[i];
			sum[i] = 1;
		}
		else{
			to[i] = to[i+a[i]];
			sum[i] = sum[i+a[i]] + 1;
		}
	}
}

void solve(int n){
	int s = (int)sqrt(n + 0.5);
	int num = n / s;
	if(n % s)
		num++;
	//if(num * s < n)
	//	puts("eeeeeeeeee");
	//else
	//	puts("good");
	for(int i=num-1;i>=0;i--){
		build(i * s,min(i * s + s - 1,n - 1));
	}
	int q;
	scanf("%d",&q);
	for(int i=0,op,p,k;i<q;i++){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d",&p);
			printf("%d\n",query(p,n));
		}
		else{
			scanf("%d %d",&p,&k);
			update(p,k,s,n);
		}
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
