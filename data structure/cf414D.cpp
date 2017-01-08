                                            
  //File Name: cf414D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月09日 星期五 15时13分41秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
const int MAXN = 100000 + 10;
struct Edge{
	int to,next;
}edge[MAXN << 2];
int head[MAXN],tot;
void init(){
	memset(head,-1,sizeof head);
	tot = 0;
}
void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
int dep[MAXN],a[MAXN],K,P,D;
void dfs(int u,int p){
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p) continue;
		dep[v] = dep[u] + 1;
		D = max(D,dep[v]);
		dfs(v,u);
	}
}
bool cmp(int x,int y){
	return dep[x] < dep[y];
}
int solve(int n){
	dfs(1,1);
	int tot = 0;
	K = min(K,n-1);
	for(int i=2;i<=n;i++)
		a[++tot] = i;
	sort(a+1,a+tot+1,cmp);
	int ans = 0,now = 0;
	int l = 1,r = 1;
	while(l <= tot){
		while(r < tot && r - l + 1 < K && now <= P){
			if(dep[a[r+1]] == dep[a[r]]) r++;
			else if(now+r-l+1<=P){
				now += r - l + 1;
				r++;
			}
			else break;
		}
		ans = max(ans,r - l + 1);
		l++;
		if(r < l) r = l,now = 0;
		else now -= dep[a[r]] - dep[a[l-1]];
	}	
	return ans;
}
int main(){
	init();
	int n;
	scanf("%d %d %d",&n,&K,&P);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	cout << solve(n) << endl;
	return 0;
}
