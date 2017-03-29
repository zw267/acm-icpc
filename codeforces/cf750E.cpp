                                            
  //File Name: cf750E.cpp
  //Created Time: 2017年03月29日 星期三 15时28分01秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
const int INF = 0x3f3f3f3f;
struct Cost{
	int mat[5][5];
	Cost operator+(const Cost &b) const {
		Cost res;
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				res.mat[i][j] = INF;
		for(int k=0;k<5;++k){
			for(int i=0;i<5;++i){
				for(int j=0;j<5;++j)
					res.mat[i][j] = min(res.mat[i][j],mat[i][k] + b.mat[k][j]);
			}
		}
		return res;
	}
};
Cost seg[MAXN << 2];
char str[MAXN];
void build(int l,int r,int rt){
	if(l == r){
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				seg[rt].mat[i][j] = (i == j ? 0 : INF);
		int c = str[l] - '0';
		if(c == 2){
			seg[rt].mat[0][1] = 0;
			seg[rt].mat[0][0] = 1;
		}
		else if(c == 0){
			seg[rt].mat[1][2] = 0;
			seg[rt].mat[1][1] = 1;
		}
		else if(c == 1){
			seg[rt].mat[2][3] = 0;
			seg[rt].mat[2][2] = 1;
		}
		else if(c == 6){
			seg[rt].mat[3][3] = 1;
			seg[rt].mat[4][4] = 1;
		}
		else if(c == 7){
			seg[rt].mat[3][4] = 0;
		}
		return ;
	}
	int m = l + r >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
	seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}
Cost query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt];
	int m = l + r >> 1;
	if(R <= m) return query(L,R,l,m,rt << 1);
	if(L > m) return query(L,R,m + 1,r,rt << 1 | 1);
	Cost r1 = query(L,R,l,m,rt << 1);
	Cost r2 = query(L,R,m + 1,r,rt << 1 | 1);
	return r1 + r2;
}
void solve(int n,int q){
	build(1,n,1);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int ans = query(l,r,1,n,1).mat[0][4];
		if(ans == INF) ans = -1;
		printf("%d\n",ans);
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	scanf("%s",str + 1);
	solve(n,q);
	return 0;
}
