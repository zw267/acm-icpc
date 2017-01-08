                                            
  //File Name: poj2104.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月18日 星期五 00时15分00秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define hash hashhash

using namespace std;

const int MAXN = 100000+5;

struct Node{
	int w,ls,rs;
	Node(){
		w = ls = rs = 0;
	}
};
Node node[MAXN * 20];
int a[MAXN];
int root[MAXN];
int num[MAXN];
int hash[MAXN];
int top,tot,sz;

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
	node[sz].w++;
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
	int cur = node[node[R].ls].w - node[node[L].ls].w;
	int mid = (l + r) >> 1;
	if(cur >= K)
		return query(node[L].ls,node[R].ls,l,mid,K);
	else
		return query(node[L].rs,node[R].rs,mid+1,r,K-cur);
}

void solve(int n,int que_num){
	hash_init();
	sz = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,tot,hash_find(a[i]));
	}
	for(int i=1,s,t,k;i<=que_num;i++){
		scanf("%d %d %d",&s,&t,&k);
		printf("%d\n",hash[query(root[s-1],root[t],1,tot,k)]);
	}
	return ;
}

int main(){
	int n,q;
	while(~scanf("%d %d",&n,&q)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n,q);
	}
	return 0;
}
