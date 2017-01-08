#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 1e5+10;

struct Seg
{
	int sum1,sum0,ly;
};
Seg seg[20][MAXN << 2];

LL pow2[20];
int a[MAXN];

void init_pow2()
{
	pow2[0]=1;
	for(int i=1;i<20;i++)
		pow2[i] = pow2[i-1] * 2;
}

void pushup(int pos,int rt)
{
	seg[pos][rt].sum1 = seg[pos][rt<<1].sum1 + seg[pos][rt<<1|1].sum1;
	seg[pos][rt].sum0 = seg[pos][rt<<1].sum0 + seg[pos][rt<<1|1].sum0; 
}

void pushdown(int pos,int rt)
{
	if(seg[pos][rt].ly ){
		seg[pos][rt<<1].ly ^= 1;
		seg[pos][rt<<1|1].ly ^= 1;
		swap(seg[pos][rt<<1].sum1,seg[pos][rt<<1].sum0);
		swap(seg[pos][rt<<1|1].sum1,seg[pos][rt<<1|1].sum0);
		seg[pos][rt].ly = 0;
	}
}

void build(int pos,int l,int r,int rt)
{
	seg[pos][rt].ly = 0;
	if(l == r){
		if(a[l] & (1<<pos))
			seg[pos][rt].sum1 = 1 , seg[pos][rt].sum0 = 0;
		else
			seg[pos][rt].sum0 = 1 , seg[pos][rt].sum1 = 0;		
		return ;
	}
	int m = (l + r) >>1;
	build(pos,lson);
	build(pos,rson);
	pushup(pos,rt);
}

void update(int pos,int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r){
		seg[pos][rt].ly ^= 1;
		swap(seg[pos][rt].sum1,seg[pos][rt].sum0);
		return ;
	}
	pushdown(pos,rt);
	//cout << "eeeeeeeeeeeeee" << endl;
	int m=(l+r)>>1;
	if(l<=m)
		update(pos,L,R,lson);
	if(R>m)
		update(pos,L,R,rson);
	pushup(pos,rt);
}

int query(int pos,int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
		return seg[pos][rt].sum1;
	pushdown(pos,rt);
	int m=(l+r)>>1;
	int ret = 0 ;
	if(L<=m)
		ret += query(pos,L,R,lson);
	if(R>m)
		ret += query(pos,L,R,rson);
	pushup(pos,rt);
	return ret;
}

void solve(int n)
{
	init_pow2();
	for(int i=0;i<20;i++)
		build(i,1,n,1);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int op;
		scanf("%d",&op);
		if(op == 1){
			int l,r;
			scanf("%d %d",&l,&r);
			LL ans = 0;
			for(int i=0;i<20;i++){
				ans = ans + pow2[i] * query(i,l,r,1,n,1);
			}
			cout << ans << endl;
		}
		else{
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			for(int i=0;i<20;i++){
				if(x & (1<<i)){
					update(i,l,r,1,n,1);
				}
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
