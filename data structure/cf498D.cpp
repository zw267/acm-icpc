                                            
  //File Name: cf498D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月21日 星期四 09时32分33秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 3;

struct Seg{
	int mod[60];
};
Seg seg[MAXN << 2];
int a[MAXN];
char op[3];

void pushup(int rt){
	int now;
	for(int i=0;i<60;i++){
		now = (i + seg[rt<<1].mod[i]) % 60;
		seg[rt].mod[i] = seg[rt<<1].mod[i] + seg[rt<<1|1].mod[now];
	}
}

void build(int l,int r,int rt){
	if(l == r){
		for(int i=0;i<60;i++){
			if(i % a[l])
				seg[rt].mod[i] = 1;
			else
				seg[rt].mod[i] = 2;
		}
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p,int add,int l,int r,int rt){
	if(l == r){
		a[p] = add;
		for(int i=0;i<60;i++){
			if(i % a[l])
				seg[rt].mod[i] = 1;
			else
				seg[rt].mod[i] = 2;
		}
		return ;
	}
	int m = (l + r) >> 1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

int query(int L,int R,int t,int l,int r,int rt){
	if(L <= l && R >= r){
		return seg[rt].mod[t];
	}
	int m = (l + r) >> 1;
	if(R <= m)
		return query(L,R,t,lson);
	else if(L > m)
		return query(L,R,t,rson);
	
	int res = query(L,m,t,lson);
	int now = (t + res) % 60;
	res += query(m+1,R,now,rson);
	return res;
}

void solve(int n){
	build(1,n,1);
	int q;
	scanf("%d",&q);
	int u,v;
	for(int i=0;i<q;i++){
		scanf("%s",op);
		scanf("%d %d",&u,&v);
		if(op[0] == 'A'){
			printf("%d\n",query(u,v - 1,0,1,n,1));
		}
		else{
			update(u,v,1,n,1);
			a[u] = v;
		}
	}
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
