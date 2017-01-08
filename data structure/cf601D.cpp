                                            
  //File Name: cf601D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月03日 星期三 22时26分54秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define LL long long 
using namespace std;
const int MAXN = 300000 + 3;

int trie[MAXN * 10][26],size[MAXN * 10],tot;
int c[MAXN];
char str[MAXN];
vector<int>e[MAXN];

int merge(int u,int v){
	if(u < 0) return v;
	if(v < 0) return u;
	int t = tot++;
	size[t] = 1;
	for(int i=0;i<26;i++){
		trie[t][i] = merge(trie[u][i],trie[v][i]);
		if(trie[t][i] >= 0)
			size[t] += size[trie[t][i]];
	}
	return t;
}

void dfs(int u,int p){
	for(int i=0;i<26;i++) trie[u][i] = -1;
	for(int i=0;i<e[u].size();i++){
		int v = e[u][i];
		if(v == p) continue;
		dfs(v,u);
		trie[u][str[v]-'a'] = merge(trie[u][str[v]-'a'],v);
	}
	size[u] = 1;
	for(int i=0;i<26;i++)
		if(trie[u][i] >= 0) 
			size[u] += size[trie[u][i]];
}

void solve(int n){
	tot = n + 1;
	dfs(1,-1);
	int ans = 0,len = 0;
	for(int i=1;i<=n;i++) 
		if(size[i] + c[i] > ans)
			ans = size[i] + c[i];
	for(int i=1;i<=n;i++)
		if(size[i] + c[i] == ans)
			len++;
	printf("%d\n%d\n",ans,len);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	scanf("%s",str+1);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	solve(n);
	return 0;
}


