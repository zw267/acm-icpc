                                            
  //File Name: cf306B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月06日 星期六 21时48分47秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 200000 + 3;
struct Line{
	int l,r,id;
	Line(int _l = 0.0,int _r = 0.0,int _id = 0.0){
		l = _l,r = _r,id = _id;
	}
	bool operator<(const Line&a)const{
		return a.r > r;
	}
}line[MAXN];
bool cmp(Line &a,Line &b){
	if(a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}
int ans[MAXN];
void solve(const int n,const int m){
	int tot = 0;
	sort(line+1,line+m+1,cmp);
	//for(int i=1;i<=m;i++)
	//	printf("l = %d r = %d id = %d\n",line[i].l,line[i].r,line[i].id);
	priority_queue<Line> que;
	int now = 0,u = 1;
	while(u <= m){
		//printf("now = %d\n",now);
		bool flag = false;
		if(u <= m && now < line[u].l) now = line[u].l,flag = true;
		while(u <= m && line[u].l <= now){
			que.push(line[u]);
			u++;
		}
		if(que.top().r > now){
			if(flag) now = que.top().r;
			else{
				if(u <= m && line[u].l == now + 1 && line[u].r >= que.top().r)
					;
				else{
					now = que.top().r;
					flag = true;
				}
			}
		}
		if(flag) que.pop();
		else ans[tot++] = que.top().id,que.pop();
		while(!que.empty()) 
			ans[tot++] = que.top().id,que.pop();
	}
	if(tot == 0){
		puts("0");
		return ;
	}
	sort(ans,ans+tot);
	printf("%d\n",tot);
	for(int i=0;i<tot;i++){
		printf("%d",ans[i]);
		if(i == tot - 1) puts("");
		else printf(" ");
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		line[i] = Line(u,u + v - 1,i);
	}
	solve(n,m);
	return 0;
}
