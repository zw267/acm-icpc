//线段树基础题，单点更新

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000+5;

int seg[MAXN << 2];
int val[MAXN];
int ans[MAXN];
int n;

inline double get(int i)
{
	double res = (n+1.0)/2 - i;
	return res >= 0 ?res:res * (-1.0);
}

void pushup(int rt)
{
	int l = seg[rt<<1];
	int r = seg[rt<<1|1];
	if(val[l] == val[r]){
		if(get(l) <= get(r))
			seg[rt] = l;
		else
			seg[rt] = r;
	}
	else if(val[l] < val[r])
		seg[rt] = l;
	else
		seg[rt] = r;
}

void build(int l,int r,int rt)
{
	seg[rt]=0;
	if(l == r){
		seg[rt] = l;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p,int add,int l,int r,int rt)
{
	if(l == r){
		val[l]++;
		return ;
	}
	int m=(l+r)>>1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

void solve(int num)
{
	build(1,n,1);

	for(int i=1;i<=num;i++){
		ans[i] = seg[1];
		update(seg[1],1,1,n,1);
	}

	for(int i=1;i<=num;i++){
		printf("%d\n",ans[i]);
	}

	return ;
}

int main()
{
	int num;
	scanf("%d %d",&num,&n);
	solve(num);
	return 0;
}
