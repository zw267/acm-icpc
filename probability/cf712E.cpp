                                            
  //File Name: cf712E.cpp
  //Created Time: 2017年05月06日 星期六 21时23分06秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pdd pair<double,double>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
double p[MAXN],u[MAXN];
pdd seg[MAXN << 2];
pdd merge(const pdd &x,const pdd &y){
	pdd res;
	res.fir = x.fir + x.sec * y.fir;
	res.sec = x.sec * y.sec;
	return res;
}
void build(int l,int r,int rt){
	if(l == r){
		seg[rt] = make_pair(u[l],u[l]);
	}
	else{
		int mid = l + r >> 1;
		build(l,mid,rt << 1);
		build(mid + 1,r,rt << 1 | 1);
		seg[rt] = merge(seg[rt << 1],seg[rt << 1 | 1]);
	}
}
void update(int p,double add,int l,int r,int rt){
	if(l == r){
		seg[rt] = make_pair(add,add);
	}
	else{
		int mid = l + r >> 1;
		if(p <= mid) update(p,add,l,mid,rt << 1);
		else update(p,add,mid + 1,r,rt << 1 | 1);
		seg[rt] = merge(seg[rt << 1],seg[rt << 1 | 1]);
	}
}
pdd query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt];
	int mid = l + r >> 1;
	if(R <= mid) return query(L,R,l,mid,rt << 1);
	else if(L > mid) return query(L,R,mid + 1,r,rt << 1 | 1);
	pdd res1 = query(L,R,l,mid,rt << 1);
	pdd res2 = query(L,R,mid + 1,r,rt << 1 | 1);
	pdd res = merge(res1,res2);
	return res;
}
void solve(const int n,int m){
	for(int i=1;i<=n;++i)
		u[i] = (1.0 - p[i]) / p[i];
	build(1,n,1);
	int op,i,a,b;
	while(m--){
		scanf("%d",&op);
		if(op == 1){
			scanf("%d %d %d",&i,&a,&b);
			p[i] = (double)a / b;
			u[i] = (1.0 - p[i]) / p[i];
			update(i,u[i],1,n,1);
		}
		else{
			scanf("%d %d",&a,&b);
			pdd res = query(a,b,1,n,1);
			printf("%.10f\n",1.0 / (1.0 + res.fir));
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i(1),x,y;i<=n;++i){
		scanf("%d %d",&x,&y);
		p[i] = (double)x / y;
	}
	solve(n,m);
	return 0;
}

