                                            
  //File Name: cf566D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月21日 星期一 21时00分04秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstdlib>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 200000+5;

int fa[MAXN];
int seg[MAXN << 2];

void init(int n){
	for(int i=1;i<=n;i++)
		fa[i] = i;
}

void pushup(int rt){
	if(seg[rt<<1] == seg[rt<<1|1])
		seg[rt] = seg[rt<<1];
	else
		seg[rt] = 0;
}

void build(int l,int r,int rt){
	seg[rt] = 0;
	if(l == r){
		seg[rt] = l;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

int find_fa(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find_fa(fa[x]);
}

int merge(int L,int R,int l,int r,int rt){
	if(seg[rt])
		return seg[rt];
	int m = (l + r) >> 1;
	int x,y;
	if(L <= m && R > m){
		x = merge(L,R,lson);
		y = merge(L,R,rson);
		x = find_fa(x);
		y = find_fa(y);
		fa[x] = y;
		if(L <= l && R >= r)
			seg[rt] = y;
	}
	else if(R <= m){
		return merge(L,R,lson);
	}
	else
		return merge(L,R,rson);
}

void solve(int n){
	init(n);
	build(1,n,1);
	int q;
	scanf("%d",&q);
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d %d %d",&op,&x,&y);
		if(op == 1){
			int fa_x = find_fa(x);
			int fa_y = find_fa(y);
			fa[fa_x] = fa_y;
		}
		else if(op == 2){
			merge(x,y,1,n,1);
		}
		else{
			x = find_fa(x);
			y = find_fa(y);
			if(x == y)
				puts("YES");
			else
				puts("NO");
		}
	}
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
