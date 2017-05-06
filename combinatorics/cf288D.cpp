                                            
  //File Name: cf288D.cpp
  //Created Time: 2017年05月05日 星期五 01时45分50秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 80000 + 5;
vector<int> G[MAXN];
int siz[MAXN];
int fa[MAXN];
LL t[MAXN];
LL comb[MAXN];
void cal_size(int u,int p,const int &n){
	fa[u] = p;
	siz[u] = 1;
	LL tmp(0);
	for(auto v:G[u]){
		if(v == p) continue;
		cal_size(v,u,n);
		siz[u] += siz[v];
		tmp += (LL)siz[v] * siz[v];
	}
	t[u] = (LL)n * (n - 1) - (LL)(n - siz[u]) * (n - siz[u]) - tmp + n - 1;
	if(t[u] & 1) puts("fuck");
	t[u] /= 2;
}
LL solve(int n){
	cal_size(1,0,n);
//	for(int i=1;i<=n;++i)
//		printf("i = %d siz = %d t = %lld\n",i,siz[i],t[i]);
	for(int i=1;i<=n;++i)
		comb[i] = (LL)i * (i - 1) / 2;
	LL res(0);
	for(int i=1;i<=n;++i)
		res += comb[n - siz[i]] * (t[i] - (n - siz[i]) * siz[i]);
	for(int i=2;i<=n;++i)
		res += comb[siz[i]] * (t[fa[i]] - siz[i] * (n - siz[i]));
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1),u,v;i<n;++i){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf("%lld\n",solve(n));
	return 0;
}
