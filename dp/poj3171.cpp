                                            
  //File Name: poj3171.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月28日 星期一 21时33分58秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 86410;
const LL INF = 0x3f3f3f3f3f3f3f;

struct Node{
	int l,r,s;
};

Node node[10000 + 5];
LL mi[MAXN << 2];
LL f[MAXN];

void build(int l,int r,int rt){
	mi[rt] = INF;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	return ;
}

void pushup(int rt){
	mi[rt] = min(mi[rt<<1],mi[rt<<1|1]);
}

void update(int p,LL add,int l,int r,int rt){
	if(l == r){
		mi[rt] = min(mi[rt],add);
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

LL query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return mi[rt];
	int mid = (l + r) >> 1;
	LL res = INF;
	if(L <= mid)
		res = min(res,query(L,R,lson));
	if(R > mid)
		res = min(res,query(L,R,rson));
	return res;
}

bool cmp(Node x,Node y){
	if(x.r == y.r)
		return x.l < y.l;
	return x.r < y.r;
}

void solve(int N,int ma){
	build(1,ma,1);
	for(int i=0;i<=ma;i++)
		f[i] = INF;
	f[0] = 0;
	update(1,0,1,ma,1);
	sort(node+1,node+N+1,cmp);
	int pos = 1;
	for(int i=2;i<=ma;i++){
		while(pos <= N && i == node[pos].r){
			f[i] = min(f[i],query(node[pos].l-1,node[pos].r-1,1,ma,1) + node[pos].s);
			pos++;
		}
		if(f[i] < INF)
			update(i,f[i],1,ma,1);
	}
	if(f[ma] >= INF)
		puts("-1");
	else
		printf("%lld\n",f[ma]);
	return ;
}

int main(){
	int N,M,E;
	while(~scanf("%d %d %d",&N,&M,&E)){
		int base = M - 2;
		M -= base;
		E -= base;
		for(int i=1;i<=N;i++){
			scanf("%d %d %d",&node[i].l,&node[i].r,&node[i].s);
			node[i].l -= base;
			node[i].r -= base;
		}
		solve(N,E);
	}
	return 0;
}

