                                            
  //File Name: cf484E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月01日 星期日 21时49分08秒
                                   

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 10;

struct Segtree{
	int l,r,sl,sr,w;
}seg[MAXN << 2];

Segtree merge(Segtree x,Segtree y){
	Segtree res;
	res.w = max(x.w,y.w);
	res.sl = x.sl;
	res.sr = y.sr;
	if(x.w == x.sr - x.sl + 1)
		x.l = x.sr, x.r = x.sl;
	if(y.w == y.sr - y.sl + 1)
		y.l = y.sr, y.r = y.sl;
	if(x.sr + 1 == y.sl && x.r > 0 && y.l > 0){
		res.w = max(res.w,y.l - x.r + 1);
		if(x.l >= x.r)
			x.l = y.l;
		if(y.r > 0 && y.r <= y.l)
			y.r = x.r;
	}
	res.l = x.l;
	res.r = y.r;
	return res;
}

void build(int l,int r,int rt){
	if(l == r){
		seg[rt].l = seg[rt].r = -1;
		seg[rt].sl = seg[rt].sr = l;
		seg[rt].w = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	seg[rt] = merge(seg[rt<<1],seg[rt<<1|1]);
}

void update(int p,int add,int rt){
	if(seg[rt].sl == seg[rt].sr){
		if(add){
			seg[rt].l = seg[rt].r = seg[rt].sl;
			seg[rt].w = 1;
		}
		else{
			seg[rt].l = seg[rt].r = -1;
			seg[rt].w = 0;
		}
		return ;
	}
	int mid = (seg[rt].sl + seg[rt].sr) >> 1;
	if(p <= mid)
		update(p,add,rt<<1);
	else
		update(p,add,rt<<1|1);
	seg[rt] = merge(seg[rt<<1],seg[rt<<1|1]);
}

Segtree query(int L,int R,int rt){
	if(L <= seg[rt].sl && R >= seg[rt].sr){
		return seg[rt];
	}
	int mid = (seg[rt].sl + seg[rt].sr) >> 1;
	if(R <= mid)
		return query(L,R,rt<<1);
	else if(L > mid)
		return query(L,R,rt<<1|1);
	return merge(query(L,R,rt<<1),query(L,R,rt<<1|1));
}

struct Query{
	int l,r,w,t;
	Query(int _l = 0,int _r = 0,int _w = 0,int _t = 0){
		l = _l,r = _r,w = _w,t = _t;
	}
}q[MAXN],q2[MAXN];

int ans[MAXN];
int now,N;

struct Node{
	int h,id;
	bool operator < (const Node &x) const{
		return h < x.h;
	}
}node[MAXN];

void solve(int head,int tail,int l,int r){
	//printf("%d %d %d %d\n",head,tail,l,r);
	if(head > tail || l > r) return ;
	if(l == r){
		for(int i=head;i<=tail;i++){
			ans[q[i].t] = l;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	while(now > 0 && node[now].h > mid){
		update(node[now].id,1,1);
		now--;
	}
	while(now+1 <= N && node[now + 1].h <= mid){
		update(node[now+1].id,0,1);
		now++;
	}
	//printf("mid = %d now = %d\n",mid,now);
	int len1 = head,len2 = tail;
	for(int i=head;i<=tail;i++){
		//printf("w = %d\n",query(q[i].l,q[i].r,1));
		if(query(q[i].l,q[i].r,1).w >= q[i].w){
			q2[len2--] = q[i];
			//puts("yes");
		}
		else{
			q2[len1++] = q[i];
			//puts("no");
		}	
	}
	for(int i=head;i<=tail;i++)
		q[i] = q2[i];
	solve(head,len1-1,l,mid);
	solve(len1,tail,mid+1,r);
}

int main(){
	 int ma = 0;
	 scanf("%d",&N);
	 for(int i=1;i<=N;i++){
		 scanf("%d",&node[i].h);
		 node[i].id = i;
		 ma = max(ma,node[i].h);
	 }
	int tot;
	scanf("%d",&tot);
	for(int i=1;i<=tot;i++){
		scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].w);
		q[i].t = i;
	}
	sort(node+1,node+N+1);
	now = N;
	build(1,N,1);
	//for(int i=1;i<=tot;i++)
	//	ans[i] = -1;
	solve(1,tot,1,ma);
	for(int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
	return 0;
}



