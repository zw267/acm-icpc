                                            
  //File Name: cf797D.cpp
  //Created Time: 2017年04月30日 星期日 16时31分59秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
const int INF = 1e9;
pii tree[MAXN];
pii range[MAXN];
int val[MAXN];
int deg[MAXN];
map<int,int> rem;
void dfs(int u,int l,int r){
	if(l > r) return ;
	if(l <= val[u] && val[u] <= r) 
		rem[val[u]] = 1;
	if(tree[u].fir != -1)
		dfs(tree[u].fir,l,min(val[u] - 1,r));
	if(tree[u].sec != -1)
		dfs(tree[u].sec,max(l,val[u] + 1),r);
}
int solve(int n){
	int root = -1;
	for(int i=1;i<=n;++i)
		if(!deg[i]){
			root = i;
			break;
		}
	dfs(root,0,INF);
	int res = 0;
	for(int i=1;i<=n;++i){
		if(!rem.count(val[i]))
			++res;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,u,v,w;i<=n;++i){
		scanf("%d %d %d",&w,&u,&v);
		val[i] = w;
		tree[i] = pii(u,v);
		if(u != -1) ++deg[u];
		if(v != -1) ++deg[v];
	}
	printf("%d\n",solve(n));
	return 0;
}

