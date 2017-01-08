                                            
  //File Name: uva12003.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月12日 星期二 14时17分45秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 300000 + 10;

int a[MAXN];
int b[MAXN];
int bel[MAXN];
int s,num;

void init(int n){
	for(int i=1;i<=n;i++){
		b[i] = a[i];
	}
	int l,r;
	for(int i=0;i<num;i++){
		l = i * s + 1;
		r = min(i * s + s,n);
		sort(b + l,b + r + 1);
	}
}

void update(int p,int cur,int n){
	int l = bel[p] * s + 1;
	int r = min(bel[p] * s + s ,n);
	int x = l;
	while(x < r && b[x] < a[p])
		x++;
	a[p] = cur;
	b[x] = cur;
	while(x > l && b[x] < b[x - 1]){
		swap(b[x],b[x - 1]);
		x--;
	}
	while(x < r && b[x] > b[x + 1]){
		swap(b[x],b[x + 1]);
		x++;
	}
}

int bs(int x,int v,int n){
	int l = x * s + 1;
	int r = min(x * s + s,n);
	if(b[r] < v)
		return r - l + 1;
	if(b[l] >= v)
		return 0;
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(b[mid] >= v)
			r = mid;
		else
			l = mid;
	}
	return l - x * s;
}

int query(int l,int r,int v,int n){
	int res = 0;
	if(bel[l] == bel[r]){
		for(int i=l;i<=r;i++){
			if(a[i] < v)
				res++;
		}
		return res;
	}
	res += query(l,bel[l] * s + s,v,n);
	res += query(bel[r] * s + 1,r,v,n);
	for(int i=bel[l] + 1;i < bel[r];i++){
		res += bs(i,v,n);
	}
	return res;
}

void solve(int n,int q,LL U){
	s = (int)sqrt(n + 0.5);
	num = n / s;
	if(n % s)
		num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / s;
	}
	init(n);
	for(int i=1,l,r,v,p;i<=q;i++){
		scanf("%d %d %d %d",&l,&r,&v,&p);
		LL cur = (LL)query(l,r,v,n);
		cur = cur * U / (r - l + 1);
		update(p,cur,n);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return ;
}

int main(){
	int n,m,U;
	while(~scanf("%d %d %d",&n,&m,&U)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n,m,U);
	}
	return 0;
}
