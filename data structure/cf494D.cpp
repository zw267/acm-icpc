                                            
  //File Name: cf494D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月07日 星期三 23时00分16秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 100000 + 10;
LL dis[MAXN][4],d[MAXN];
int siz[MAXN],cost[MAXN],pa[MAXN][17],dep[MAXN],e[MAXN][3],st[MAXN],en[MAXN];
struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot;
void init(){
	memset(head,-1,sizeof head);
	memset(pa,-1,sizeof pa);
}
void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs1(int u,int p){
	siz[u] = 1;
	st[u] = ++tot;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dep[v] = dep[u] + 1;
		pa[v][0] = u;
		dfs1(v,u);
		siz[u] += siz[v];
	}
	en[u] = tot;
}
void init_pa(int n){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			if(pa[i][j-1] != -1)
				pa[i][j] = pa[pa[i][j-1]][j-1];
		}
	}
}
void dfs2(int u){
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == pa[u][0]) continue;
		(d[v] = d[u] + cost[v]) %= MOD;
		dfs2(v);
	}
}
int query(int a,int b,int n){
	int init_a = a,init_b = b;
	if(dep[a] < dep[b]) swap(a,b);
	int cnt;
	for(cnt=0;dep[a]-(1<<cnt)>=0;cnt++);
	cnt--;
	for(int j=cnt;j>=0;j--){
		if(dep[a]-(1<<j)>=dep[b]) 
			a = pa[a][j];
	}
	if(a == b) return (d[init_a]+d[init_b] - 2 * d[a]%MOD + MOD) % MOD;
	for(int i=cnt;i>=0;i--){
		if(pa[a][i] != -1 && pa[a][i] != pa[b][i])
			a = pa[a][i],b = pa[b][i];
	}
	return (d[init_a] + d[init_b] - 2 * d[pa[a][0]]%MOD + MOD) % MOD;
}
void dfs3(int u){
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == pa[u][0]) continue;
		dfs3(v);
		(dis[u][1] += dis[v][1] + siz[v] * cost[v]%MOD) %= MOD;
		LL tmp = (dis[v][2]+siz[v]*cost[v]%MOD*cost[v]%MOD) % MOD;
		(tmp += 2*cost[v]%MOD*dis[v][1]%MOD) %= MOD;
		(dis[u][2] += tmp) %= MOD;
	}
}
void dfs4(int u,int n){
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == pa[u][0]) continue;
		dis[v][3]=(dis[u][3]+n*cost[v]%MOD-2*siz[v]*cost[v]%MOD+MOD)%MOD;
		LL tmp=(n-4*siz[v])*cost[v]%MOD*cost[v]%MOD;
		tmp = (tmp + MOD) % MOD;
		tmp=(tmp+(2*dis[u][3]%MOD-4*dis[v][1]%MOD+MOD)*cost[v]%MOD)%MOD;
		(tmp+=dis[v][2]+dis[u][0]-dis[v][2]+MOD)%=MOD;
		dis[v][0] = (tmp + MOD) % MOD;
		dfs4(v,n);
	}
}
void solve(int n){
	tot = 0;
	dfs1(1,-1);
	init_pa(n);
	for(int i=1;i<n;i++){
		if(dep[e[i][0]] > dep[e[i][1]])
			swap(e[i][0],e[i][1]);
		cost[e[i][1]] = e[i][2];
	}
	dfs2(1);
	dfs3(1);
	dis[1][0] = dis[1][2],dis[1][3] = dis[1][1];
	dfs4(1,n);
	//for(int i=1;i<=n;i++)
	//	printf("i =%d %lld %lld\n",i,dis[i][0],dis[i][3]);
	int q;
	scanf("%d",&q);
	for(int i=1,u,v;i<=q;i++){
		scanf("%d %d",&u,&v);
		LL dd = query(u,v,n);
		LL ans;
		if(st[u]>=st[v]&&en[u]<=en[v]){
			ans=(n-siz[v])*dd%MOD*dd%MOD+dis[v][0]-dis[v][2];
			ans=(ans%MOD+2*dd%MOD*(dis[v][3]-dis[v][1])%MOD);
			ans=(ans+MOD)%MOD;
			ans=(dis[u][0]-2*ans%MOD+MOD)%MOD;
			cout << ans << endl;
		}
		else{
			ans=(siz[v]*dd%MOD*dd%MOD+dis[v][2]+2*dd%MOD*dis[v][1]%MOD)%MOD;
			ans = (ans * 2 % MOD - dis[u][0] + MOD) % MOD;
			cout << ans << endl;
		}
	}
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&e[i][0],&e[i][1],&e[i][2]);
		addedge(e[i][0],e[i][1]);
		addedge(e[i][1],e[i][0]);
	}
	solve(n);
	return 0;
}
