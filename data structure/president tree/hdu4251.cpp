                                            
  //File Name: hdu4251.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月04日 星期一 20时41分55秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define w(i) node[(i)].w
#define ls(i) node[(i)].ls
#define rs(i) node[(i)].rs
#define hash hashhash

using namespace std;

const int MAXN = 100005;

struct Node{
	int ls,rs,w;
	Node(){
		ls = rs = w = 0;
	}
};
Node node[MAXN * 18];
int root[MAXN];
int a[MAXN];
int num[MAXN];
int hash[MAXN];
int top,tot,sz;

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

int get(int l,int r){
	return (r - l + 1) / 2 + 1;
}

void update(int &rt,int l,int r,int p){
	node[++sz] = node[rt];
	rt = sz;
	w(rt)++;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(ls(rt),l,mid,p);
	else
		update(rs(rt),mid+1,r,p);
}

int query(int L,int R,int l,int r,int k){
	if(l == r)
		return l;
	int cur = w(ls(R)) - w(ls(L));
	int mid = (l + r) >> 1;
	if(cur >= k)
		return query(ls(L),ls(R),l,mid,k);
	else
		return query(rs(L),rs(R),mid+1,r,k-cur);
}

void solve(int n){
	hash_init();
	sz = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,tot,hash_find(a[i]));
	}
	int q;
	scanf("%d",&q);
	for(int i=0,l,r;i<q;i++){
		scanf("%d %d",&l,&r);
		printf("%d\n",hash[query(root[l-1],root[r],1,tot,get(l,r))]);
	}
	return ;
}

int main(){
	int n;
	int cas = 1;
	while(~scanf("%d",&n)){
		printf("Case %d:\n",cas++);
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n);
	}
	return 0;
}
