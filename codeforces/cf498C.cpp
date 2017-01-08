#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define pb push_back
#define LL long long

using namespace std;

const int MAX_V = 110;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,cap,rev;
};

vector<Edge>G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
LL rem[MAX_V];
LL val[MAX_V];

void addedge(int from,int to,int cap)
{
	G[from].pb((Edge){to,cap,G[to].size()});
	G[to].pb((Edge){from,0,G[from].size()-1});
}

void bfs(int s)
{
	memset(level,-1,sizeof level);
	queue<int>que;
	while(!que.empty())
		que.pop();
	level[s] = 0;
	que.push(s);
	while(!que.empty()){
		int v = que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			Edge &e = G[v][i];
			if(e.cap > 0 && level[e.to] < 0){
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v,int t,int f)
{
	if(v == t)
		return f;
	for(int &i=iter[v];i<G[v].size();i++){
		Edge &e = G[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d > 0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow = 0;
	while(true){
		bfs(s);
		if(level[t] < 0)
			return flow;
		memset(iter,0,sizeof iter);
		int f;
		while((f = dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
}

int pri_fact(LL x)
{
	int res = 0;
	for(int i=2;i * i <= x;i++){
		while(x % i == 0){
			res++;
			x /= i;
		}
	}
	if(x != 1)
		res++;
	return res;
}

void init(int n)
{
	for(int i=0;i<=n+1;i++)
		G[i].clear();
	memset(rem,-1,sizeof rem);
}

LL gcd(LL x,LL y)
{
	if(y == 0)
		return x;
	return gcd(y,x % y);
}

void solve()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
		//scanf("%I64d",&val[i]);
	}
	init(n);
	
	int s = 0,t = n + 1;
	int l,r;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l,&r);
		if(r % 2)
			swap(l,r);
		LL the_gcd = gcd(val[l],val[r]);
		addedge(l,r,pri_fact(the_gcd));
		//printf("%d %d %d\n",l,r,pri_fact(the_gcd));
		if(rem[l] == -1)
			rem[l] = the_gcd;
		else
			rem[l] = gcd(val[l],rem[l] * the_gcd);
		if(rem[r] == -1)
			rem[r] = the_gcd;
		else
			rem[r] = gcd(val[r],rem[r] * the_gcd);		
	}

	for(int i=1;i<=n;i+=2){
		if(rem[i] != -1){
			addedge(s,i,pri_fact(rem[i]));
			//printf("%d %d %d\n",s,i,pri_fact(rem[i]));
		}
	}
	for(int i=2;i<=n;i+=2){
		if(rem[i] != -1){
			addedge(i,t,pri_fact(rem[i]));
			//printf("%d %d %d\n",i,t,pri_fact(rem[i]));
		}
	}

	//for(int i=0;i<=t;i++){
	//	for(int j=0;j<G[i].size();j++){
	//		printf("%d %d %d\n",i,G[i][j].to,G[i][j].cap);
	//	}
	//}

	printf("%d\n",max_flow(s,t));

	//for(int i=0;i<=t;i++){
	//	for(int j=0;j<G[i].size();j++){
	//		printf("%d %d %d\n",i,G[i][j],G[i][j].cap);
	//	}
	//}

	return ;
}

int main()
{
	solve();
	return 0;
}
