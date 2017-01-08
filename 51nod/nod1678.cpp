                                            
  //File Name: nod1678.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 00时05分25秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000 + 5;
vector<int> fact[MAXN];
bool check[MAXN];
int prime[MAXN],mu[MAXN],a[MAXN],s[MAXN];
void init(int n){
	memset(check,false,sizeof(check));
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<=n;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] > n) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			s[i] += a[j];
			fact[j].push_back(i);
		}
	}
}
void solve(int n,int q){
	init(n);
	while(q--){
		int op,x,y;
		scanf("%d",&op);
		if(op == 1){
			scanf("%d %d",&x,&y);
			for(int j=0;j<fact[x].size();j++){
				int u = fact[x][j];
				s[u] -= a[x];
			}
			a[x] = y;
			for(int j=0;j<fact[x].size();j++){
				int u = fact[x][j];
				s[u] += y;
			}
		}
		else{
			scanf("%d",&x);
			int ans = 0;
			for(int j=0;j<fact[x].size();j++){
				int u = fact[x][j];
				ans += s[u] * mu[u];
			}
			printf("%d\n",ans);
		}
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	solve(n,q);
	return 0;
}


