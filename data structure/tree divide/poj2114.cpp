                                            
  //File Name: poj2114.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月08日 星期二 16时28分27秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 10000+5;

struct Edge
{
	int to,w,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;
bool cen[MAXN];
int sub_size[MAXN];
int ds[MAXN];
int tds[MAXN];
int tot_ds,tot_tds;
bool ans;
int que;

void init()
{
	memset(head,-1,sizeof head);
	total = 0;
}

void addedge(int u,int v,int w)
{
	edge[total].to = v;
	edge[total].w = w;
	edge[total].next = head[u];
	head[u] = total++;
}

void get_sub_size(int u,int p)
{
	sub_size[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v] || v == p)
			continue;
		get_sub_size(v,u);
		sub_size[u] += sub_size[v];
	}
}

pair<int,int> find_cen(int u,int p,int sum)
{
	pair<int,int> res = make_pair(MAXN,-1);
	int s = 1,m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,find_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	res = min(res,make_pair(m,u));
	return res;
}

bool bs(int cur ,int r)
{
	int l = 0,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] <= cur)
			l = mid;
		else
			r = mid;
	}
	if(ds[l] == cur || ds[r] == cur)
		return true;
	return false;
}

void dfs(int u,int p,int cost)
{
	tds[tot_tds++] = cost;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		dfs(v,u,cost + edge[i].w);
	}
}

void solve(int u)
{
	get_sub_size(u,-1);
	if(sub_size[u] <= 1)
		return ;
	int s = find_cen(u,-1,sub_size[u]).second;
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve(v);
		if(ans)
			return ;
	}
	tot_ds = 0;
	ds[tot_ds++] = 0;
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		tot_tds = 0;
		dfs(v,s,edge[j].w);
		for(int i=0;i<tot_tds;i++){
			int cur = que - tds[i];
			if(cur < 0 || cur > ds[tot_ds-1])
				continue;
			if(bs(cur,tot_ds-1)){
				ans = true;
				return ;
			}
		}
		for(int i=0;i<tot_tds;i++){
			ds[tot_ds++] = tds[i];
		}
		sort(ds,ds+tot_ds);
	}
	cen[s] = false;
	return; 
}

int main()
{
	int n;
	while(scanf("%d",&n) && n){
		init();
		int v,w;
		for(int i=1;i<=n;i++){
			while(scanf("%d",&v) && v){
				scanf("%d",&w);
				addedge(i,v,w);
				addedge(v,i,w);
			}
		}
		while(scanf("%d",&que) && que){
			ans = false;
			memset(cen,false,sizeof cen);
			solve(1);
			if(ans)
				puts("AYE");
			else
				puts("NAY");
		}
		puts(".");
	}
	return 0;
}




