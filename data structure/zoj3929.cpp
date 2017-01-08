                                            
  //File Name: zoj3929.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月16日 星期六 16时55分38秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;
const int MOD = (int)1e9 + 7;

LL bit[MAXN];
int p[MAXN],tot;
LL po2[MAXN];

void init(){
	po2[0] = 1;
	for(int i=1;i<MAXN;i++){
		po2[i] = po2[i - 1] * 2 % MOD;
	}
}

inline int lb(int x){
	return x & (-x);
}

void update(int x,LL add){
	while(x <= tot){
		bit[x] = (bit[x] + add) % MOD;
		x += lb(x);
	}
}

LL query(int x){
	LL res = 0;
	while(x <= tot && x > 0){
		res = (res + bit[x]) % MOD;
		x -= lb(x);
	}
	return res;
}

void solve(int n){
	memset(bit,0,sizeof bit);
	tot = n;
	LL ans = 0,cur;
	for(int i=1;i<=n;i++){
		cur = query(p[i] - 1) + query(n) - query(p[i]);
		cur = (cur % MOD + MOD) % MOD;
		cur = (cur * po2[n - i]) % MOD;
		ans = (ans + cur) % MOD;
		if(i > 1)
			update(p[i],po2[i - 1]);
		else
			update(p[i],2);
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		solve(n);
	}
	return 0;
}
