                                            
  //File Name: cf195E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月20日 星期三 22时53分07秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;
const int MOD = (int)1e9 + 7;

int fa[MAXN];
LL dis[MAXN];

inline void UP(LL &x){
	x = (x % MOD + MOD) % MOD;
}

int find_fa(int x){
	if(fa[x] == x)
		return x;
	int pa = fa[x];
	fa[x] = find_fa(fa[x]);
	dis[x] += dis[pa];
	UP(dis[x]);
	return fa[x];
}

void init(int n){
	for(int i=1;i<=n;i++){
		fa[i] = i;
		dis[i] = 0;
	}
}

void solve(int n){
	LL ans = 0LL;
	init(n);
	for(int j=1,num;j<=n;j++){
		scanf("%d",&num);
		for(int i=1,v,x;i<=num;i++){
			scanf("%d %d",&v,&x);
			int pa = find_fa(v);
			fa[pa] = j;
			dis[pa] = dis[v] + x;
			UP(dis[pa]);
			ans += dis[pa];
			UP(ans);
		}
	}
	printf("%d\n",(int)ans);
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
