                                            
  //File Name: cf374D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月14日 星期五 21时16分46秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN = 1000000 + 5;
int val[MAXN],sum[MAXN << 2],a[MAXN],now = 1;
void pushup(int rt){
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int p,int add,int l,int r,int rt){
	if(l == r){
		sum[rt] = 1,val[l] = add;
		return ;
	}
	int m = l + r >> 1;
	if(p <= m) update(p,add,lson);
	else update(p,add,rson);
	pushup(rt);
}
void query(int p,int l,int r,int rt){
	if(l == r){
		sum[rt] = 0;
		return ;
	}
	int m = l + r >> 1;
	if(sum[rt<<1] >= p)
		query(p,lson);
	else
		query(p-sum[rt<<1],rson);
	pushup(rt);
}
void output(int l,int r,int rt){
	if(l == r){
		printf("%d",val[l]);
		return ;
	}
	int m = l + r >> 1;
	if(sum[rt<<1])
		output(lson);
	if(sum[rt<<1|1])
		output(rson);
}
int bs(int l,int r,int x){
	if(a[r] <= x) return r;
	if(a[l] > x) return -1;
	while(r - l > 1){
		int m = l + r >> 1;
		if(a[m] <= x) l = m + 1;
		else
			r = m - 1;
	}
	if(a[r] <= x) return r;
	return l;
}
void solve(int n,int m){
	for(int i=1,u;i<=n;i++){
		scanf("%d",&u);
		if(u >= 0)
			update(now++,u,1,n,1);
		else{
			int len = bs(1,m,sum[1]);
			for(int j=len;j>0;j--){
				query(a[j],1,n,1);
			}
		}
	}
	if(sum[1] == 0) puts("Poor stack!");
	output(1,n,1);
	puts("");
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",a + i);
	solve(n,m);
	return 0;	
}
