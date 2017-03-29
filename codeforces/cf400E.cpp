                                            
  //File Name: cf400E.cpp
  //Created Time: 2017年03月29日 星期三 16时08分51秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 2;
const int N = 17;
inline LL cal(int x){
//	return x;
	return 1LL * x * (x + 1) / 2;
}
struct Node{
	int vl,vr;
	LL vs;
	Node(){}
	Node(int _vl,int _vr,LL _vs):vl(_vl),vr(_vr),vs(_vs){}
	Node merge(const Node &a,const Node &b,const int l,const int r){
		Node res(-1,-1,0);
		res.vl = a.vl,res.vr = b.vr;
		res.vs = a.vs + b.vs;
		if(a.vr != -1 && b.vl != -1){
			int m = l + r >> 1;
			res.vs -= cal(m - a.vr + 1);
			res.vs -= cal(b.vl - m);
			res.vs += cal(b.vl - a.vr + 1);
			if(a.vl >= a.vr)
				res.vl = b.vl;
			if(b.vr != -1 && b.vl >= b.vr)
				res.vr = a.vr;
		}
		return res;
	}
};
Node seg[N][MAXN << 2];
int a[MAXN];
LL pow2[N];
void build(int p,int l,int r,int rt){
	if(l == r){
		if(a[l] & (1 << p))
			seg[p][rt] = Node(l,l,1);
		else
			seg[p][rt] = Node(-1,-1,0);
		return ;
	}
	int m = l + r >> 1;
	build(p,l,m,rt << 1);
	build(p,m + 1,r,rt << 1 | 1);
	seg[p][rt] = seg[p][rt].merge(seg[p][rt << 1],seg[p][rt << 1 | 1],l,r);
//	if(!p){
//		printf("l = %d r = %d\n",l,r);
//		printf("vl = %d vr = %d vs = %lld\n",seg[p][rt].vl,seg[p][rt].vr,seg[p][rt].vs);
//	}

}
void update(int p,int pos,int add,int l,int r,int rt){
	if(l == r){
		if(add == 0)  seg[p][rt] = Node(-1,-1,0);
		else seg[p][rt] = Node(l,l,1);
		return ;
	}
	int m = l + r >> 1;
	if(pos <= m) update(p,pos,add,l,m,rt << 1);
	else update(p,pos,add,m + 1,r,rt << 1 | 1);
	seg[p][rt] = seg[p][rt].merge(seg[p][rt << 1],seg[p][rt << 1 | 1],l,r);
}
void solve(int n,int q){
	pow2[0] = 1;
	for(int i=1;i<N;++i)
		pow2[i] = pow2[i - 1] * 2;
	for(int i=0;i<N;++i)
		build(i,1,n,1);
//	for(int i=0;i<1;++i)
//		printf("i = %d %lld\n",i,seg[i][1].vs);
	while(q--){
		int p,v;
		scanf("%d %d",&p,&v);
		for(int i=0;i<N;++i){
			if((a[p] & (1 << i)) && (v & (1 << i)) == 0)
				update(i,p,0,1,n,1);
			else if((a[p] & (1 << i)) == 0 && (v & (1 << i)))
				update(i,p,1,1,n,1);
		}
		a[p] = v;
		LL ans = 0;
		for(int i=0;i<N;++i)
			ans += seg[i][1].vs * pow2[i];
		printf("%lld\n",ans);
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a + i);
	solve(n,q);
	return 0;
}
