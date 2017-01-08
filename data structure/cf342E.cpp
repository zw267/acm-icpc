                                            
  //File Name: cf342E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月29日 星期二 16时09分29秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

#define LL long long
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 100000 + 3;
const int INF = 0x3f3f3f3f;

struct Edge{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN],total;
int sub_size[MAXN];
bool is[MAXN];
bool cen[MAXN];
int dis[MAXN];
int red;
vector< pair<int,int> > fa[MAXN];

void init(){
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v){
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void init_sub_size(int u,int p){
	sub_size[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		init_sub_size(v,u);
		sub_size[u] += sub_size[v];
	}
}

pair<int,int> find_cen(int u,int p,int sum){
	pair<int,int> res = mp(INF,-1);
	int s = 1, m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,find_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	return res = min(res,mp(m,u));
}

void dfs(int u,int p,int cost,int s){
	if(is[u])
		red = min(red,cost);
	fa[u].pb(mp(s,cost));
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs(v,u,cost+1,s);
	}
}

void divide(int u){
	init_sub_size(u,-1);
	int s = find_cen(u,-1,sub_size[u]).sec;
	cen[s] = true;
	red = is[s]? 0:INF;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		dfs(v,s,1,s);
	}
	dis[s] = red;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		divide(v);
	}
	cen[s] = false;
}

void solve(int N,int Q){
	memset(cen,false,sizeof cen);
	for(int i=1;i<=N;i++)
		fa[i].clear();
	memset(is,false,sizeof is);
	is[1] = true;
	divide(1);
	for(int i=0,op,u;i<Q;i++){
		scanf("%d %d",&op,&u);
		if(op == 1){
			if(is[u])
				continue;
			dis[u] = 0;
			is[u] = true;
			for(int j=0;j<fa[u].size();j++){
				int id = fa[u][j].fir;
				int d = fa[u][j].sec;
				dis[id] = min(dis[id],d);
			}
		}
		else{
			int ans = dis[u];
			for(int j=0;j<fa[u].size();j++){
				int id = fa[u][j].fir;
				int d = fa[u][j].sec;
				ans = min(ans,dis[id] + d);
			}
			printf("%d\n",ans);
		}
	}
	return ;
}

int main(){
	int N,Q;
	while(~scanf("%d %d",&N,&Q)){
		init();
		for(int i=1,u,v;i<N;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve(N,Q);
	}
	return 0;
}

