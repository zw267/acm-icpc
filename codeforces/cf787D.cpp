                                            
  //File Name: cf787D.cpp
  //Created Time: 2017年03月27日 星期一 11时02分40秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define pli pair<LL,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
const LL INF = (1LL << 60);
vector<pii> G[MAXN * 9];
int tot;
LL dis[MAXN * 9];
bool vis[MAXN * 9];
void add(int u,int v,int w){
	G[u].push_back(pii(v,w));
}
void cal_tot(int l,int r,int rt){
	tot = max(tot,rt);
	if(l == r) return ;
	int m = l + r >> 1;
	cal_tot(l,m,rt << 1);
	cal_tot(m + 1,r,rt << 1 | 1);
}
void build(int l,int r,int rt){
	if(l == r){
		add(rt,l + tot + tot,0);
		add(l + tot + tot,rt + tot,0);
		return ;
	}
	add(rt,rt << 1,0);
	add(rt,rt << 1 | 1,0);
	add(rt + rt + tot,rt + tot,0);
	add(rt +rt + 1 + tot,rt +tot,0);
	int m = l + r >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
}
void add2(int v,int L,int R,int w,int l,int r,int rt){
	if(L <= l && r <= R){
		add(v,rt,w);
		return ;
	}
	int m = l + r >> 1;
	if(L <= m) add2(v,L,R,w,l,m,rt << 1);
	if(R > m) add2(v,L,R,w,m + 1,r,rt << 1 | 1);
}
void add3(int L,int R,int v,int w,int l,int r,int rt){
	if(L <= l && r <= R){
		add(rt + tot,v,w);
		return ;
	}
	int m = l + r >> 1;
	if(L <= m) add3(L,R,v,w,l,m,rt << 1);
	if(R > m) add3(L,R,v,w,m + 1,r,rt << 1 | 1);
}
void dijkstra(int n,int s){
	for(int i=1;i<=n;++i)
		dis[i] = INF,vis[i] = false;
	dis[s] = 0;
	priority_queue<pli> que;
	while(!que.empty()) que.pop();
	que.push(pli(0,s));
	while(!que.empty()){
		pli tmp = que.top();
		que.pop();
		LL d = -tmp.fir;
		int u = tmp.sec;
		if(d > dis[u] || vis[u]) continue;
		vis[u] = true;
		for(auto edge:G[u]){
			LL w = edge.sec;
			int v = edge.fir;
			if(!vis[v] && dis[v] > d + w){
				dis[v] = d + w;
				que.push(pli(-dis[v],v));
			}
		}
	}
}
void solve(int n,int q,int s){
	tot = 0;
	cal_tot(1,n,1);
	build(1,n,1);
	while(q--){
		int t,u,v,l,r,w;
		scanf("%d",&t);
		if(t == 1){
			scanf("%d %d %d",&v,&u,&w);
			add(v + tot + tot,u + tot + tot,w);
		}
		else{
			scanf("%d %d %d %d",&v,&l,&r,&w);
			if(t == 2)
				add2(v + tot + tot,l,r,w,1,n,1);
			else
				add3(l,r,v + tot + tot,w,1,n,1);
		}
	}
	dijkstra(tot + tot + n,tot + tot + s);
}
int main(){
	int n,q,s;
	scanf("%d %d %d",&n,&q,&s);
	solve(n,q,s);
	for(int i=1;i<=n;++i){
		if(dis[i + tot + tot] == INF)
			dis[i + tot + tot] = -1;
		printf("%lld ",dis[i + tot + tot]);
	}
	puts("");
	return 0;
}
