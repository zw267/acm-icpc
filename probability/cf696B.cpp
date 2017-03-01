                                            
  //File Name: cf696B.cpp
  //Created Time: 2017年02月26日 星期日 14时33分29秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 2;
vector<int> G[MAXN];
double f[MAXN];
int siz[MAXN];
int pa[MAXN];
void dfs(int u){
	for(int i=0;i<G[u].size();++i){
		int v  =G[u][i];
		f[v] = f[u] + 1.0 + (siz[u] - siz[v] - 1.0) / 2.0;
		dfs(v);
	}
}
void solve(int n){
	for(int i=n;i>=1;--i){
		++siz[i];
		siz[pa[i]] += siz[i];
	}
	f[1] = 1;
	dfs(1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",pa + i);
		G[pa[i]].push_back(i);
	}
	solve(n);
	for(int i=1;i<=n;++i)
		printf("%.15f ",f[i]);
	puts("");
	return 0;
}
