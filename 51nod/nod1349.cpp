                                            
  //File Name: nod1349.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月16日 星期四 11时56分45秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>

#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second

using namespace std;

const int MAXN = 100000 + 3;

struct Seg{
	int l,r;
	LL s;
}seg[MAXN << 2];

pii que[MAXN],a[MAXN];

LL ans[MAXN];


void pushup(int l,int r,int rt){
	int mid = (l + r) >> 1;
	int ls = rt<<1,rs = rt<<1|1;
	seg[rt].s = seg[ls].s + seg[rs].s;
	if(seg[ls].r == mid + 1 || seg[rs].l == mid){
		seg[rt].l = seg[ls].l;
		seg[rt].r = seg[rs].r;
	}
	else{
		seg[rt].s += (LL)(mid - seg[ls].r + 1) * (seg[rs].l - mid);
		if(seg[ls].l < seg[ls].r)
			seg[rt].l = seg[ls].l;
		else
			seg[rt].l = seg[rs].l;
		if(seg[rs].r > seg[rs].l)
			seg[rt].r = seg[rs].r;
		else
			seg[rt].r = seg[ls].r;
	}
}

void build(int l,int r,int rt){
	seg[rt].s = 0;
	seg[rt].l = l - 1;
	seg[rt].r = r + 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	//pushup(l,r,rt);
}

void update(int p,int l,int r,int rt){
	if(l == r){
		seg[rt].s = 1;
		seg[rt].l = seg[rt].r = l;
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(p,lson);
	else
		update(p,rson);
	pushup(l,r,rt);
}

void solve(int n,int Q){
	sort(que+1,que+Q+1);
	sort(a+1,a+n+1);
	build(1,n,1);
	int now = 1;
	for(int i=1;i<=Q;i++){
		while(now <= n && a[now].fir < que[i].fir){
			update(a[now].sec,1,n,1);
			now++;
		}
		//printf("%lld\n",seg[1].s);
		ans[que[i].sec] = (LL)n * (n + 1) / 2 - seg[1].s;
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].fir);
			a[i].sec = i;
		}
		int Q;
		scanf("%d",&Q);
		for(int i=1;i<=Q;i++){
			scanf("%d",&que[i].fir);
			que[i].sec = i;
		}
		solve(n,Q);
		for(int i=1;i<=Q;i++)
			printf("%lld\n",ans[i]);
	}
	return 0;
}
