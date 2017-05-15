                                            
  //File Name: cf325E.cpp
  //Created Time: 2017年05月09日 星期二 18时11分44秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
int to[MAXN];
bool vis[MAXN];
int n;
void dfs(int u){
	if(vis[u]) return ;
	vis[u] = true;
	if(!vis[(u + u)% n]){
		to[u] = (u + u) % n;
		dfs((u + u) % n);
	}
	else if(!vis[(u + u + 1) % n]){
		to[u] = (u + u + 1) % n;
		dfs((u + u + 1) % n);
	}
	if(!vis[(u + n / 2) % n]){
		to[u] = (u + u + 1) % n;
		dfs((u + u + 1) % n);
		to[(u + n / 2) % n] = (u + u) % n;
	}
}
int main(){
	scanf("%d",&n);
	if(n & 1) puts("-1");
	else{
		memset(vis,false,sizeof vis);
		dfs(0);
		printf("0");
		for(int i=0;i<n;){
			printf(" %d",to[i]);
			i = to[i];
			if(!i) break;
		}
		puts("");
	}
	return 0;
}
