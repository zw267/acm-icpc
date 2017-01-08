                                            
  //File Name: 51nod1472.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月19日 星期六 17时05分03秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 300000 + 5;
struct Node{
	int ls,rs,w;
}node[MAXN * 27];
LL a[MAXN],sum[MAXN];
int root[MAXN],sz = 0;
int L[MAXN],R[MAXN];
void update(int &i,int l,int r,int x){
	node[++sz] = node[i];
	i = sz;
	node[i].w++;
	if(l == r) return ;
	int m = l + r >> 1;
	if(x <= m) update(node[i].ls,l,m,x);
	else update(node[i].rs,m+1,r,x);
}
int query(int i,int j,int l,int r,int x){
	if(l == r) return node[j].w - node[i].w;
	int m = l + r >> 1;
	if(x <= m) return query(node[i].ls,node[j].ls,l,m,x);
	else return query(node[i].rs,node[j].rs,m+1,r,x);
}
LL solve(int n,int p){
	for(int i=1;i<=n;i++){
		L[i] = i;
		while(L[i] > 1 && a[L[i] - 1] <= a[i])
			L[i] = L[L[i] - 1];
	}
	for(int i=n;i>0;i--){
		R[i] = i;
		while(R[i] < n && a[R[i]+1] < a[i])
			R[i] = R[R[i] + 1];
	}
//	for(int i=1;i<=n;i++)
//		printf("i = %d l = %d r = %d\n",i,L[i],R[i]);
	root[0] = root[1] = 0;
	update(root[1],0,p-1,0);
	for(int i=1;i<=n;i++){
		a[i] %= p;
		sum[i] = (sum[i-1] + a[i]) % p;
		root[i + 1] = root[i];
		update(root[i + 1],0,p-1,sum[i]);
	}
	LL res = 0;
	for(int i=1;i<=n;i++){
		int l = L[i],r = R[i];
//		res = 0;
		if(r - i < i - l){
			for(int j=i;j<=r;j++){
				int now = (sum[j] - a[i] + p) % p;
				int tmp = query(root[l-1],root[i],0,p-1,now);
				res += tmp;
			}
		}
		else{
			for(int j=i;j>=l;j--){
				int now = (a[i] + sum[j - 1]) % p;
				int tmp = query(root[i],root[r+1],0,p-1,now);
				res += tmp;
			}
		}
//		printf("i = %d res = %lld\n",i,res);
	}
	return res - n;
}
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",a + i);
	printf("%lld\n",solve(n,p));
	return 0;
}
