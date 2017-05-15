                                            
  //File Name: cf799B.cpp
  //Created Time: 2017年05月15日 星期一 11时02分25秒
                                   
#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 200000 + 5;
set<pii> rem[4];
int p[MAXN],a[MAXN],b[MAXN];
int ans[MAXN];
void solve(const int n,const int m){
	for(int i(0);i<n;++i){
		rem[a[i]].insert(pii(p[i],b[i]));
		rem[b[i]].insert(pii(p[i],a[i]));
	}
	for(int i(0),c;i<m;++i){
		scanf("%d",&c);
		if(rem[c].size() == 0)
			ans[i] = -1;
		else{
			pii cur = *rem[c].begin();
			rem[c].erase(cur);
			ans[i] = cur.fir;
			rem[cur.sec].erase(pii(cur.fir,c));
		}
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i(0);i<n;++i)
		scanf("%d",p + i);
	for(int i(0);i<n;++i)
		scanf("%d",a + i);
	for(int i(0);i<n;++i)
		scanf("%d",b + i);
	scanf("%d",&m);
	solve(n,m);
	for(int i(0);i<m;++i)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
