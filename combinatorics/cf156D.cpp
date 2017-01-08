                                            
  //File Name: cf156D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月15日 星期六 20时22分14秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
const int MAXN = 100000 + 3;
vector<int>edge[MAXN];
int siz[MAXN],t,mod;
bool vis[MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
void dfs(int u){
	siz[t]++;
	vis[u] = true;
	for(int i=0;i<edge[u].size();i++){
		int v = edge[u][i];
		if(vis[v]) continue;
		dfs(v);
	}	
}
LL solve(int n,int m){
	memset(vis,false,sizeof(vis));
	t = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			++t;
			dfs(i);
		}
	}
	if(t == 1) return 1 % mod;
	LL ans = qp(n,t - 2);
	for(int i=1;i<=t;i++)
		ans = ans * siz[i] % mod;
	return ans;
}
int main(){
	int n,m;
	scanf("%d %d %d",&n,&m,&mod);
	for(int i=0,u,v;i<m;i++){
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	printf("%d\n",(int)solve(n,m));
	return 0;
}
