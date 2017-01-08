                                            
  //File Name: hdu4366.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月12日 星期二 15时34分56秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define LL long long
#define fir first
#define sec second
#define mp make_pair
#define size sizsiz

using namespace std;

const int MAXN = 50000 + 5;

struct Node{
	int loy,abi,id;
	Node(int _loy = 0,int _abi = 0,int _id = 0){
		loy = _loy,abi = _abi,id = _id;
	}
};
Node pre[MAXN];
Node now[MAXN];

struct Edge{
	int to,next;
};
Edge edge[MAXN];
int head[MAXN],total;
int size[MAXN];
int abi[MAXN];
int loy[MAXN];
int f[MAXN];
int bel[MAXN];
int in[MAXN];
int s,num,tot;

void init_edge(){
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v){
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void dfs(int u){
	size[u] = 1;
	pre[++tot] = Node(loy[u],abi[u],u);
	in[u] = tot;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		dfs(v);
		size[u] += size[v];
	}
}

bool cmp(Node x,Node y){
	if(x.abi == y.abi)
		return x.loy < y.loy;
	return x.abi < y.abi;
}

void init(int n){
	s = (int)sqrt(n + 0.0);
	num = n / s;
	if(n % s)
		num++;
	for(int i=0;i<n;i++)
		bel[i] = i / s;
	for(int i=0;i<n;i++){
		now[i] = pre[i];
	}
	for(int i=0,l,r;i<num;i++){
		l = i * s;
		r = min(i * s + s - 1,n - 1);
		sort(now + l,now + r + 1,cmp);
	}
	for(int i=0,l,r;i<num;i++){
		l = i * s;
		r = min(i * s + s - 1,n - 1);
		f[r] = now[r].id;
		for(int j=r - 1;j >= l;j--){
			f[j] = f[j + 1];
			if(now[j].loy > loy[f[j]])
				f[j] = now[j].id;
		}
	}
	return ;
}

pair<int,int> bs(int p,int x){
	int l = p * s;
	int r = p * s + s - 1;
	if(now[r].abi <= x)
		return mp(-1,-1);
	if(now[l].abi > x){
		return mp(loy[f[l]],f[l]);
	}
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(now[mid].abi <= x)
			l = mid;
		else
			r = mid;
	}
	return mp(loy[f[r]],f[r]);
}

pair<int,int> query(int l,int r,int x){
	pair<int,int> res = mp(-1,-1);
	if(bel[l] == bel[r]){
		for(int i=l;i<=r;i++){
			if(pre[i].abi > x){
				if(pre[i].loy > res.fir)
					res = mp(pre[i].loy,pre[i].id);
			}
		}
		return res;
	}
	pair<int,int> L = query(l,bel[l] * s + s - 1,x);
	pair<int,int> R = query(bel[r] * s,r,x);
	res = L.fir > R.fir ? L:R;
	for(int i=bel[l]+1;i<bel[r];i++){
		L = bs(i,x);
		if(L.fir > res.fir)
			res = L;
	}
	return res;
}

void solve(int n,int q){
	loy[0] = abi[0] = -1;
	tot = -1;
	dfs(0);
	//if(n != tot){
	//	puts("fuck");
	//}
	init(n);
	for(int i=0,u;i<q;i++){
		scanf("%d",&u);
		if(size[u] == 1){
			puts("-1");
			continue;
		}
		printf("%d\n",query(in[u] + 1,in[u] + size[u] - 1,abi[u]).sec);
	}
	return ;
}

int main(){
	int test,n,q;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&q);
		init_edge();
		for(int i=1,p;i<n;i++){
			scanf("%d %d %d",&p,&loy[i],&abi[i]);
			addedge(p,i);
		}
		solve(n,q);
	}
	return 0;
}
