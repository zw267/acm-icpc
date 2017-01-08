                                            
  //File Name: cf13E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月19日 星期二 22时52分23秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN];
int bel[MAXN];
int sum[MAXN];
int to[MAXN];
int end[MAXN];
int sz,num;

void build(int n){
	sz = (int)sqrt(n + 0.5);
	num = n / sz;
	if(n % sz)
		num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / sz;
	}
	for(int j=num-1,l,r;j>=0;j--){
		l = min(j * sz + 1,n);
		r = min(j * sz + sz ,n);
		for(int i=r;i>=l;i--){
			if(i + a[i] > r){
				to[i] = i + a[i];
				sum[i] = 1;
				end[i] = i;
			}
			else{
				to[i] = to[i + a[i]];
				end[i] = end[i + a[i]];
				sum[i] = sum[i + a[i]] + 1;
			}
		}
	}
}

void update(int p,int k,int n){
	int l = min(bel[p] * sz + 1, n);
	int r = min(bel[p] * sz + sz , n);
	a[p] = k;
	for(int i=p;i>=l;i--){
		if(a[i] + i > r){
			sum[i] = 1;
			end[i] = i;
			to[i] = a[i] + i;
		}
		else{
			sum[i] = sum[i + a[i]] + 1;
			end[i] = end[i + a[i]];
			to[i] = to[i + a[i]];
		}
	}
}

int query(int &p,int n){
	int res = 0,e;
	while(p <= n){
		res += sum[p];
		e = end[p];
		p = to[p];
	}
	printf("%d %d\n",e,res);
}

void solve(int n,int q){
	build(n);
	for(int i=1,op,p,k;i<=q;i++){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d",&p);
			query(p,n);
		}
		else{
			scanf("%d %d",&p,&k);
			update(p,k,n);
		}
	}
}

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n,q);
	return 0;
}
