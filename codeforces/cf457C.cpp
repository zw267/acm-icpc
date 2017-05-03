                                            
  //File Name: cf457C.cpp
  //Created Time: 2017年05月03日 星期三 19时02分03秒
                                   
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 100001;
const int INF = 1e9;
vector<int> a[MAXN + 1];
int tmp[MAXN];
int check(int x){
	int cur = a[0].size();  //目前手上的票数
	int res(0),tot(0);
	for(int i=1;i<MAXN;++i){
		int len = a[i].size();
		int j(0);
		if(len >= x){
			for(;j< len + 1 - x;++j){
				res += a[i][j];
				++cur;
			}
		}
		for(;j<len;++j)
			tmp[tot++] = a[i][j];
	}
	int p(0);
	sort(tmp,tmp + tot);
	while(cur < x){
		res += tmp[p++];
		++cur;
	}
	return res;
}
int solve(const int n){
	for(int i=1;i<MAXN;++i)
		sort(a[i].begin(),a[i].end());
	int l(1),r(n);
	while(r - l > 2){
		int midl = l + (r - l) / 3;
		int midr = r - (r - l ) / 3;
		if(check(midl) >= check(midr))
			l = midl;
		else
			r = midr;
	}
	int ans = INF;
	for(int i=l;i<=r;++i)
		ans = min(ans,check(i));
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;++i){
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
	}
	printf("%d\n",solve(n));
	return 0;
}
