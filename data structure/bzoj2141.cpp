                                            
  //File Name: bzoj2141.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月09日 星期六 21时40分30秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <math.h>

#define ls(i) node[(i)].ls
#define rs(i) node[(i)].rs
#define w(i) node[(i)].w
#define hash hashhash

using namespace std;

const int MAXN = 20000 + 5;

struct Node{
	int ls,rs,w;
	Node(){
		ls = rs = w = 0;
	}
};
Node node[10000000];
int root[MAXN];
int h[MAXN];
int num[MAXN];
int hash[MAXN];
int top,tot,sz;
int L[30],R[30],tot_l,tot_r;
int bit[MAXN];

inline int lb(int x){return x & (-x);}

void update_bit(int p,int add){
	while(p <= tot){
		bit[p] += add;
		p += lb(p);
	}
}

int query_bit(int p){
	int res = 0;
	while(p > 0){
		res += bit[p];
		p -= lb(p);
	}
	return res;
}

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
	int l = 1, r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

void update(int &rt,int l,int r,int p,int add){
	node[++sz] = node[rt];
	rt = sz;
	w(rt) += add;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(ls(rt),l,mid,p,add);
	else
		update(rs(rt),mid+1,r,p,add);
}

int query_more(int l,int r,int k){
	if(l == r){
		if(l == k)
			return 0;
		int suml = 0,sumr = 0;
		for(int i=0;i<tot_l;i++)
			suml += w(L[i]);
		for(int i=0;i<tot_r;i++)
			sumr += w(R[i]);
		return sumr - suml;
	}
	int res = 0,suml = 0,sumr = 0;
	int mid = (l + r) >> 1;
	if(k <= mid){
		for(int i=0;i<tot_l;i++)
			suml += w(rs(L[i]));
		for(int i=0;i<tot_r;i++)
			sumr += w(rs(R[i]));
		res = sumr - suml;
		for(int i=0;i<tot_l;i++)
			L[i] = ls(L[i]);
		for(int i=0;i<tot_r;i++)
			R[i] = ls(R[i]);
		return res + query_more(l,mid,k);
	}
	else{
		for(int i=0;i<tot_l;i++)
			L[i] = rs(L[i]);
		for(int i=0;i<tot_r;i++)
			R[i] = rs(R[i]);
		return query_more(mid+1,r,k);
	}
}

int query_less(int l,int r,int k){
	if(l == r){
		if(l == k)
			return 0;
		int suml = 0,sumr = 0;
		for(int i=0;i<tot_l;i++)
			suml += w(L[i]);
		for(int i=0;i<tot_r;i++)
			sumr += w(R[i]);
		return sumr - suml;
	}
	int res = 0,suml = 0,sumr = 0;
	int mid = (l + r) >> 1;
	if(k > mid){
		for(int i=0;i<tot_l;i++)
			suml += w(ls(L[i]));
		for(int i=0;i<tot_r;i++)
			sumr += w(ls(R[i]));
		res = sumr - suml;
		for(int i=0;i<tot_l;i++)
			L[i] = rs(L[i]);
		for(int i=0;i<tot_r;i++)
			R[i] = rs(R[i]);
		return res + query_less(mid+1,r,k);
	}
	else{
		for(int i=0;i<tot_l;i++)
			L[i] = ls(L[i]);
		for(int i=0;i<tot_r;i++)
			R[i] = ls(R[i]);
		return query_less(l,mid,k);
	}
}

void init(int u,int v){
	tot_l = tot_r = 0;
	for(int i=u;i>0;i-=lb(i))
		L[tot_l++] = root[i];
	for(int i=v;i>0;i-=lb(i))
		R[tot_r++] = root[i];
}

void solve(int n){
	hash_init();
	for(int i=1;i<=n;i++)
		h[i] = hash_find(h[i]);
	memset(bit,0,sizeof bit);
	int ans = 0;
	for(int i=1;i<=n;i++){
		update_bit(h[i],1);
		ans += query_bit(tot) - query_bit(h[i]);
	}
	printf("%d\n",ans);
	memset(root,0,sizeof root);
	sz = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=lb(j))
			update(root[j],1,tot,h[i],1);
	}
	int q;
	scanf("%d",&q);
	for(int j=1,u,v;j<=q;j++){
		scanf("%d %d",&u,&v);
		if(u > v)
			swap(u,v);
		if(u + 1 <= v - 1){
			init(u,v - 1);
			ans -= query_less(1,tot,h[u]);
			init(u,v - 1);
			ans += query_more(1,tot,h[u]);
			init(u,v - 1);
			ans -= query_more(1,tot,h[v]);
			init(u,v - 1);
			ans += query_less(1,tot,h[v]);
		}
		if(h[u] < h[v])
			ans++;
		else if(h[u] > h[v])
			ans--;
		printf("%d\n",ans);
		for(int i=u;i<=n;i+=lb(i))
			update(root[i],1,tot,h[u],-1);
		for(int i=v;i<=n;i+=lb(i))
			update(root[i],1,tot,h[v],-1);
		for(int i=u;i<=n;i+=lb(i))
			update(root[i],1,tot,h[v],1);
		for(int i=v;i<=n;i+=lb(i))
			update(root[i],1,tot,h[u],1);
		swap(h[u],h[v]);
	}
	return ;	
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
			num[++top] = h[i];
		}
		solve(n);
	}
	return 0;
}
