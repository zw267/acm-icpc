                                            
  //File Name: cf283E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月06日 星期六 19时05分19秒
                                
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stdlib.h>
#define LL long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define hash _hash_
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 1000000001;
int a[MAXN],g[MAXN];
pii que[MAXN];
struct Node{
	int l,r;
	Node(){};
	Node(int _l,int _r){
		l = _l,r = _r;
	}
	bool operator < (const Node &b) const {
		return r > b.r;
	}
};
struct Seg{
	int s[2],ly;
}seg[MAXN << 2];
void pushup(int rt){
	for(int i=0;i<2;i++)
		seg[rt].s[i] = seg[rt<<1].s[i] + seg[rt<<1|1].s[i];
}
void pushdown(int rt){
	if(seg[rt].ly){
		seg[rt<<1].ly ^= 1;
		seg[rt<<1|1].ly ^= 1;
		swap(seg[rt<<1].s[0],seg[rt<<1].s[1]);
		swap(seg[rt<<1|1].s[0],seg[rt<<1|1].s[1]);
		seg[rt].ly = 0;
	}
}
void build(int l,int r,int rt){
	seg[rt].ly = 0;
	if(l == r){
		seg[rt].s[1] = 1;
		seg[rt].s[0] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		seg[rt].ly ^= 1;
		swap(seg[rt].s[0],seg[rt].s[1]);
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) update(L,R,lson);
	if(R > mid) update(L,R,rson);
	pushup(rt);
}
int query(int L,int R,int c,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt].s[c];
	pushdown(rt);
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid) res += query(L,R,c,lson);
	if(R > mid) res += query(L,R,c,rson);
	pushup(rt);
	return res;
}
LL solve(const int n,const int m){
	build(1,n,1);
	priority_queue<Node> rem;
	Node v;
	sort(que+1,que+m+1);
	memset(g,0,sizeof(g));
	int u = 1;
	for(int i=1;i<=n;i++){
		while(!rem.empty()){
			v = rem.top();
			if(v.r < i){
				update(v.l,v.r,1,n,1);
				rem.pop();
			}
			else break;
		}
		while(u <= m && que[u].fi <= i){
			if(que[u].se >= i){
				update(que[u].fi,que[u].se,1,n,1);
				rem.push((Node){que[u].fi,que[u].se});
			}
			u++;
		}
		if(i > 1) g[i] += query(1,i-1,1,1,n,1);
		if(i < n) g[i] += query(i+1,n,0,1,n,1);
	}
	//for(int i=1;i<=n;i++)
	//	printf("g = %d\n",g[i]);
	LL ans = (LL)n * (n - 1) * (n - 2) / 6;
	for(int i=1;i<=n;i++)
		ans -= (LL)g[i] * (g[i] - 1) / 2;
	return ans;
}
int main(){
	int n,m,tot = 0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		u = lower_bound(a+1,a+n+1,u) - a;
		v = upper_bound(a+1,a+n+1,v) -a - 1;
		if(u > v) continue;
		que[++tot] = mp(u,v);
	}
	cout << solve(n,tot) << endl;
	return 0;
}
