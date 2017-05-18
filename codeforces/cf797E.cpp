                                            
  //File Name: cf797E.cpp
  //Created Time: 2017年05月18日 星期四 22时56分34秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 2;
const int N = 400;
int a[MAXN];
int b[N][MAXN];
void init(const int n){
	int ma = min(n + 1,N);
	for(int i(1);i<ma;++i){
		for(int j(n);j>0;--j){
			if(j + a[j] + i > n)
				b[i][j] = 1;
			else
				b[i][j] = b[i][j + a[j] + i] + 1;
		}
	}
}
void solve(const int n){
	init(n);
	int q,p,k,ans;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&p,&k);
		if(k < min(N,n + 1)) 
			ans = b[k][p];
		else{
			ans = 0;
			while(p <= n){
				++ans;
				p = p + a[p] + k;
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i(1);i<=n;++i)
		scanf("%d",a + i);
	solve(n);
	return 0;
}
