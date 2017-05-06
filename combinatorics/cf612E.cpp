                                            
  //File Name: cf612E.cpp
  //Created Time: 2017年05月05日 星期五 22时19分59秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 5;
int p[MAXN];
bool vis[MAXN];
vector<int> loop[MAXN];
int ans[MAXN];
int tmp[MAXN];
bool solve(int n){
	memset(vis,false,sizeof vis);
	for(int i(1);i<=n;++i){
		if(vis[i]) continue;
		int num(0),u(i),tot(0);
		while(!vis[u]){
			++num;
			vis[u] = true;
			tmp[tot++] = u;
			u = p[u];
		}
		if(num == 1)
			ans[i] = i;
		else if(num & 1){
			for(int j(0),k;j<tot;++j){
				k = j + (tot - 1) / 2;
				if(k >= tot) k -= tot;
				ans[tmp[k]] = tmp[j];
			}
		}
		else{
			loop[num].push_back(i);
		}
	}
	for(int i(2);i<=n;i+=2){
		if(!loop[i].size()) continue;
		int m = loop[i].size();
		if(m & 1) return false;
		for(int j=0;j<m;j+=2){
			int u = loop[i][j];
			int v = loop[i][j + 1];
			for(int k(1);k<=i;++k){
				ans[u] = v;
				u = p[u];
				ans[v] = u;
				v = p[v];
			}
		}
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1);i<=n;++i){
		scanf("%d",p + i);
	}
	bool can = solve(n);
	if(!can) puts("-1");
	else{
		for(int i(1);i<=n;++i)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
