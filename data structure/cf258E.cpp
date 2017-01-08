                                            
  //File Name: cf258E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月02日 星期一 14时39分40秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 3;

struct Segtree{
	int ly,w;
}seg[MAXN << 2];

void pushup(int l,int r,int rt){
	if(seg[rt].ly)
		seg[rt].w = r - l + 1;
	else if(l == r)
		seg[rt].w = 0;
	else
		seg[rt].w = seg[rt<<1].w + seg[rt<<1|1].w;
}

void build(int l,int r,int rt){
	seg[rt].ly = seg[rt].w = 0;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson),build(rson);
}

void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		seg[rt].ly += add;
		pushup(l,r,rt);
		return ;
	}
	int mid = (l + r) >> 1;
	if(L <= mid)	update(L,R,add,lson);
	if(R > mid) 	update(L,R,add,rson);
	pushup(l,r,rt);
}

struct Query{
	int l,r,w,next;
	Query(int _l = 0,int _r = 0,int _w = 0,int _next = -1){
		l = _l,r = _r,w = _w,next = _next;
	}
	bool operator < (const Query &a) const{
		return a.r < r;
	}
}q[MAXN << 1];
int now,tot;
int ans[MAXN];

bool cmp(Query x,Query y){
	if(x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],total;

void init(){
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v){
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

int in[MAXN],siz[MAXN],rev[MAXN];

void dfs(int u,int p){
	in[u] = ++total;
	rev[total] = u;
	siz[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)  continue;
		dfs(v,u);
		siz[u] += siz[v];
	}
}

int tmp[MAXN][2];

void get_next(int m){
	memset(tmp,-1,sizeof tmp);
	for(int i=1,w;i<=tot;i++){
		w = q[i].w;
		if(tmp[w][0] == -1) tmp[w][0] = i;
		else tmp[w][1] = i;
	}
	for(int i=1;i<=m;i++){
		if(tmp[i][1] == -1)
			q[tmp[i][0]].next = -1;
		else{
			q[tmp[i][0]].next = tmp[i][1];
			q[tmp[i][1]].next = tmp[i][0];
		}
	}
}

void solve(int n,int m){
	total = 0,tot = 0;
	dfs(1,-1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		if(in[u] > in[v])
			swap(u,v);
		q[++tot] = Query(in[u],in[u] + siz[u] - 1,i);
		if(in[v] > in[u] + siz[u] - 1){
			q[++tot] = Query(in[v],in[v] + siz[v] - 1,i);
		}
	}
	sort(q+1,q+tot+1,cmp);
	get_next(m);
	build(1,n,1);
	now = 1;
	priority_queue<Query> que;
	Query cnt;
	while(!que.empty())
		que.pop();
	for(int i=1;i<=n;i++){
		while(now <=tot && q[now].l == i){
			update(q[now].l,q[now].r,1,1,n,1);
			if(q[now].next != -1){
				int u = q[now].next;
				update(q[u].l,q[u].r,1,1,n,1);
			}
			que.push(q[now]);
			now++;
		}
		ans[rev[i]] = seg[1].w;
		if(ans[rev[i]] > 0)
			ans[rev[i]]--;
		while(!que.empty() && que.top().r == i){
			cnt = que.top();
			que.pop();
			update(cnt.l,cnt.r,-1,1,n,1);
			if(cnt.next != -1){
				int u = cnt.next;
				update(q[u].l,q[u].r,-1,1,n,1);
			}
		}
	}
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return ;
}
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		init();
		for(int i=1,u,v;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve(n,m);
	}
	return 0;
}
