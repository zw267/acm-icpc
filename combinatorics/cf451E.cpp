                                            
  //File Name: cf451E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月25日 星期四 20时59分56秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long

using namespace std;

const int MOD = (int)1e9+7;

LL a[21];
LL jie[21];
LL b[10];
LL c[10];

LL qp(LL x,LL y)
{
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x *  x % MOD;
		y >>= 1;
	}
	return res;
}

void init(int n)
{
	jie[0] = 1;
	for(int i=1;i<=n;i++)
		jie[i] = jie[i-1] * i % MOD;
}

LL comb(LL x,LL y)
{
	if(y < 0 || y > x)
		return 0;
	if(y == 0 || y == x)
		return 1;
	LL res = 1;
	for(int i=0;i<y;i++){
		res = res * ((x - i) % MOD) % MOD;
	}
	res = res * qp(jie[y], MOD - 2) % MOD;
	return res;
}

LL lucas(LL x,LL y)
{
	if(y < 0 || y > x)
		return 0;
	if(y == 0 || y == x)
		return 1;
	int len_b = 0, len_c = 0;
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	while(x){
		b[len_b++] = x % MOD;
		x /= MOD;
	}
	while(y){
		c[len_c++] = y % MOD;
		y /= MOD;
	}
	int len = max(len_b,len_c);
	LL res = 1;
	for(int i=0;i<len;i++){
		res = res * comb(b[i],c[i]) % MOD;
	}
	return res;
}

void solve(int n,LL sum)
{
	init(n);
	LL ans = 0;
	for(int i=0;i < (1 << n);i++){
		LL cur = 0;
		int num = 0;
		for(int j=0;j<n;j++){
			if(i & (1 << j)){
				num++;
				cur += (a[j] + 1);
			}
		}
		if(num % 2)
			ans = (ans - comb(sum - cur + n - 1, n - 1) + MOD) % MOD;
		else
			ans = (ans + comb(sum - cur + n - 1, n - 1)) % MOD;
	}
	cout << ans << endl;
	return ;
}

int main()
{
	int n;
	LL sum;
	cin >> n >> sum;
	for(int i=0;i<n;i++)
		cin >> a[i];
	solve(n,sum);
	return 0;
}

