                                            
  //File Name: 51nod1306.cpp
  //Created Time: 2017年04月18日 星期二 00时39分31秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL MAXN = 1e18;
const int M = 65;
vector<LL> f[M];
void init(){
	for(int i=0;i<=1900000;++i)
		f[0].push_back(0);
	for(int j=1;j<M;++j){
		f[j].push_back(0);
		for(int i=1;i<=1900000;++i){
			LL tmp = f[j - 1][i - 1] + f[j][i - 1] + 1;
			f[j].push_back(tmp);
			if(tmp >= MAXN) break;
		}
	}
}
int main(){
	init();
	int t,m;
	LL n;
	scanf("%d",&t);
	while(t--){
		LL ans(0);
		scanf("%lld %d",&n,&m);
		if(m == 1) 
			ans = n;
		else if(m == 2){
			ans = sqrt(n + n);
			if(ans * (ans + 1) / 2 < n)
				++ans;
			else if(ans * (ans - 1) / 2 >= n)
				--ans;
		}
		else{
			ans = lower_bound(f[m].begin(),f[m].end(),n) - f[m].begin();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
