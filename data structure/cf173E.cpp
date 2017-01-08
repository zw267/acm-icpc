                                            
  //File Name: cf173E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月05日 星期五 21时54分22秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#define LL long long
#define hash _hash_
#define fir first
#define sec second
#define pii pair<int,int>
#define mp make_pair
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int MAXN = 100000 + 10;

int num[MAXN],hash[MAXN],tot,top;
int ans[MAXN];
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
		mid = l + r >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
pii a[MAXN],g[MAXN];
struct Query{
	int l,r,v,t;
	Query(){}
	Query(int _l,int _r,int _v,int _t){
		l = _l,r = _r,v = _v,t = _t;
	}
	bool operator < (const Query &b) const{
		return v > b.v;
	}
}que[MAXN];
struct Node{
	int a,v,f;
	Node(){}
	Node(int _a,int _v,int _f){
		a = _a,v = _v,f = _f;
	}
	bool operator<(const Node&b)const{
		return v > b.v;
	}
}node[MAXN];
int bit[MAXN];
void update(int x,int add){
	for(;x<=tot;x += x & -x)
		bit[x] += add;
}
int query(int x){
	int res = 0;
	for(;x>0;x -= x& -x)
		res += bit[x];
	return res;
}
int seg[MAXN << 2];
void pushup(int rt){
	seg[rt] = max(seg[rt<<1],seg[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l == r) seg[rt] = 0;
	int mid = l + r >> 1;
	build(lson);
	build(rson);
}
void update(int p,int add,int l,int r,int rt){
	if(l == r){
		seg[rt] = max(seg[rt],add);
		return ;
	}
	int mid = l + r >> 1;
	if(p <= mid) update(p,add,lson);
	else update(p,add,rson);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt];
	int mid = l + r >> 1,res = 0;
	if(L <= mid) res = max(res,query(L,R,lson));
	if(R > mid) res = max(res,query(L,R,rson));
	return res;
}
void cal_que(pii u,pii v,int i,int &K){
	if(u.sec > v.sec) swap(u,v);
	que[i].l = v.sec - K;
	que[i].r = u.sec + K;
	que[i].t = i;
	que[i].v = max(u.fir,v.fir);
}
void cal_g(int n,int K){
	memset(bit,0,sizeof bit);
	sort(a+1,a+n+1);
	for(int i=1;i<=tot;i++) g[i].fir = 0;
	int now = 1;
	for(int i=1,l,r,f;i<=n;i++){
		while(now <= n && a[now].fir <= a[i].fir){
			update(a[now].sec,1);
			now++;
		}
		l = hash_find(hash[a[i].sec]-K);
		if(hash[l] < hash[a[i].sec] - K) l++;
		r = hash_find(hash[a[i].sec]+K);
		if(hash[r] > hash[a[i].sec]+K) r--;
		//printf("i = %d l = %d r = %d\n",a[i].sec,l,r);
		if(l <= r){
			f = query(r) - query(l-1);
			if(g[a[i].sec].fir <= f){
				g[a[i].sec].fir = f;
				g[a[i].sec].sec = a[i].fir;
			}
		}
	}
}
int cal_node(){
	int len = 0;
	for(int i=1;i<=tot;i++){
		if(g[i].fir == 0) continue;
		node[++len].a = i;
		node[len].v = g[i].sec;
		node[len].f = g[i].fir;
	}
	return len;
}
void cal_ans(int n,int m){
	sort(que+1,que+m+1);
	sort(node+1,node+n+1);
	int u = 1;
	for(int i=1;i<=m;i++){
		while(u <= n && node[u].v >= que[i].v){
			update(node[u].a,node[u].f,1,tot,1);
			u++;
		}
		if(que[i].l > que[i].r) ans[que[i].t] = 0;
		else ans[que[i].t] = query(que[i].l,que[i].r,1,tot,1);
	}
}
void solve(int n,int K,int q){
	hash_init();
	for(int i=1;i<=n;i++){
		a[i].sec = hash_find(a[i].sec);
	}
	for(int i=1,u;i<=q;i++){
		u = hash_find(que[i].l);
		if(hash[u] < que[i].l) que[i].l = u + 1;
		else que[i].l = u;
		u = hash_find(que[i].r);
		if(hash[u] > que[i].r) que[i].r = u - 1;
		else que[i].r = u;
	}
	cal_g(n,K);
	//for(int i=1;i<=tot;i++)
	//	printf("a = %d g = %d v = %d\n",i,g[i].fir,g[i].sec);
	int len = cal_node();
	cal_ans(len,q);
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i] > 1 ? ans[i] : -1);
}
int main(){
	int n,K,q;
	top = 0;
	//num[++top] = 0;
	num[++top] = -1000000001;
	num[++top] = 2000000001;
	scanf("%d %d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].fir);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].sec),num[++top] = a[i].sec;
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d %d",&u,&v);
		cal_que(a[u],a[v],i,K);
	}
	solve(n,K,q);
	return 0;
}
