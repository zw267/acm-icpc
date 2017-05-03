                                            
  //File Name: cf547D.cpp
  //Created Time: 2017年05月03日 星期三 19时54分57秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 200000;
set<pii> edge[MAXN + MAXN + 10];
int ans[MAXN];
void dfs(int u,int col){
	if(edge[u].size() == 0)
		return ;
	pii tmp = *edge[u].begin();
	int v = tmp.fir;
	int id = tmp.sec;
	edge[u].erase(tmp);
	edge[v].erase(pii(u,id));
	ans[id] = col;
	dfs(v,3 - col);
}
void solve(){
	int n = MAXN + MAXN;
	for(int i=1;i<=n;++i)
		if(edge[i].size() & 1) 
			dfs(i,1);
	for(int i=1;i<=n;++i)
		while(edge[i].size())
			dfs(i,1);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d %d",&x,&y);
		y += MAXN;
		edge[x].insert(pii(y,i));
		edge[y].insert(pii(x,i));
	}
	solve();
	for(int i=1;i<=n;++i)
		printf("%c",ans[i] == 1 ? 'r' : 'b');
	puts("");
	return 0;
}
