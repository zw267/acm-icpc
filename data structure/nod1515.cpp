                                            
  //File Name: nod1515.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月16日 星期五 23时01分02秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int MAXN = 100000 + 10;
int fa[MAXN];
map<int,int> rem;
set<int> dis[MAXN];
struct Query{
	int x,y,p;
}que[MAXN];
int find_fa(int x){
	if(fa[x] == x) return x;
	return fa[x] = find_fa(fa[x]);
}
void union_to(int x,int y){
	fa[y] = x;
	set<int>::iterator it;
	for(it=dis[y].begin();it!=dis[y].end();it++){
		int v = *it;
		dis[v].erase(y);
		dis[v].insert(x);
		dis[x].insert(v);
	}
	dis[y].clear();
}
void _union(int x,int y){
	if(dis[x].size() >= dis[y].size()) union_to(x,y);
	else union_to(y,x);
}
void solve(int n,int tot){
	for(int i=1;i<=n;i++){
		que[i].x = rem[que[i].x];
		que[i].y = rem[que[i].y];
	}
	for(int i=1;i<=tot;i++){
		fa[i] = i;
		dis[i].clear();
	}
	for(int i=1;i<=n;i++){
		int x = que[i].x,y = que[i].y,p = que[i].p;
		int fax = find_fa(x);
		int fay = find_fa(y);
		if(fax == fay){
			if(p) puts("YES");
			else puts("NO");
		}
		else{
			if(p){
				if(dis[fax].find(fay) != dis[fax].end()) puts("NO");
				else{
					puts("YES");
					_union(fax,fay);
				}
			}
			else{
				puts("YES");
				dis[fax].insert(fay);
				dis[fay].insert(fax);
			}
		}
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		int tot = 0;
		rem.clear();
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&que[i].x,&que[i].y,&que[i].p);
			if(!rem[que[i].x]) rem[que[i].x] = ++tot;
			if(!rem[que[i].y]) rem[que[i].y] = ++tot;
		}
		solve(n,tot);
	}
	return 0;
}
