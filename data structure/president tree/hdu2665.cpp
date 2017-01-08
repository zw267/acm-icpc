                                            
  //File Name: hdu2665.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月17日 星期四 23时03分34秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#define hash hashhash

using namespace std;

const int MAXN = 100000+5;

struct Node{
	int sum,ls,rs;
	Node(int _sum = 0,int _ls = 0,int _rs = 0){
		sum = _sum;
		ls = _ls;
		rs = _rs;
	}
};
Node node[MAXN * 20];
int a[MAXN];
int root[MAXN];
int num[MAXN];
int hash[MAXN];
int tot,top,sz;

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

void update(int &i,int l,int r,int pos){
	node[++sz] = node[i];
	i = sz;
	node[sz].sum++;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(node[sz].ls,l,mid,pos);
	else
		update(node[sz].rs,mid+1,r,pos);
}

int query(int L,int R,int l,int r,int K){
	if(l == r)
		return l;
	int cur = node[node[R].ls].sum - node[node[L].ls].sum;
	int mid = (l + r) >> 1;
	if(cur >= K)
		return query(node[L].ls,node[R].ls,l,mid,K);
	else
		return query(node[L].rs,node[R].rs,mid+1,r,K - cur);	
}

void solve(int n,int q_num){
	hash_init();
	sz = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,tot,hash_find(a[i]));
	}
	for(int i=1,s,t,k;i<=q_num;i++){
		scanf("%d %d %d",&s,&t,&k);
		printf("%d\n",hash[query(root[s-1],root[t],1,tot,k)]);
	}
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d %d",&n,&m);
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n,m);
	}
	return 0;
}
