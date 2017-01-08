                                            
  //File Name: cf420C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月06日 星期三 16时11分53秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <map>

#define LL long long
#define mp make_pair
#define fir first
#define sec second

using namespace std;

const int MAXN = 300000 + 3;

int deg[MAXN];
map<pair<int,int>,int> m;
map<pair<int,int>,int>::iterator it;

void solve(int n,int p){
	LL ans = 0;
	int r = n,l = 1;
	int u,v;
	for(it=m.begin();it!=m.end();it++){
		u = (it->fir).fir;
		v = (it->fir).sec;
		if(deg[u] + deg[v] >= p && deg[u] + deg[v] - (it->sec) < p)
			ans--;
	}
	sort(deg+1,deg+n+1);
	while(l <= r && l < n){
		while(r > l && deg[l] + deg[r] >= p)
			r--;
		ans = ans + n - r;
		l++;
		r = max(r,l);
	}
	
	cout << ans << endl;
	return; 
}

int main(){
	m.clear();
	memset(deg,0,sizeof deg);
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=1,u,v;i<=n;i++){
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++;
		if(u > v)
			swap(u,v);
		m[mp(u,v)]++;
	}
	solve(n,p);
	return 0;
}

