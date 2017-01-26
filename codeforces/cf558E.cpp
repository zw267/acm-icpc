                                            
  //File Name: cf558E.cpp
  //Created Time: 2017年01月16日 星期一 22时51分08秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN = 100000 + 2;
struct Seg{
	int s[26],ly;
}seg[MAXN << 2];
char str[MAXN];
int sum[26];
void pushup(int rt){
	for(int i=0;i<26;++i)
		seg[rt].s[i] = seg[rt<<1].s[i] + seg[rt<<1|1].s[i];
}
void pushdown(int l,int r,int rt){
	int &ly = seg[rt].ly;
	if(ly == -1) return ;
	int m = l + r >> 1;
	seg[rt<<1].ly = seg[rt<<1|1].ly = ly;
	for(int i=0;i<26;++i)
		seg[rt<<1].s[i] = seg[rt<<1|1].s[i] = 0;
	seg[rt<<1].s[ly] = m - l + 1;
	seg[rt<<1|1].s[ly] = r - m;
	ly = -1;
}
void build(int l,int r,int rt){
	seg[rt].ly = -1;
	fill(seg[rt].s,seg[rt].s + 26,0);
	if(l == r){
		seg[rt].s[str[l] - 'a'] = 1;
		return ;
	}
	int m = l + r >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		for(int i=0;i<26;++i)
			seg[rt].s[i] = 0;
		seg[rt].s[add] = r - l + 1;
		seg[rt].ly = add;
		return ;
	}
	pushdown(l,r,rt);
	int m = l + r >> 1;
	if(L <= m)
		update(L,R,add,lson);
	if(R > m)
		update(L,R,add,rson);
	pushup(rt);
}
int query(int L,int R,int x,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt].s[x];
	pushdown(l,r,rt);
	int m = l + r >> 1;
	int res = 0;
	if(L <= m)
		res += query(L,R,x,lson);
	if(R > m)
		res += query(L,R,x,rson);
	pushup(rt);
	return res;
}
void output(int l,int r,int rt){
	if(l == r){
		int u = -1;
		for(int i=0;i<26;++i)
			if(seg[rt].s[i])
				u = i;
		printf("%c",u + 'a');
		return ;
	}
	pushdown(l,r,rt);
	int m = l + r >> 1;
	output(lson);
	output(rson);
}
void solve(const int n,int q){
	build(1,n,1);
	int l,r,k;
	while(q--){
		scanf("%d %d %d",&l,&r,&k);
		for(int i=0;i<26;++i)
			sum[i] = query(l,r,i,1,n,1);
		if(k){
			for(int i=0;i<26;++i){
				r = l + sum[i] - 1;
				if(l <= r){
					update(l,r,i,1,n,1);
					l = r + 1;
				}
			}
		}
		else{
			for(int i=25;i>=0;--i){
				r = l + sum[i] - 1;
				if(l <= r){
					update(l,r,i,1,n,1);
					l = r + 1;
				}
			}
		}
//		output(1,n,1);
//		puts("");
	}
	output(1,n,1);
	puts("");
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	scanf("%s",str + 1);
	solve(n,q);
	return 0;
}
