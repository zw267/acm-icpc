                                            
  //File Name: 51nod1604.cpp
  //Created Time: 2017年03月27日 星期一 22时32分46秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000 + 5;
const int P = (int)1e9 + 7;
LL f[MAXN][MAXN];
LL jie[MAXN * MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
LL C(int x,int y){
	if(y > x || y < 0) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % P,P - 2) % P;
}
void init(int n,int k){
	jie[0] = 1;
	for(int i=1;i<=k;++i)
		jie[i] = jie[i - 1] * i % P;
	for(int i=1;i<=n;++i){
		f[i][1] = 1;
		for(int j=2;j<=min(i,k);++j){
			f[i][j] = f[i-1][j] * j + f[i-1][j-1];
			f[i][j] %= P;
		}
	}
}
LL solve(int n,int m,int k){
	init(n,k);
	LL res = 0;
	for(int x=1;x<=min(n,k);++x){
		LL cur = C(k,x) * f[n][x] % P * f[n][x] % P * jie[x] % P * jie[x] % P;
		for(int y=0;y<=x;++y){
			LL tmp = cur * C(x,y) % P * C(k-x,x-y) % P * qp(y,n * m - n - n) % P;
			res += tmp;
			if(res >= P) res -= P;
		}
	}
	return res;
}
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	cout << solve(n,m,k) << endl;
	return 0;
}
