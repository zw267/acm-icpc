                                            
  //File Name: hdu4638.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月11日 星期一 12时37分42秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <math.h>

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 3;

struct Que{
	int l,r,id;
};
Que que[MAXN];
int a[MAXN];
int bel[MAXN];
int ans[MAXN];
bool vis[MAXN];
int cur_l,cur_r,all;

bool cmp(Que x,Que y){
	if(bel[x.l] == bel[y.l])
		return x.r < y.r;
	return bel[x.l] < bel[y.l];
}

void update_r(int &u,int v){
	while(u < v){
		u++;
		if(vis[a[u]+1] && vis[a[u]-1])
			all--;
		else if(!vis[a[u]+1] && !vis[a[u]-1])
			all++;
		vis[a[u]] = true;
	}
	while(u > v){
		if(vis[a[u]+1] && vis[a[u]-1])
			all++;
		else if(!vis[a[u]+1] && !vis[a[u]-1])
			all--;
		vis[a[u]] = false;
		u--;
	}
}

void update_l(int &u,int v){
	while(u < v){
		if(vis[a[u]+1] && vis[a[u]-1])
			all++;
		else if(!vis[a[u]+1] && !vis[a[u]-1])
			all--;
		vis[a[u]] = false;
		u++;
	}
	while(u > v){
		u--;
		if(vis[a[u]+1] && vis[a[u]-1])
			all--;
		else if(!vis[a[u]+1] && !vis[a[u]-1])
			all++;
		vis[a[u]] = true;
	}
}

void solve(int n,int q){
	int s = (int)sqrt(n + 0.5);
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / s;
	}
	sort(que+1,que+q+1,cmp);
	memset(vis,false,sizeof vis);
	cur_l = cur_r = all = 1;
	vis[a[1]] = true;
	for(int i=1;i<=q;i++){
		if(que[i].l == que[i].r){
			ans[que[i].id] = 1;
			continue;
		}
		update_r(cur_r,que[i].r);
		update_l(cur_l,que[i].l);
		ans[que[i].id] = all;
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=q;i++){
			scanf("%d %d",&que[i].l,&que[i].r);
			que[i].id = i;
		}
		solve(n,q);
	}
	return 0;
}
