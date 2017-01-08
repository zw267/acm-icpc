                                            
  //File Name: poj3581.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月30日 星期六 00时43分57秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define rank RANK
#define hash HASH

using namespace std;

const int MAXN = 200000 + 6;

struct Suffix{
	int s[MAXN],sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n;
	int rank[MAXN],height[MAXN];
	void build_sa(int m){
		n++;
		int i,*x = t,*y = t2;
		for(i=0;i<m;i++) c[i] = 0;
		for(i=0;i<n;i++) c[x[i] = s[i]]++;
		for(i=1;i<m;i++) c[i] += c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[i]]] = i;
		for(int k=1;k<=n;k<<=1){
			int p = 0;
			for(i=n-k;i<n;i++) y[p++] = i;
			for(i=0;i<n;i++) if(sa[i] >= k) y[p++] = sa[i] - k;
			for(i=0;i<m;i++) c[i] = 0;
			for(i=0;i<n;i++) c[x[y[i]]]++;
			for(i=1;i<m;i++) c[i] += c[i-1];
			for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
			swap(x,y);
			p = 1;
			x[sa[0]] = 0;
			for(i=1;i<n;i++){
				x[sa[i]] = (y[sa[i-1]] == y[sa[i]] &&
						y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1:p++;
			}
			if(p >=n ) break;
			m = p;
		}
		n--;
	}
	void get_height(){
		int i,k = 0;
		for(i=1;i<=n;i++) rank[sa[i]] = i;
		for(i=0;i<n;i++){
			if(k) k--;
			int j = sa[rank[i] - 1];
			while(s[i + k] == s[j + k])
				k++;
			height[rank[i]] = k;
		}
	}
}gao;

int num[MAXN];
int hash[MAXN];
int a[MAXN];
int tot,top;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}

int hash_find(int x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

void solve(const int n){
	hash_init();
	int ma = -MAXN;
	for(int i=0;i<n;i++){
		gao.s[i] = hash_find(a[n - 1 - i]);
		ma = max(ma,gao.s[i]);
	}
	gao.n = n;
	gao.s[n] = 0;
	gao.build_sa(ma + 1);
	int p = 1;
	while(gao.sa[p] == 0 || gao.sa[p] == 1)
		p++;
	p = gao.sa[p];
	//printf("p = %d\n",p);
	for(int i=n-p-1;i>=0;i--)
		printf("%d\n",a[i]);
	gao.n = p;
	gao.s[p] = 0;
	int pre = p;
	gao.build_sa(ma + 1);
	p = 1;
	while(gao.sa[p] == 0)
		p++;
	p = gao.sa[p];
	for(int i=n-p-1;i>=n-pre;i--)
		printf("%d\n",a[i]);
	for(int i=n-1;i>=n-p;i--)
		printf("%d\n",a[i]);
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	top = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		num[++top] = a[i];
	}
	solve(n);
	return 0;
}

