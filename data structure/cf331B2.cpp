                                            
  //File Name: cf331B2.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月02日 星期二 23时52分02秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 300000 + 3;

int a[MAXN],p[MAXN],s[MAXN << 2];

void pushup(int l,int r,int rt){
	int mid = (l + r) >> 1;
	s[rt] = s[rt<<1] + s[rt<<1|1];
	if(p[mid] < p[mid + 1])
		s[rt]--;
}

void build(int l,int r,int rt){
	s[rt] = 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(l,r,rt);
}

void update(int pos,int add,int l,int r,int rt){
	if(l == r){
		s[rt] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(pos,add,lson);
	else update(pos,add,rson);
	pushup(l,r,rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return s[rt];
	int mid = (l + r) >> 1;
	if(R <= mid) return query(L,R,lson);
	else if(L > mid) return query(L,R,rson);
	else{
		int res = query(L,R,lson) + query(L,R,rson);
		if(p[mid] < p[mid + 1])
			res--;
		return res;
	}
}

void solve(int n){
	build(1,n,1);
	int op,x,y,q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d %d",&op,&x,&y);
		if(op == 1)
			printf("%d\n",query(x,y,1,n,1));
		else{
			p[a[x]] = y,p[a[y]] = x;
			update(a[x],y,1,n,1);
			update(a[y],x,1,n,1);
			swap(a[x],a[y]);
			//for(int i=1;i<=n;i++)
			//	printf("%d ",a[i]);
			//puts("");
			//for(int i=1;i<=n;i++)
			//	printf("%d ",p[i]);
			//puts("");
		}
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			p[a[i]] = i;
		}
		solve(n);
	}
	return 0;
}
