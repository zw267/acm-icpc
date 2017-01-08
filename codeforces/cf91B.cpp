                                            
  //File Name: cf91B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月30日 星期三 16时44分29秒


/*
segment tree
*/
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 1e5+5;
const int INF = 0x3f3f3f3f;

int a[MAXN];
int ans[MAXN];
int mi[MAXN << 2];

void pushup(int rt)
{
	mi[rt] = min(mi[rt<<1],mi[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	mi[rt] = INF;
	if(l == r){
		mi[rt] = a[l];
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p,int add,int l,int r,int rt)
{
	if(l == r){
		mi[rt] = add;
		return ;
	}
	int m=(l+r)>>1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

int query(int R,int p,int l,int r,int rt)
{
	if(l > R)
		return -1;
	if(mi[rt] >= p)
		return -1;
	if(l == r){
		return l;
	}
	int m = (l+r)>>1;
	int ret = query(R,p,lson);
	if(ret == -1) {
		ret = query(R,p,rson);
	}
	return ret;
}

void solve(int n)
{
	build(1,n,1);
	for(int i=1;i<=n;i++){
		int pos = query(i-1,a[i],1,n,1);
		if(pos == -1)
			ans[i] = -1;
		else
			ans[i] = i - pos - 1;
	}

	for(int i=n;i>1;i--)
		printf("%d ",ans[i]);
	printf("%d\n",ans[1]);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n;i>0;i--) {
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
