                                            
  //File Name: cf650E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月02日 星期五 13时45分08秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <set>
#define fir first
#define sec second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int MAXN = 500000 + 10;
struct Edge{
	int to,next;
}edge1[MAXN<<1],edge2[MAXN<<1];
int head1[MAXN],head2[MAXN],tot1,tot2;
int fa[MAXN],fa2[MAXN],dep[MAXN],len,s;
set< pii > rem;
void init(){
	memset(head1,-1,sizeof head1);
	memset(head2,-1,sizeof head2);
	tot1 = tot2 = 0;
	memset(fa,-1,sizeof fa);
	memset(fa2,-1,sizeof fa2);
}
void addedge(int u,int v,int flag){
	if(flag == 1){
		edge1[tot1].to = v;
		edge1[tot1].next = head1[u];
		head1[u] = tot1++;
	}
	else{
		edge2[tot2].to = v;
		edge2[tot2].next = head2[u];
		head2[u] = tot2++;
	}
}
struct Ans{
	int a,b,c,d;
	Ans(){}
	Ans(int _a,int _b,int _c,int _d){
		a = _a,b = _b,c = _c,d = _d;
	}
}ans[MAXN];
int find_fa(int x){
	if(fa[x] == -1) return x;
	return fa[x] = find_fa(fa[x]);
}
void _union(int x,int y){
	int fax = find_fa(x),fay = find_fa(y);
	if(dep[fax] <= dep[fay])
		fa[fay] = fax;
	else
		fa[fax] = fay;
}
void dfs2(int u,int p){
	fa2[u] = p;
	dep[u] = dep[p] + 1;
	for(int i=head2[u];~i;i=edge2[i].next){
		int v = edge2[i].to;
		if(v == p) continue;
		dfs2(v,u);
	}
}
void dfs1(int u,int p){
	for(int i=head1[u];~i;i=edge1[i].next){
		int v = edge1[i].to;
		if(v == p) continue;
		if(rem.find(mp(u,v))!=rem.end() || rem.find(mp(v,u))!=rem.end()){
			_union(u,v);
		}
		else
			s++;
		dfs1(v,u);
	}
}
void dfs3(int u,int p){
	for(int i=head1[u];~i;i=edge1[i].next){
		int v = edge1[i].to;
		if(v == p) continue;
		dfs3(v,u);
		if(rem.find(mp(u,v))==rem.end() && rem.find(mp(v,u))==rem.end()){
			int f = find_fa(v);
			if(f != 1){
					
				ans[++len] = Ans(u,v,fa2[f],f);
			}
			_union(f,fa2[f]);
		}
	}
}
void solve(int n){
	len = 0,s = 1;
	dfs2(1,1);
	dfs1(1,1);
	if(s == 1) return ;
	dfs3(1,1);
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v,1);
		addedge(v,u,1);
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		addedge(u,v,2);
		addedge(v,u,2);
		rem.insert(make_pair(u,v));
	}
	solve(n);
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
	}
	return 0;
}
