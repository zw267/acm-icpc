                                            
  //File Name: poj2774.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月29日 星期五 13时01分23秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define rank RANK

using namespace std;

const int MAXN = 200000 + 10;

struct Suffix{
	int s[MAXN];
	int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n;
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
			for(i=1;i<m;i++) c[i] += c[i-1];
			for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]] = y[i];
			swap(x,y);
			p = 1;
			x[sa[0]] = 0;
			for(i=1;i<n;i++)
				x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && 
						y[sa[i-1]+k] == y[sa[i]+k]) ? p-1:p++;
			if(p >= n) break;
			m = p;
		}
		n--;
	}
	void get_height(){
		int i,k = 0;
		for(i=1;i<n;i++) rank[sa[i]] = i;
		for(i=0;i<n;i++){
			if(k) k--;
			int j =sa[rank[i] - 1];
			while(s[i+k] == s[j+k])
				k++;
			height[rank[i]] = k;
		}
	}
}gao;

char str1[MAXN >> 1];
char str2[MAXN >> 1];

bool ok(int x,int y,int n,int m){
	if(0 <= x && x <= n -1 && n + 1 <= y && y <= n + m)
		return true;
	if(0 <= y && y <= n -1 && n + 1 <= x && x <= n + m)
		return true;
	return false;
}

void solve(){
	int n = strlen(str1);
	int m = strlen(str2);
	int tot = 0;
	for(int i=0;i<n;i++){
		gao.s[tot++] = str1[i];
	}
	gao.s[tot++] = (int)'$';
	//printf("%d\n",gao.s[tot-1]);
	for(int i=0;i<m;i++){
		gao.s[tot++] = str2[i];
	}
	gao.s[tot] = (int)'\0';
	gao.n = tot;
	gao.build_sa(128);
	gao.get_height();
	int ans = 0;
	for(int i=2;i<=tot;i++){
		if(ok(gao.sa[i],gao.sa[i-1],n,m))
			ans = max(ans,gao.height[i]);
	}
	printf("%d\n",ans);
	return ;
}

int main(){
	while(~scanf("%s",str1)){
		scanf("%s",str2);
		solve();
	}
	return 0;
}
