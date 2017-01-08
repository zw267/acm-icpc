                                            
  //File Name: nod1297.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月19日 星期一 22时41分22秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define fir first
#define sec second
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 10;
int val[MAXN << 2],a[MAXN];
void pushdown(int rt){
	if(val[rt]){
		val[rt<<1] = val[rt<<1|1] = val[rt];
		val[rt] = 0;
	}
}
void build(int l,int r,int rt){
	val[rt] = a[1];
	if(l == r) return ;
	int m = l + r >> 1;
	build(lson);
	build(rson);
}
void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		val[rt] = add;
		return ;
	}
	int m = l + r >> 1;
	pushdown(rt);
	if(L <= m) update(L,R,add,lson);
	if(R > m) update(L,R,add,rson);
}
int query(int p,int l,int r,int rt){
	if(l == r) return val[rt];
	int m = l + r >> 1;
	pushdown(rt);
	if(p <= m) return query(p,lson);
	else return query(p,rson);
}
struct Edge{
	int to,next;
}edge[MAXN<<1];
int head[MAXN],tot,num[MAXN];
pii line[MAXN];
LL ans[MAXN];
void init(){
	memset(head,-1,sizeof head);
	tot = 0;
	memset(ans,0,sizeof ans);
}
void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void update(int x,int n){
	int fa = query(x,1,n,1);
//	printf("x = %d fa = %d\n",x,fa);
	addedge(fa,x);
	addedge(x,fa);
	if(x < fa){
		line[x] = mp(line[fa].fir,fa-1);
		line[fa].fir = fa;
	}
	else{
		line[x] = mp(fa+1,line[fa].sec);
		line[fa].sec = fa;
	}
//	printf("x = %d l = %d r = %d\n",x,line[x].fir,line[x].sec);
	if(line[x].fir <= line[x].sec)
		update(line[x].fir,line[x].sec,x,1,n,1);
}
int sub_size[MAXN];
bool cen[MAXN];
vector<pii> ds,tds;
int get_sub_size(int u,int p){
	int tmp = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v] || v == p) continue;
		tmp += get_sub_size(v,u);
	}
	sub_size[u] = tmp;
	return tmp;
}
pii get_cen(int u,int p,int sum){
	pii res = mp(INF,-1);
	int s = 1,m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v]) continue;
		res = min(res,get_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	res = min(res,mp(m,u));
	return res;
}
void dfs(int u,int p,int s){
	tds.push_back(mp(num[u],s));
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v] || v == p) continue;
		dfs(v,u,s+1);
	}
}
void cal(vector<pii> &d,int f){
	sort(d.begin(),d.end());
	LL pre = 0;
	pii now;
	for(int i=0;i<d.size();i++){
		now = d[i];
		ans[now.fir] += (LL)f * (pre + (LL)now.sec * i);
		pre += now.sec;
	}
}
void solve_sub(int root){
	get_sub_size(root,root);
	if(sub_size[root] == 1) return ;
	int s = get_cen(root,root,sub_size[root]).sec;
//	printf("s = %d\n",s);
	cen[s] = true;
	ds.clear();
	ds.push_back(mp(num[s],0));
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v]) continue;
		tds.clear();
		dfs(v,s,1);
		cal(tds,-1);
		for(int j=0;j<tds.size();j++)
			ds.push_back(tds[j]);
	}
	cal(ds,1);
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v]) continue;
		solve_sub(v);
	}
}
void solve(int n){
	init();
	line[a[1]] = mp(1,n);
	build(1,n,1);
	for(int i=2;i<=n;i++)
		update(a[i],n);
	memset(cen,false,sizeof cen);
	solve_sub(1);
	for(int i=2;i<=n;i++)
		ans[i] += ans[i-1];
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",a + i);
			num[a[i]] = i;
		}
		solve(n);
		for(int i=1;i<=n;i++)
			printf("%lld\n",ans[i]);
	}
	return 0;
}
