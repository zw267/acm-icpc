                                            
  //File Name: poj3261.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月28日 星期四 19时55分14秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define rank RANK
#define hash HASH

using namespace std;

const int MAXN = 20000 + 5;

struct Suffix{
	int n;
	int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],s[MAXN];
	int rank[MAXN],height[MAXN];
	void build_sa(int m){
		n++;
		int i,*x = t,*y = t2;
		for(i=0;i<m;i++) c[i] = 0;
		for(i=0;i<n;i++) c[x[i]=s[i]]++;
		for(i=1;i<m;i++) c[i] += c[i-1];
		for(i=n-1;i>=0;i--) sa[--c[x[i]]] = i;
		for(int k=1;k<=n;k<<=1){
			int p = 0;
			for(i=n-k;i<n;i++) y[p++] = i;
			for(i=0;i<n;i++) if(sa[i] >= k) y[p++] = sa[i] - k;
			for(i=0;i<m;i++) c[i] = 0;
			for(i=0;i<n;i++) c[x[y[i]]]++;
			for(i=1;i<m;i++) c[i] += c[i -1];
			for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
			swap(x,y);
			p = 1;
			x[sa[0]] = 0;
			for(i=1;i<n;i++) 
				x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && 
						y[sa[i-1]+k] == y[sa[i]+k])? p - 1:p++;
			if(p >= n) break;
			m = p;
		}
		n--;
	}

	void get_height(){
		int i,k = 0;
		for(i=1;i<=n;i++)
			rank[sa[i]] = i;
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
int top,tot;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++){
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
	}
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

int ok(int n,int x){
	int ans = 1, now = 1;
	for(int i=1;i<=n;i++){
		if(gao.height[i] < x){
			ans = max(ans,now);
			now = 1;
		}
		else
			now++;
	}
	ans = max(ans,now);
	return ans;
}

void solve(const int n,const int sum){
	hash_init();
	int ma = 0;
	for(int i=0;i<n;i++){
		a[i] = hash_find(a[i]);
		gao.s[i] = a[i];
		ma = max(ma,a[i]);
	}
	gao.n = n;
	gao.build_sa(ma + 1);
	gao.get_height();
	int l = 1, r = n, mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ok(n,mid) >= sum)
			l = mid;
		else
			r = mid;
	}
	printf("%d\n",l);
	return ;
}

int main(){
	int n,sum;
	while(~scanf("%d %d",&n,&sum)){
		top = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n,sum);
	}
	return 0;
}

