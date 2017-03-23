                                            
  //File Name: cf777C.cpp
  //Created Time: 2017年03月23日 星期四 18时38分46秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
vector<int> a[MAXN],f[MAXN];
int g[MAXN];
void solve(int n,int m){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(i == 0) f[0][j] = 0;
			else if(a[i][j] >= a[i - 1][j])
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = i;
		}
	}
	for(int i=0;i<n;++i){
		g[i] = i;
		for(int j=0;j<m;++j)
			g[i] = min(g[i],f[i][j]);
	}
	int k,l,r;
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&l,&r);
		--l,--r;
		if(g[r] <= l) puts("Yes");
		else puts("No");
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		for(int j=0,u;j<m;++j){
			scanf("%d",&u);
			a[i].push_back(u);	
			f[i].push_back(-1);
		}
	}
	solve(n,m);
	return 0;
}
