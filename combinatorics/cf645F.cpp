                                            
  //File Name: cf645F.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月15日 星期日 19时58分07秒
                                   

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 100000 + 3;
const int MAXM = 1000000 + 3;
const int MOD = (int)1e9 + 7;

LL jie[MAXN << 1];
LL comb[MAXN << 1];
LL ans;
int g[MAXM];
int f[MAXM];
vector<int> di;

void get_di(int x){
	di.clear();
	int ma = (int)sqrt(x + 0.5);
	for(int i=1,j;i<=ma;i++){
		if(x % i == 0){
			di.pb(i);
			j = x / i;
			if(j != i)
				di.pb(j);
		}
	}
}

LL qp(LL x){
	LL res = 1,y = MOD - 2;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init(int n,int k){
	ans = 0;
	jie[0] = 1;
	for(int i=1;i<=n;i++){
		jie[i] = jie[i - 1] * i % MOD;
	}
	for(int i=0;i<=n;i++){
		if(i < k) comb[i] = 0;
		else comb[i] = jie[i] * qp(jie[k] * jie[i - k] % MOD) % MOD;
	}
	for(int i=1,ma;i<=MAXM;i++){
		g[i] = i;
		get_di(i);
		ma = di.size();
		for(int j=0;j<ma;j++){
			if(di[j] == i) continue;
			g[i] -= g[di[j]];
		}
	}
}

void query(int x){
	get_di(x);
	int ma = di.size();
	for(int i=0;i<ma;i++){
		(ans += comb[f[di[i]]++] * g[di[i]] % MOD ) %= MOD;
	}
}

void solve(int n,int k,int q){
	init(n + q,k - 1);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		query(a);
	}
	for(int i=1,a;i<=q;i++){
		scanf("%d",&a);
		query(a);
		printf("%d\n",ans);
	}
}

int main(){
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	solve(n,k,q);
	return 0;
}
