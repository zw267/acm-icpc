                                            
  //File Name: cf650D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月04日 星期四 20时17分18秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define hash _hash_

using namespace std;

const int MAXN = 400000 + 2;

int num[MAXN << 1],hash[MAXN << 1],tot,top;
void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}
int hash_find(int x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

struct Seg{
	int max,ly;
}seg[MAXN << 3];
void pushup(int rt){
	seg[rt].max = max(seg[rt<<1].max,seg[rt<<1|1].max);
}
void pushdown(int rt){
	if(seg[rt].ly > -1){
		int ly = seg[rt].ly;
		seg[rt<<1].ly = seg[rt<<1|1].ly = ly;
		seg[rt<<1].max = seg[rt<<1|1].max = ly;
		seg[rt].ly = -1;
	}
}
void build(int l,int r,int rt){
	seg[rt].ly = -1;
	seg[rt].max = 0;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}
void update(int p,int add,int l,int r,int rt){
	if(l == r){
		if(add > seg[rt].max) seg[rt].max = add;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if(p <= mid) update(p,add,lson);
	else update(p,add,rson);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) return seg[rt].max;
	pushdown(rt);
	int mid = (l + r) >> 1;
	int res = 0;
	if(L <= mid) res = max(res,query(L,R,lson));
	if(R > mid) res = max(res,query(L,R,rson));
	pushup(rt);
	return res;
}

struct Query{
	int p,v,t;
	bool operator < (const Query &a) const{
		return p < a.p;
	}
}que[MAXN];
int a[MAXN],begin[MAXN],end[MAXN],ans[MAXN],pos[MAXN];

void cal_begin_and_end(int n,int &s){
	for(int i=1;i<=n;i++){
		end[i] = query(1,a[i]-1,1,tot,1) + 1;
		update(a[i],end[i],1,tot,1);
	}
	seg[1].ly = 0;
	for(int i=n;i>0;i--){
		begin[i] = query(a[i]+1,tot,1,tot,1) + 1;
		update(a[i],begin[i],1,tot,1);
	}
	//for(int i=1;i<=n;i++)
	//	printf("i = %d begin = %d end = %d\n",i,begin[i],end[i]);
	for(int i=1;i<=n;i++)
		s = max(s,end[i]);
	//printf("s = %d\n",s);
}

void cal_ans(int n,int m,int s){
	sort(que+1,que+m+1);
	for(int i=1;i<=m;i++) ans[i] = 1;
	int u = 1;
	seg[1].ly = 0;
	for(int i=1;i<=m;i++){
		while(u < que[i].p){
			update(a[u],end[u],1,tot,1);
			u++;
		}
		ans[que[i].t] += query(1,que[i].v - 1,1,tot,1);
	}
	seg[1].ly = 0;
	u = n;
	for(int i=m;i>0;i--){
		while(u > que[i].p){
			update(a[u],begin[u],1,tot,1);
			u--;
		}
		ans[que[i].t] += query(que[i].v + 1,tot,1,tot,1);
	}
	for(int i=1;i<=m;i++){
		if(pos[end[que[i].p]] == 1 && begin[que[i].p] + end[que[i].p] == s + 1)
			ans[que[i].t] = max(ans[que[i].t],s - 1);
		else 
			ans[que[i].t] = max(ans[que[i].t],s);
	}
}

void cal_pos(int n,int s){
	memset(pos,0,sizeof pos);
	for(int i=1;i<=n;i++){
		if(begin[i] + end[i] - 1 == s)
			pos[end[i]]++;
	}
}

void solve(int n,int m){
	int s = 0;
	hash_init();
	for(int i=1;i<=n;i++) a[i] = hash_find(a[i]);
	for(int i=1;i<=m;i++) que[i].v = hash_find(que[i].v);
	build(1,tot,1);
	cal_begin_and_end(n,s);
	cal_pos(n,s);
	cal_ans(n,m,s);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}

int main(){
	top = 0;
	int n,m,ma = 0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),num[++top] = a[i],ma = max(ma,a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&que[i].p,&que[i].v);
		que[i].t = i,num[++top] = que[i].v,ma = max(ma,que[i].v);
	}
	num[++top] = 0;
	num[++top] = ma + 1;
	solve(n,m);
	return 0;
}
