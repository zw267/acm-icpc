                                            
  //File Name: cf337E.cpp
  //Created Time: 2017年04月26日 星期三 21时01分28秒
                                   
#include <bits/stdc++.h>
#define LL long long 
#define pli pair<long long,int>
#define fir first
#define sec second
using namespace std;
LL a[11],b[11];
int fa[11];
int n;
int ans(1e9);
vector<pli> prime[11];
vector<int> son[11];
void cal(){
	for(int i=0;i<=n;++i)
		son[i].clear();
	for(int i=0;i<n;++i)
		son[fa[i]].push_back(i);
	int res = 0;
	for(int i=n;i>=0;--i){
		++res;
		if(i == n){
			if(son[i].size() == 1)
				--res;
			continue;
		}
		if(b[i] == 1 || (prime[i].size() == 1 && prime[i][0].sec == 1))
			continue;
		for(auto p:prime[i]){
			int cur = 0;
			for(auto u:son[i]){
				for(auto w:prime[u]){
					if(w.fir > p.fir) break;
					if(w.fir == p.fir)
						cur += w.sec;
				}
			}
			res += max(0,p.sec - cur);
		}
	}
	ans = min(ans,res);
}
void dfs(int p){
	if(p == n){
		cal();
		return ;
	};
	for(int i=p+1;i<n;++i){
		if(b[i] % a[p] == 0){
			b[i] /= a[p];
			fa[p] = i;
			dfs(p + 1);
			b[i] *= a[p];
		}
	}
	fa[p] = n;
	dfs(p + 1);
}
int solve(){
	sort(a,a + n);
	for(int i=0;i<n;++i)
		b[i] = a[i];
	for(int i=0;i<n;++i){
		LL cur = a[i];
		for(LL j=2;j*j<=cur;++j){
			if(cur % j == 0){
				pli now(j,0);
				while(cur % j == 0){
					++now.sec;
					cur /= j;
				}
				prime[i].push_back(now);
			}
		}
		if(cur > 1) prime[i].push_back(pli(cur,1));
		sort(prime[i].begin(),prime[i].end());
	}
	dfs(0);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",a + i);
	solve();
	printf("%d\n",ans);
	return 0;
}

