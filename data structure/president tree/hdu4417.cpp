                                            
  //File Name: hdu4417.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月18日 星期五 01时08分36秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
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
int num[MAXN << 1];
int hash[MAXN << 1];
int sz,tot,top;
int que[MAXN][3];

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

void update(int &i,int l,int r,int x){
	node[++sz] = node[i];
	i = sz;
	node[sz].w++;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(x <= mid)
		update(node[sz].ls,l,mid,x);
	else
		update(node[sz].rs,mid+1,r,x);
}

int query(int L,int R,int l,int r,int x){
	if(l > x || r < x)
		return 0;
	if(l == r)
		return node[R].w - node[L].w;
	int res = 0;
	int mid = (l + r) >> 1;
	if(mid <= x){
		res += node[node[R].ls].w - node[node[L].ls].w;
		res += query(node[L].rs,node[R].rs,mid+1,r,x);
	}
	else{
		res += query(node[L].ls,node[R].ls,l,mid,x);
	}
	return res;
}

void solve(int n,int q_num){
	hash_init();
	sz = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,tot,hash_find(a[i]));
	}

	for(int i=1;i<=q_num;i++){
		printf("%d\n",query(root[que[i][0]-1],root[que[i][1]],1,tot,hash_find(que[i][2])));
	}
	return ;
}

int main(){
	int test,cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case %d:\n",cas++);
		int n,m;
		top = 0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&que[i][0],&que[i][1],&que[i][2]);
			que[i][0]++;
			que[i][1]++;
			num[++top] = que[i][2];
		}
		solve(n,m);
	}
	return 0;
}
