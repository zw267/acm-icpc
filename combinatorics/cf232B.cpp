                                            
  //File Name: cf232B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月25日 星期四 22时28分20秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

const int MOD = (int)1e9+7;

LL comb[101][101];
LL the[101];
LL f[101][10000+5];

LL qp(LL ,LL );

void init(int n,LL m)
{
	memset(comb,0,sizeof comb);
	for(int i=0;i<=n;i++)
		comb[i][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}
	LL cur = (m / n) % (MOD - 1);
	for(int i=0;i<=n;i++){
		the[i] = qp(comb[n][i],cur);
	}
}

LL qp(LL x, LL y)
{
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void solve(int n,LL m,int sum)
{
	init(n,m);
	memset(f,0,sizeof f);
	f[0][0] = 1;
	LL cur;
	for(int i=0;i<n;i++){
		for(int j=0;j<=min(i*n,sum);j++){
			if(f[i][j] == 0)
				continue;
			for(int k=0;k<=n;k++){
				if(j + k > sum)
					break;
				if(m % n >= (i + 1))
					cur = the[k] * comb[n][k] % MOD;
				else
					cur = the[k];
				(f[i+1][j+k] += (f[i][j] * cur % MOD)) %= MOD;
			}
		}
	}

	//for(int i=1;i<=n;i++){
	//	for(int j=0;j<=sum;j++){
	//		cout << f[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << f[n][sum] << endl;
	return ;
}

int main()
{
	int n,sum;
	LL m;
	cin >> n >> m >> sum;
	solve(n,m,sum);
	return 0;
}
