                                            
  //File Name: cf274D.cpp
  //Created Time: 2017年03月29日 星期三 21时43分05秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000020;
vector<int> G[MAXN];
vector<int> ans;
int deg[MAXN],tot;
int a[MAXN / 10],b[MAXN / 10];
void add(int x,int y){
	G[x].push_back(y);
	++deg[y];
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	tot = m - 1;
	for(int i=0;i<n;++i){
		int len = 0;
		for(int j=0;j<m;++j){
			scanf("%d",b + j);
			if(b[j] != -1)
				a[len++] = b[j];
		}
		sort(a,a + len);
		len = unique(a,a + len) - a;
		for(int j=0;j<m;++j){
			if(b[j] != -1){
				int k = lower_bound(a,a + len,b[j]) - a;
				add(j,tot + k + 1);
				if(k > 0) add(tot + k,j);
			}
		}
		tot += len;
	}
	queue<int> que;
	for(int i=0;i<=tot;++i)
		if(!deg[i]) que.push(i);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		ans.push_back(u);
		for(auto v:G[u]){
			--deg[v];
			if(!deg[v]) que.push(v);
		}
	}
	if(ans.size() != tot + 1) puts("-1");
	else{
		for(int i=0;i<=tot;++i)
			if(ans[i] >= 0 && ans[i] < m)
				printf("%d ",ans[i] + 1);
		puts("");
	}
	return 0;
}
