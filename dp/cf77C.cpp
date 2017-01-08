                                            
  //File Name: cf77C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月13日 星期四 22时29分25秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
struct Edge{
	int to,next;
}edge[MAXN << 1];
int head[MAXN],tot,a[MAXN];
bool is[MAXN];
LL f[MAXN];
vector<LL>tmp[MAXN];
void init(){
	memset(head,-1,sizeof(head));
	tot = 0;
	memset(is,false,sizeof(is));
}
void ae(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
bool cmp(int x,int y){
	return x > y;
}
void dfs1(int u,int p){
	if(a[u] == 0) f[u] = 0;
	else if(a[u] == 1) f[u] = 1,a[u]--;
	else{
		tmp[u].clear();
		for(int i=head[u];~i;i=edge[i].next){
			int v = edge[i].to;
			if(v == p) continue;
			dfs1(v,u);
			if(f[v]) tmp[u].push_back(f[v]);
		}
		int ma = tmp[u].size();
		if(ma == 0){
			f[u] = 1,a[u]--;
			return ;
		}
		sort(tmp[u].begin(),tmp[u].end(),cmp);
		int num = min(a[u]-1,ma);
		for(int i=0;i<num;i++)
			f[u] += tmp[u][i];
		f[u] += num + 1;
		a[u] -= num + 1;
		tmp[u].clear();
		for(int i=head[u];~i;i=edge[i].next){
			if(a[u] == 0) break;
			int v = edge[i].to;
			if(v == p || is[v] || a[v] == 0) continue;
		   	int now = min(a[u],a[v]);
			f[u] += now * 2;
			a[u] -= now;
			a[v] -= now;	
		}
	}
}
LL dfs2(int u,int p){
	LL res = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || is[v]) continue;
		res += dfs2(v,u);
		int now= min(a[u],a[v]);
		res += now * 2;
		a[u] -= now;
	}
	return res;
}
LL solve(int n,int rt){
	if(a[rt] == 0) return a[rt];
	a[rt]++;
	dfs1(rt,rt);
//	cout << f[rt] -1 << endl;
//	for(int i=1;i<=n;i++)
//		printf("i = %d f[i] = %lld\n",i,f[i]);
//	f[rt] += dfs2(rt,rt);
	return f[rt] - 1;
}
int main(){
	init();
	int n,rt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	   	scanf("%d",a + i);
		if(a[i] == 0) is[i] = true;
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	scanf("%d",&rt);
	cout << solve(n,rt) << endl;
	return 0;
}
