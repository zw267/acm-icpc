                                            
  //File Name: cf605D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月06日 星期五 14时39分54秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <queue>

#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 100000 + 5;

struct Data{
	int a,b,c,d,id;
}data[MAXN];

int num[MAXN << 1];
int has[MAXN << 1];
int tot,top;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	has[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i - 1])
			has[++tot] = num[i];
}

int hash_find(int x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(has[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

set< pii > bit[MAXN << 1];
set< pii >::iterator it;
vector<int> now;

void update(int x,pii d){
	for(;x <= tot;x += x & (-x)){
		bit[x].insert(d);
	}
}

int query(int x,int d){
	now.clear();
	pii u = mp(d,MAXN);
	for(;x > 0;x-= x & (-x)){
		for(it=bit[x].begin();it != bit[x].end();){
			if(*it <= u){
				now.pb(it->sec);
				bit[x].erase(it);
				it = bit[x].begin();
			}
			else
				break;
		}
	}
}

int pre[MAXN],dis[MAXN];
void print(int );

void solve(int n){
	hash_init();
	for(int i=0;i<=n;i++){
		data[i].a = hash_find(data[i].a);
		data[i].c = hash_find(data[i].c);
	}
	for(int i=0;i<=n;i++){
		pre[i] = -1,dis[i] = MAXN;
	}
	dis[0] = 0;
	for(int i=1;i<=n;i++){
		update(data[i].a,mp(data[i].b,data[i].id));
	}
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		if(u == n) break;
		query(data[u].c,data[u].d);
		for(int i=0;i<now.size();i++){
			if(dis[now[i]] > dis[u] + 1){
				dis[now[i]] = dis[u] + 1;
				pre[now[i]] = u;
				que.push(now[i]);
			}
		}
	}
	print(n);
}

int ans[MAXN];

void print(int n){
	if(pre[n] == -1) {puts("-1");return ;}
	int tot = 0;
	for(int i=n;pre[i] != -1;i=pre[i]){
		ans[tot++] = i;
	}
	printf("%d\n",tot);
	for(int i=tot-1;i>0;i--){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[0]);
}

int main(){
	int n;
	top = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&data[i].a,&data[i].b,&data[i].c,&data[i].d);
		num[++top] = data[i].a, num[++top] = data[i].c;
		data[i].id = i;
	}
	data[0].a = data[0].c = data[0].d = data[0].id = 0;
	num[++top] = 0;
	solve(n);
	return 0;
}
