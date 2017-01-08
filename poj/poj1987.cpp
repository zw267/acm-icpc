                                            
  //File Name: poj1987.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月24日 星期日 20时19分45秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>

#define fir first
#define sec second

using namespace std;

const int MAXN = 40010;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to,cost;
};
vector<Edge> G[MAXN];
bool cen[MAXN];
int subtree_size[MAXN];
int ans,k;

void init(int n)
{
	for(int i=0;i<=n;i++)
		G[i].clear();
}

int com_size(int u,int p)
{
	int c = 1;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].to;
		if(v == p || cen[v])
			continue;
		c+= com_size(v,u);
	}
	subtree_size[u] = c;
	return c;
}

pair<int,int> find_cen(int u,int p,int sum)
{
	pair<int,int> res = make_pair(INF,-1);
	int s = 1;
	int m = 0;
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].to;
		if(v == p || cen[v])
			continue;
		res = min(res,find_cen(v,u,sum));
		m = max(m,subtree_size[v]);
		s += subtree_size[v];
	}

	m = max(m,sum - s);
	res = min(res,make_pair(m,u));
	return res;
}

void get_dis(int u,int p,int dis,vector<int>& ds)
{
	ds.push_back(dis);
	for(int i=0;i<G[u].size();i++){
		int v = G[u][i].to;
		if(v == p || cen[v])
			continue;
		get_dis(v,u,G[u][i].cost + dis,ds);
	}
}

int get_res(vector<int>& ds)
{
	int res = 0;
	sort(ds.begin(),ds.end());
	int l = 0;
	int r = ds.size() - 1;
	while(l < r){
		while(r > l && ds[l] + ds[r] > k)
			r--;
		res += (r - l);
		l++;
	}
	return res;
}

void solve_sub(int root)
{
	com_size(root,root);
	if(subtree_size[root] == 1)
		return ;
	int s = find_cen(root,root,subtree_size[root]).sec;
	cen[s] = true;
	for(int i=0;i<G[s].size();i++){
		int v = G[s][i].to;
		if(cen[v])
			continue;
		solve_sub(v);
	}
	vector<int> ds;
	ds.push_back(0);
	for(int i=0;i<G[s].size();i++){
		int v = G[s][i].to;
		if(cen[v])
			continue;
		vector<int> tds;
		get_dis(v,s,G[s][i].cost,tds);
		ans -= get_res(tds);
		ds.insert(ds.end(),tds.begin(),tds.end());
	}
	ans += get_res(ds);
	cen[s] = false;
}

int main()
{
	int n,m;
	
	while(~scanf("%d %d",&n,&m)){
		init(n);
		int u,v,cost;
		char ch[2];
		Edge e;
		for(int i=1;i<n;i++){
			scanf("%d %d %d",&u,&v,&cost);
			scanf("%s",ch);
			e.to = v;
			e.cost = cost;
			G[u].push_back(e);
			e.to = u;
			G[v].push_back(e);
		}
		scanf("%d",&k);
		ans = 0;
		memset(cen,false,sizeof cen);
		solve_sub(1);
		printf("%d\n",ans);
	}
	return 0;
}


