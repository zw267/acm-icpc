                                            
  //File Name: poj3415.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月29日 星期五 19时54分43秒
                                   

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>

#define rank RANK
#define LL long long

using namespace std;

const int MAXN = 200000 + 10;

struct Suffix{
	int s[MAXN],sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n;
	int rank[MAXN],height[MAXN];
	void build_sa(int m){
		n++;
		int i,*x = t,*y = t2;
		for(i=0;i<m;i++) c[i] = 0;
		for(i=0;i<n;i++) c[x[i]=s[i]]++;
		for(i=1;i<m;i++) c[i] += c[i - 1];
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
				x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] ==
						y[sa[i]+k]) ? p - 1 : p++;
			}
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
			while(s[i+k] == s[j+k])
				k++;
			height[rank[i]] = k;
		}
	}
}gao;

struct Node{
	int w,num;
	Node(int _w = 0,int _num = 0){
		w = _w,num = _num;
	}
};

char str1[MAXN >> 1];
char str2[MAXN >> 1];
Node _stack[MAXN * 10];
int _l,_r,K,len1,len2;

bool is(int x,int flag){
	if(flag == 1){
		if(len1 + 1 <= x && x <= len1 + len2)
			return true;
		return false;
	}
	else{
		if(0 <= x && x <= len1 - 1)
			return true;
		return false;
	}
}

void calc(LL &ans,int flag){
	Node now;
	LL cur = 0;
	for(int i=1;i<=gao.n;i++){
		if(gao.height[i] < K){
			_l = _r = 0;
			cur = 0;
			if(!is(gao.sa[i],flag)){
				_stack[_r++] = Node(MAXN,1);
				cur += (LL)(MAXN - K + 1);
			}
		}
		else{
			if(is(gao.sa[i],flag)){
				now.w = gao.height[i];
				now.num = 0;
				while(_l < _r && _stack[_r - 1].w >= now.w){
					now.num += _stack[_r - 1].num;
					cur -= (LL)(_stack[_r-1].w-K+1) * _stack[_r-1].num;
					_r--;
				}
				if(now.num){
					_stack[_r++] = now;
					cur += (LL)(now.w - K + 1) * now.num;
				}
				ans += cur;
				//for(int j=_l;j<_r;j++){
				//	ans += (LL)(_stack[j].w  - K + 1) * _stack[j].num;
				//}
			}
			else{
				now.w = gao.height[i];
				now.num = 0;
				while(_l < _r && _stack[_r - 1].w >= now.w){
					now.num += _stack[_r - 1].num;
					cur -= (LL)(_stack[_r-1].w-K+1) * _stack[_r-1].num;
					_r--;
				}
				if(now.num){
					_stack[_r++] = now;
					cur += (LL)(now.w-K+1)*now.num;
				}
				_stack[_r++] = Node(MAXN,1);
				cur += (LL)(MAXN-K+1);
			}
		}
	}
}

void solve(){
	len1 = strlen(str1);
	len2 = strlen(str2);
	int tot = 0;
	for(int i=0;i<len1;i++)
		gao.s[tot++] = str1[i];
	gao.s[tot++] = '$';
	for(int i=0;i<len2;i++)
		gao.s[tot++] = str2[i];
	gao.s[tot] = (int)'\0';
	gao.n = tot;
	gao.build_sa(128);
	gao.get_height();
	LL ans = 0;
	calc(ans,1);
	calc(ans,2);
	printf("%lld\n",ans);
	return ;
}

int main(){
	while(~scanf("%d",&K)){
		if(!K)  break;
		scanf("%s",str1);
		scanf("%s",str2);
		solve();
	}
	return 0;
}
