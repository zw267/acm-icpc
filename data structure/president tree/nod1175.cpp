                                            
  //File Name: nod1175.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月28日 星期六 21时48分29秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define hash _HASH

using namespace std;

const int MAXN = 50000 + 5;

struct Node{
	int ls,rs,w;
	Node(int _w = 0,int _ls = 0,int _rs = 0){
		w = _w,ls = _ls,rs = _rs;
	}
}node[MAXN * 18];

int root[MAXN],a[MAXN],tot;

int num[MAXN],hash[MAXN],total,top;

void hash_init(){
	sort(num+1,num+top+1);
	total = 0;
	hash[++total] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++total] = num[i];
}

int hash_find(int x){
	int l = 1,r = total,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void update(int &rt,int l,int r,int p){
	node[++tot] = node[rt];
	rt = tot;
	node[rt].w += 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(p <= mid) update(node[rt].ls,l,mid,p);
	else update(node[rt].rs,mid+1,r,p);
}

int query(int L,int R,int l,int r,int k){
	if(l == r) return l;
	int t = node[node[R].rs].w - node[node[L].rs].w;
	int mid = (l + r) >> 1;
	if(k <= t)
		return query(node[L].rs,node[R].rs,mid+1,r,k);
	else
		return query(node[L].ls,node[R].ls,l,mid,k - t);
}

void solve(int n){
	hash_init();
	for(int i=1;i<=n;i++){
		a[i] = hash_find(a[i]);
	}
	tot = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,total,a[i]);
	}
	int q;
	scanf("%d",&q);
	for(int i=1,l,r,k;i<=q;i++){
		scanf("%d %d %d",&l,&r,&k);
		l++,r++;
		printf("%d\n",hash[query(root[l-1],root[r],1,total,k)]);
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n);
	}
	return 0;
}
