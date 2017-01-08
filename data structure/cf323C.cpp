                                            
  //File Name: cf323C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月02日 星期五 23时38分56秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#define LL long long
#define fir first
#define sec second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int MAXN = 1000000 + 100;
pii pos[MAXN];
struct Node{
	int ls,rs,w;
	Node(){ls = rs = w = 0;}
}node[MAXN * 30];
int root[MAXN],sz,a[MAXN],n,ans;
void ins(int &i,int l,int r,int x){
	node[++sz] = node[i];
	i = sz;
	node[i].w++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(x <= mid) ins(node[i].ls,l,mid,x);
	else ins(node[i].rs,mid+1,r,x);
}
int query(int i,int j,int l,int r,int k){
	if(k >= r) return node[j].w - node[i].w;
	if(l == r) return 0;
	int mid = (l + r) >> 1;
	if(k <= mid) return query(node[i].ls,node[j].ls,l,mid,k);
	else{
		int t = node[node[j].ls].w - node[node[i].ls].w;
		return t + query(node[i].rs,node[j].rs,mid+1,r,k);
	}
}
int cal(int x){
	return (x - 1 + ans) % n + 1;
}
void solve(){
	for(int i=1;i<=n;i++)
		a[pos[i].fir] = pos[i].sec;
//	for(int i=1;i<=n;i++){
//		printf("%d  ",a[i]);
//	}
	root[0] = 0,sz = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		ins(root[i],1,n,a[i]);
	}
	int m,tmp,l1,r1,l2,r2;
	ans = 0;
	scanf("%d",&m);
	for(int i=1,u,v,x,y;i<=m;i++){
		scanf("%d %d %d %d",&u,&v,&x,&y);
		l1 = min(cal(u),cal(v));
		r1 = max(cal(u),cal(v));
		l2 = min(cal(x),cal(y));
		r2 = max(cal(x),cal(y));
//		printf("%d %d %d %d\n",l1,r1,l2,r2);
		ans = query(root[l1-1],root[r1],1,n,r2) - 
			query(root[l1-1],root[r1],1,n,l2 - 1);
		printf("%d\n",ans);
		ans++;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u;i<=n;i++){
		scanf("%d",&u);
		pos[u].fir = i;
	}
	for(int i=1,u;i<=n;i++){
		scanf("%d",&u);
		pos[u].sec = i;
	}
	solve();
	return 0;
}

