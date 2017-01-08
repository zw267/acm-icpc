                                            
  //File Name: cf687D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月09日 星期五 17时27分52秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1005;
struct Edge{
	int u,v,w,id;
	bool operator<(const Edge&a)const{
		return w > a.w;
	}
}e[MAXN * MAXN];
int fa[MAXN + MAXN];
int find_fa(int x){
	if(fa[x] == x) return x;
	return fa[x] = find_fa(fa[x]);
}
void _union(int x,int y){
	int fax = find_fa(x);
	int fay = find_fa(y);
	fa[fax] = fay;
}
void solve(int n,int m,int q){
	sort(e+1,e+m+1);
	int l,r,ans;
	while(q--){
		ans = -1;
		scanf("%d %d",&l,&r);
		for(int i=1;i<=2*n;i++) 
			fa[i] = i;
		for(int i=1;i<=m;i++){
			if(e[i].id >= l && e[i].id <= r){
				int u = e[i].u,v = e[i].v;
				int fau = find_fa(u);
				int fav = find_fa(v);
				if(fau == fav){
					ans = e[i].w;
					break;
				}
				else{
					_union(u,v+n);
					_union(u+n,v);
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		e[i].id = i;
	}
	solve(n,m,q);
	return 0;
}
