                                            
  //File Name: cf533B.cpp
  //Created Time: 2017年01月17日 星期二 00时00分46秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 200000 + 2;
vector<int> G[MAXN];
int a[MAXN];
LL f[MAXN][2];
void dfs(int u){
	f[u][0] = 0;
	f[u][1] = -INF;
	LL p0 = 0,p1 = 0;
	for(int i=0;i<G[u].size();++i){
		int v = G[u][i];
		dfs(v);
		p0 = f[u][0],p1 = f[u][1];
		f[u][0] = max(p0 + f[v][0],p1 + f[v][1]);
		f[u][1] = max(p0 + f[v][1],p1 + f[v][0]);
	}
	f[u][1] = max(f[u][1],f[u][0] + a[u]);
}
LL solve(int n){
	dfs(1);
//	for(int i=1;i<=n;++i)
//		printf("i = %d %lld %lld\n",i,f[i][0],f[i][1]);
	return max(f[1][0],f[1][1]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,p;i<=n;++i){
		scanf("%d %d",&p,&a[i]);
		if(p != -1)
			G[p].push_back(i);
	}
	printf("%lld\n",solve(n));
	return 0;
}
