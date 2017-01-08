                                            
  //File Name: spoj_disubstr.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月28日 星期四 22时30分53秒
                                   

#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>

#define rank Rank

using namespace std;

const int MAXN = 1000 + 3;

struct Suffix{
	int s[MAXN];
	int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n;
	int rank[MAXN],height[MAXN];
	void build_sa(int m){
		n++;
		int i,*x = t,*y = t2;
		for(i=0;i<m;i++) c[i] = 0;
		for(i=0;i<n;i++) c[x[i] = s[i]]++;
		for(i=1;i<m;i++) c[i] += c[i - 1];
		for(i=n-1;i>=0;i--) sa[--c[x[i]]] = i;
		for(int k=1;k<=n;k<<=1){
			int p = 0;
			for(i=n-k;i<n;i++) y[p++] = i;
			for(i=0;i<n;i++) if(sa[i] >= k) y[p++] = sa[i] - k;
			for(i=0;i<m;i++) c[i] = 0;
			for(i=0;i<n;i++) c[x[y[i]]]++;
			for(i=1;i<m;i++) c[i] += c[i - 1];
			for(i=n-1;i>=0;i--) 
				sa[--c[x[y[i]]]] = y[i];
			swap(x,y);
			p = 1;
			x[sa[0]] = 0;
			for(i=1;i<n;i++)
				x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && 
						y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1: p++;
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

char str[MAXN];

void solve(){
	int n = strlen(str);
	gao.n = n;
	for(int i=0;i<=n;i++){
		gao.s[i] = str[i];
	}
	gao.build_sa(128);
	gao.get_height();
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += n - gao.sa[i] - gao.height[i];
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",str);
		solve();
	}
	return 0;
}
