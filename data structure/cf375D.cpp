                                            
  //File Name: cf375D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月20日 星期三 09时59分46秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

#define count countcount

using namespace std;

const int MAXN = 100000 + 3;

struct Edge{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN],total;
int in[MAXN],siz[MAXN];
struct Query{
	int l,r,k,id;
};
Query que[MAXN];

int col[MAXN];
int count[MAXN];
int sum[MAXN];
int bel[MAXN];
int ans[MAXN],now_l,now_r;
int sz,sz_num;

void init_edge(){
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v){
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void dfs(int u,int p){
	in[u] = ++total;
	siz[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p)
			continue;
		dfs(v,u);
		siz[u] += siz[v];
	}
}

void change_col(int n){
	for(int i=1;i<=n;i++){
		head[in[i]] = col[i];
	}
	for(int i=1;i<=n;i++){
		col[i] = head[i];
	}
}

void build(int n){
	sz = (int)sqrt(n + 0.5);
	sz_num = n / sz;
	if(n % sz)
		sz_num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / sz;
	}
}

bool cmp(Query x,Query y){
	if(bel[x.l] == bel[y.l])
		return x.r < y.r;
	return bel[x.l] < bel[y.l];
}

void update_r(int &u,int v){
	while(u < v){
		u++;
		sum[col[u]]++;
		count[sum[col[u]]]++;
	}
	while(u > v){
		count[sum[col[u]]]--;
		sum[col[u]]--;
		u--;
	}
}

void update_l(int &u,int v){
	while(u < v){
		count[sum[col[u]]]--;
		sum[col[u]]--;
		u++;
	}
	while(u > v){
		u--;
		sum[col[u]]++;
		count[sum[col[u]]]++;
	}
}

void solve(int n,int q){
	total = 0;
	dfs(1,-1);
	change_col(n);
	build(n);
	for(int i=1,u,k;i<=q;i++){
		scanf("%d %d",&u,&k);
		que[i].l = in[u];
		que[i].r = in[u] + siz[u] - 1;
		que[i].k = k;
		que[i].id = i;
	}
	sort(que+1,que+q+1,cmp);
	now_l = now_r = 1;
	sum[col[1]]++;
	count[1] = 1;
	for(int i=1;i<=q;i++){
		if(que[i].l == que[i].r){
			ans[que[i].id] = (que[i].k == 1);
			continue;
		}
		update_r(now_r,que[i].r);
		update_l(now_l,que[i].l);
		ans[que[i].id] = count[que[i].k];
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return ;
}

int main(){
	init_edge();
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&col[i]);
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	solve(n,q);
	return 0;
}
