                                            
  //File Name: cf597.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月31日 星期四 21时50分18秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 100000 + 5;

LL f[MAXN][12];
LL bit[MAXN];
int a[MAXN];

inline int lb(int x){
	return x & (-x);
}

void update(int p,LL add,int n){
	while(p <= n){
		bit[p] += add;
		p += lb(p);
	}
}

LL query(LL p){
	LL res = 0;
	while(p > 0){
		res += bit[p];
		p -= lb(p);
	}
	return res;
}

void solve(int n,int k){
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][1] = 1;
	}
	k++;
	for(int j=2;j<=k;j++){
		memset(bit,0,sizeof bit);
		for(int i=1;i<=n;i++){
			f[i][j] += query(a[i]);
			update(a[i],f[i][j-1],n);
		}
	}

	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans += f[i][k];
	}
	cout << ans << endl;
	return ;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n,k);
	return 0;
}
