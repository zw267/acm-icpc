                                            
  //File Name: nod1249.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月17日 星期六 20时53分39秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 50000 + 10;
int a[MAXN],L[MAXN],R[MAXN],root[MAXN],sz;
struct Node{
	int ls,rs,w;
	Node(){ls = rs = w = 0;}
}node[MAXN * 18];
void ins(int &i,int l,int r,int x){
	node[++sz] = node[i];
	i = sz;
	node[i].w++;
	if(l == r) return ;
	int m = l + r >> 1;
	if(x <= m) ins(node[i].ls,l,m,x);
	else ins(node[i].rs,m+1,r,x);
}
int query(int i,int j,int l,int r,int x){
	if(r <= x) return node[j].w - node[i].w;
	if(l > x) return 0;
	int m = l + r >> 1;
	if(x <= m) return query(node[i].ls,node[j].ls,l,m,x);
	int t = node[node[j].ls].w - node[node[i].ls].w;
	return t + query(node[i].rs,node[j].rs,m+1,r,x);
}
LL solve(int n){
	L[n] = n,R[1] = 1;
	for(int i=n-1;i>0;i--){
		L[i] = i;
		while(L[i]+1<=n && a[L[i]+1]>=a[i])
			L[i] = L[L[i]+1];
	}
	for(int i=2;i<=n;i++){
		R[i] = i;
		while(R[i]-1>=1 && a[R[i]-1]<=a[i])
			R[i] = R[R[i]-1];
	}
	root[0] = sz = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		ins(root[i],1,n,R[i]);
	}
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans += query(root[i-1],root[L[i]],1,n,i);
	}
	return ans;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",a + i);
		printf("%lld\n",solve(n));
	}
	return 0;
}
