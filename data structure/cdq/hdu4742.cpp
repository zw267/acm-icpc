                                            
  //File Name: hdu4742.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月29日 星期五 15时49分08秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

#define LL long long
#define hash _hash_
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define v first
#define s second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

const int MAXN = 100000 + 5;
const int MOD = 1 << 30;

int h_num[MAXN],hash[MAXN],tot,top;

void hash_init(){
	sort(h_num+1,h_num+top+1);
	tot = 0;
	hash[++tot] = h_num[1];
	for(int i=2;i<=top;i++){
		if(h_num[i] != h_num[i-1])
			hash[++tot] = h_num[i];
	}
}

int hash_find(int x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

struct Query{
	int t,x,y,z;
	Query(int _t = 0,int _x = 0,int _y = 0,int _z = 0){
		t = _t,x = _x,y = _y,z = _z;
	}
	bool operator<(const Query&a)const{
		if(y == a.y) return z < a.z;
		return y < a.y;
	}
}que[MAXN],q1[MAXN],q2[MAXN];

int f[MAXN],g[MAXN];
pii seg[MAXN << 2];
int ly[MAXN << 2];

void pushup(int rt){
	if(seg[rt<<1].v == seg[rt<<1|1].v){
		seg[rt].v = seg[rt<<1].v;
		seg[rt].s = (0LL + seg[rt<<1].s + seg[rt<<1|1].s) % MOD;
	}
	else if(seg[rt<<1].v > seg[rt<<1|1].v){
		seg[rt].v = seg[rt<<1].v,seg[rt].s = seg[rt<<1].s;
	}
	else{
		seg[rt].v = seg[rt<<1|1].v,seg[rt].s = seg[rt<<1|1].s;
	}
}

void pushdown(int rt){
	if(ly[rt]){
		seg[rt<<1] = mp(0,0);
		seg[rt<<1|1] = mp(0,0);
		ly[rt<<1] = ly[rt<<1|1] = 1;
		ly[rt] = 0;
	}
}

void build(int l,int r,int rt){
	seg[rt].v = 0,seg[rt].s = 0;
	ly[rt] = 0;
	if(l == r) return ;
	int mid =(l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int p,int v,int s,int l,int r,int rt){
	if(l == r){
		if(v > seg[rt].v){
			seg[rt].v = v,seg[rt].s = s;
		}
		else if(v == seg[rt].v){
			seg[rt].s = (0LL + seg[rt].s + s) % MOD;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if(p <= mid)
		update(p,v,s,lson);
	else
		update(p,v,s,rson);
	pushup(rt);
}

pii query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt];
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(R <= mid)
		return query(L,R,lson);
	else if(L > mid)
		return query(L,R,rson);
	else{
		pii res1 = query(L,R,lson);
		pii res2 = query(L,R,rson);
		pii res;
		if(res1.v == res2.v){
			res.v = res1.v;
			res.s = (0LL + res1.s + res2.s) % MOD;
		}
		else if(res1.v > res2.v) res = res1;
		else res = res2;
		return res;
	}
}

bool cmpx(Query &a,Query &b){
	return a.x < b.x;
}

void cdq(int l,int r){
	if(l >= r)  return ;
	int mid = (l + r) >> 1;
	cdq(l,mid);
	int s1 = 0,s2 = 0;
	for(int i=l;i<=mid;i++)
		q1[s1++] = que[i];
	for(int i=mid+1;i<=r;i++)
		q2[s2++] = que[i];
	sort(q1,q1+s1);
	sort(q2,q2+s2);
	int u = 0;
	for(int i=0;i<s2;i++){
		while(u < s1 && q1[u].y <= q2[i].y){
			update(q1[u].z,f[q1[u].t],g[q1[u].t],1,tot,1);
			u++;
		}
		pii now = query(1,q2[i].z,1,tot,1);
		if(now.v + 1 > f[q2[i].t])
			f[q2[i].t] = now.v + 1,g[q2[i].t] = now.s;
		else if(now.v + 1 == f[q2[i].t])
			g[q2[i].t] = (0LL + g[q2[i].t] + now.s) % MOD;
	}
	ly[1] = 1;
	seg[1] = mp(0,0);
	cdq(mid+1,r);
}

void solve(int n){
	hash_init();
	for(int i=1;i<=n;i++)
		que[i].z = hash_find(que[i].z);
	for(int i=1;i<=n;i++)
		f[i] = g[i] = 1;
	build(1,tot,1);
	sort(que+1,que+n+1,cmpx);
	cdq(1,n);
	//for(int i=1;i<n;i++){
	//	printf("f = %d g = %d\n",f[i],g[i]);
	//}
	printf("%d %d\n",f[n]-1,g[n]);
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		top = 0;
		scanf("%d",&n);
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%d %d %d",&x,&y,&z);
			h_num[++top] = z;
			que[i] = (Query){i,x,y,z};
		}
		que[++n] = (Query){n,MOD + 1,MOD + 1,MOD + 1};
		h_num[++top] = MOD + 1;
		solve(n);
	}
	return 0;
}

