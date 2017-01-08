                                            
  //File Name: cf515E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月01日 星期五 17时32分48秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <math.h>

#define LL long long
#define mp make_pair
#define fi first
#define se second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000+3;

LL d[MAXN << 1];
LL h[MAXN << 1];
LL sum[MAXN << 1];
pair<int,int> ma[MAXN << 3];

LL get(int l,int r)
{
	return 2 * h[l] + 2 * h[r] + sum[r-1] - sum[l -1];
}

pair<int,int> judge(int l1,int r1,int l2,int r2)
{
	int res_l,res_r;

	if(l1 == r1 && l2 == r2){
		res_l = l1;
		res_r = r2;
	}
	else if(l1 == r1 && l2 != r2) {
		res_l = l2;
		res_r = r2;
		if(get(r1,l2) > get(res_l,res_r)){
			res_l = r1;
			res_r = l2;
		}
		if(get(r1,r2) > get(res_l,res_r)){
			res_l = r1;
			res_r = r2;
		}
	}
	else if(l1 != r1 && l2 == r2) {
		res_l = l1;
		res_r = r1;
		if(get(l1,l2) > get(res_l,res_r)){
			res_l = l1;
			res_r = l2;
		}
		if(get(r1,l2) > get(res_l,res_r)){
			res_l = r1;
			res_r = l2;
		}
	}
	else {
		res_l = l1;
		res_r = r1;
		if(get(l2,r2) > get(res_l,res_r)){
			res_l = l2;
			res_r = r2;
		}
		if(get(l1,l2) > get(res_l,res_r)){
			res_l = l1;
			res_r = l2;
		}
		if(get(l1,r2) > get(res_l,res_r)){
			res_l = l1;
			res_l = r2;
		}
		if(get(r1,l2) > get(res_l,res_r)){
			res_l = r1;
			res_r = l2;
		}
		if(get(r1,r2) > get(res_l,res_r)){
			res_l = r1;
			res_r = r2;
		}
	}
	return mp(res_l,res_r);
}

void pushup(int rt)
{
	int l1 = ma[rt<<1].fi;
	int r1 = ma[rt<<1].se;
	int l2 = ma[rt<<1|1].fi;
	int r2 = ma[rt<<1|1].se;
	ma[rt] = judge(l1,r1,l2,r2);
}

void build(int l,int r,int rt)
{
	if(l == r){
		ma[rt] = mp(l,l);
		return ;
	}
	int m = (l+r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

pair<int,int> query(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r){
		return ma[rt];
	}
	int m = (l+r) >> 1;
	if(L > m)
		return query(L,R,rson);
	if(R <= m)
		return query(L,R,lson);
	pair<int,int> res1 = query(L,R,lson);
	pair<int,int> res2 = query(L,R,rson);
	return judge(res1.fi,res1.se,res2.fi,res2.se);
}

void solve(int n,int q)
{
	for(int i=1;i<n;i++){
		d[i+n] = d[i];
		h[i+n] = h[i];
	}
	sum[0] = 0;
	d[0] = 0;
	h[0] = 0;
	for(int i=1;i<2*n;i++){
		sum[i] = sum[i-1] + d[i];
	}

	build(1,2*n-1,1);
	for(int i=0;i<q;i++) {
		int l,r;
		pair<int,int> cur;
		LL res = -1;
		scanf("%d %d",&l,&r);
		if(l <= r){
			cur = query(r+1,l-1+n,1,2*n-1,1);
			res = get(cur.fi,cur.se);
		}
		else {
			cur = query(r+1,l-1,1,2*n-1,1);
			res = get(cur.fi,cur.se);
		}
		printf("%lld\n",res);
	}
	return ;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&d[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",&h[i]);
	}
	solve(n,m);
	return 0;
}
