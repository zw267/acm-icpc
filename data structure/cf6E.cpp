                                            
  //File Name: cf6E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月02日 星期四 20时17分20秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define right _right

const int MAXN = 100000 + 3;
const int INF = 0x3f3f3f3f;

struct Seg{
	int ma,mi;
}seg[MAXN << 2];

int a[MAXN];
int right[MAXN];
int ans[MAXN];

void pushup(int rt){
	if(seg[rt<<1].mi <= seg[rt<<1|1].mi)
		seg[rt].mi = seg[rt<<1].mi;
	else
		seg[rt].mi = seg[rt<<1|1].mi;
	if(seg[rt<<1].ma > seg[rt<<1|1].ma)
		seg[rt].ma = seg[rt<<1].ma;
	else
		seg[rt].ma = seg[rt<<1|1].ma;

}

void build(int l,int r,int rt){
	if(l == r){
		seg[rt].mi = seg[rt].ma = a[l];
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

int query_max(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt].ma;
	int m = (l + r) >> 1;
	int res = -INF;
	if(L <= m)	res = max(res,query_max(L,R,lson));
	if(R > m) res = max(res,query_max(L,R,rson));
	return res;
}

int query_min(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt].mi;
	int m = (l + r) >> 1;
	int res = INF;
	if(L <= m) res = min(res,query_min(L,R,lson));
	if(R > m) res = min(res,query_min(L,R,rson));
	return res;	
}

int get(int l,int r,int k){
	int L = l, n = r;
	if(query_max(l,r,1,n,1) - query_min(l,r,1,n,1) <= k)
		return r;
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(query_max(L,mid,1,n,1) - query_min(L,mid,1,n,1) <= k)
			l = mid;
		else
			r = mid;
	}
	return l;
}

void solve(int n,int k){
	build(1,n,1);
	for(int i=1;i<=n;i++){
		right[i] = get(i,n,k);
	}
	int ans_len = 0,tot = 0;
	for(int i=1;i<=n;i++){
		if(right[i] - i + 1 > ans_len)
			ans_len = right[i] - i + 1;
	}
	for(int i=1;i<=n;i++){
		if(right[i] - i + 1 == ans_len)
			ans[tot++] = i;
	}
	printf("%d %d\n",ans_len,tot);
	for(int i=0;i<tot;i++){
		printf("%d %d\n",ans[i],right[ans[i]]);
	}
}

int main(){
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n,k);
	}
	return 0;
}
