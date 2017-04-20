                                            
  //File Name: cf788B.cpp
  //Created Time: 2017年04月21日 星期五 01时43分43秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 3;
vector<int> G[MAXN];
int loop[MAXN];
int neibour[MAXN];
int fa[MAXN];
int siz[MAXN];
int one[MAXN];
int find_fa(int x){
	if(fa[x] == x) return x;
	fa[x] = find_fa(fa[x]);
	siz[fa[x]] += siz[x];
	siz[x] = 0;
}
LL solve(int n,int m){
	int num = 0,num_loop = 0,one_deg = 0;
	for(int i=1;i<=n;++i){
		if(find_fa(i) == i && (siz[i] > 1 || loop[i]))
			++num;
		if(loop[i])
			++num_loop;
		if(neibour[i] == 1)
			++one_deg;
		if(neibour[i] == 1){
			++one[G[i][0]];
		}
	}
	if(num > 1) return 0;
	LL res = 0;
	for(int i=1;i<=n;++i){
		res += (LL)neibour[i] * (neibour[i] - 1) / 2;
		if(loop[i])
//			res += (m  - num_loop - (one_deg - one[i] + neibour[i] == 1));
			res += (m - num_loop);
	}
	res += (LL)num_loop * (num_loop - 1) / 2;
	return res;
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	memset(loop,0,sizeof loop);
	for(int i=1;i<=n;++i)
		fa[i] = i,siz[i] = 1;
	for(int i=1;i<=m;++i){
		scanf("%d %d",&u,&v);
		if(u == v) loop[u] = 1;
		else{
			++neibour[u];
			++neibour[v];
			G[u].push_back(v);
			G[v].push_back(u);
			int fau = find_fa(u);
			int fav = find_fa(v);
			if(fau == fav) continue;
			fa[fau] = fav;
			siz[fav] += siz[fau];
			siz[fau] = 0;
		}
	}
	printf("%lld\n",solve(n,m));
	return 0;
}
