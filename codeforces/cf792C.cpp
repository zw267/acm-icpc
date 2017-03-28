                                            
  //File Name: cf792C.cpp
  //Created Time: 2017年03月28日 星期二 13时38分58秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
int f[MAXN][3],g[MAXN][3];
vector<int> ans;
int a[MAXN];
char str[MAXN];
bool solve(){
	int n = strlen(str + 1);
	for(int i=1;i<=n;++i)
		a[i] = str[i] - '0';
	for(int i=0;i<=n;++i)
		for(int j=0;j<3;++j)
			f[i][j] = n;
	f[0][0] = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<3;++j){
			if(f[i][j] == n) continue;
			int nxt = (j + a[i + 1]) % 3;
			if((a[i+1] || (!a[i+1] && f[i][j] < i)) && f[i][j] < f[i+1][nxt]){
				f[i + 1][nxt] = f[i][j];
				g[i + 1][nxt] = j;
			}
			if(f[i][j] + 1 < f[i + 1][j]){
				f[i + 1][j] = f[i][j] + 1;
				g[i + 1][j] = j;
			}
		}
	}
//	printf("f = %d\n",f[n][0]);
	if(f[n][0] == n){
		for(int i=1;i<=n;++i)
			if(!a[i]){
				ans.push_back(0);
				return true;
			}
		return false;
	};
	int i = n,j = 0;
	while(i){
		int pre = g[i][j];
		if(f[i - 1][pre] == f[i][j])
			ans.push_back(a[i]);
		--i;
		j = pre;
	}
	return true;
}
int main(){
	scanf("%s",str + 1);
	bool can = solve();
	if(!can) puts("-1");
	else{
		for(int i=ans.size()-1;i>=0;--i)
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
