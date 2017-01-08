                                            
  //File Name: hdu4670.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月08日 星期二 20时53分20秒
                                   

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 50000+5;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,next;
};
Edge edge[MAXN << 1];
int head[MAXN];
int total;

bool cen[MAXN];
int sub_size[MAXN];
LL prime[30];
map<LL,int> ds;
map<LL,int> tds;
map<LL,int>::iterator it;
LL init_val[MAXN];
LL val[MAXN];
LL po[32];
int K;
LL ans;

void init()
{
	memset(head,-1,sizeof head);
	total = 0;
	memset(cen,false,sizeof cen);
	po[0] = 1;
	for(int i=1;i<32;i++)
		po[i] = po[i-1] * 3;
}

void addedge(int u,int v)
{
	edge[total].to = v;
	edge[total].next = head[u];
	head[u] = total++;
}

void init_sub_size(int u,int p)
{
	sub_size[u] = 1;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		init_sub_size(v,u);
		sub_size[u] += sub_size[v];
	}
}

pair<int,int> find_cen(int u,int p,int sum)
{
	pair<int,int> res = make_pair(MAXN,-1);
	int s = 1, m = 0;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,find_cen(v,u,sum));
		m = max(m,sub_size[v]);
		s += sub_size[v];
	}
	m = max(m,sum - s);
	return res = min(res,make_pair(m,u));
}

void dfs(int u,int p,LL cost)
{
	tds[cost]++;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(v == p || cen[v])
			continue;
		LL cur = 0;
		int num = 0;
		for(int i=0;i<K;i++){
			num = (cost % po[i+1])/po[i] + (val[v]%po[i+1])/po[i];
			num %= 3;
			cur += num * po[i];
		}
		dfs(v,u,cur);
	}
}

int bs(int init_l,int init_r,LL cur)
{
	int res_l,res_r;
	int mid;
	int l = init_l, r = init_r;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] < cur)
			l = mid;
		else
			r = mid;
	}
	if(ds[l] == cur)
		res_l = l;
	else
		res_l = r;
	
	l = init_l, r = init_r;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] <= cur)
			l = mid;
		else
			r = mid;
	}
	if(ds[l] > cur)
		res_r = l;
	else
		res_r = r;
	return res_r - res_l;	
}

void solve_sub(int u)
{
	init_sub_size(u,-1);
	if(sub_size[u] <= 1)
		return ;
	int s = find_cen(u,-1,sub_size[u]).second;
	cen[s] = true;
	for(int i=head[s];~i;i=edge[i].next){
		int v = edge[i].to;
		if(cen[v])
			continue;
		solve_sub(v);
	}
	ds.clear();
	ds[0] = 1;
	for(int j=head[s];~j;j=edge[j].next){
		int v = edge[j].to;
		if(cen[v])
			continue;
		tds.clear();
		dfs(v,s,val[v]);
		/*
		for(int i=0;i<tot_tds;i++){
			LL cur = po[K];
			cur = cur - tds[i] - val[s];
			cur = (cur + po[K]) % po[K];
			if(cur < ds[0] || cur > ds[tot_ds - 1])
				continue;
			ans += bs(0,tot_ds-1,cur);
		}
		for(int i=0;i<tot_tds;i++)
			ds[tot_ds++] = tds[i];
		sort(ds,ds+tot_ds);
		*/
		LL cur;
		int num;
		for(it=tds.begin();it!=tds.end();it++){
			cur = 0;
			num = 0;
			LL fir = it->first;
			int sec = it->second;
			for(int i=0;i<K;i++){
				num = (fir % po[i+1]) / po[i] + (val[s] % po[i+1]) / po[i];
				num = (6 - num) % 3;
				cur += num * po[i];
			}
			ans += (LL)ds[cur] * (it->second);
		}
		for(it=tds.begin();it!=tds.end();it++){
			ds[it->first] += (it->second);
		}
	}
	cen[s] = false;
}

void solve(int n)
{
	ans = 0;
	int cur;
	for(int i=1;i<=n;i++){
		val[i] = 0;
		for(int j=0;j<K;j++){
			cur = 0;
			while(init_val[i] % prime[j] == 0){
				cur++;
				init_val[i] /= prime[j];
			}
			cur %= 3;
			val[i] += cur * po[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(val[i] == 0)
			ans++;
	}
	//cout << ans << endl;
	solve_sub(1);
	cout << ans <<endl;
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		scanf("%d",&K);
		init();
		for(int i=0;i<K;i++)
			scanf("%lld",&prime[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&init_val[i]);
		int u,v;
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve(n);
	}
	return 0;
}
