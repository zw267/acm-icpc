                                            
  //File Name: cf150C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月05日 星期五 09时08分19秒
                                   

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 150000+3;

double x[MAXN],p[MAXN];

struct Seg{
	double lm,rm,s,m;
	void reset(){
		lm = max(0.,lm),rm = max(0.,rm),m = max(0.,m);
	}
	Seg(double _lm = 0.,double _rm = 0.,double _s = 0.,double _m = 0.){
		lm = _lm,rm = _rm,s = _s,m = _m;
		reset();
	}
	Seg operator +(const Seg&b) const{
		Seg c,a = *this;
		c.s = a.s + b.s;
		c.lm = max(a.lm,a.s + b.lm);
		c.rm = max(b.rm,b.s + a.rm);
		c.m = max(max(a.m,b.m),a.rm + b.lm);
		c.reset();
		return c;
	}
}seg[MAXN << 2];
void build(int l,int r,int rt){
	if(l == r){
		seg[rt] = (Seg){x[l],x[l],x[l],x[l]};
		return ;
	}
	int mid = l + r >> 1;
	build(lson);
	build(rson);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}
Seg query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt];
	int mid = l + r >> 1;
	if(R <= mid) return query(L,R,lson);
	if(L > mid) return query(L,R,rson);
	return query(L,R,lson) + query(L,R,rson);
}

double solve(int n,int m){
	double ans = 0.;
	build(1,n,1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		ans += query(u,v-1,1,n,1).m;
	}
	return ans;
}

int main(){
	int n,c,m;
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;i++) scanf("%lf",&x[i]);
	for(int i=1;i<n;i++) scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++) x[i] = (x[i+1] - x[i]) / 2. - p[i] / 100. * c;
	//puts("eeeeeeeeeeeeeeeeeeeeeeee");
	printf("%.10f\n",solve(n,m));
	return 0;
}
