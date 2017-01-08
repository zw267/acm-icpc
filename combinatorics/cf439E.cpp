                                            
  //File Name: cf439E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月17日 星期三 14时58分16秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

LL f[MAXN];
LL jie[MAXN];
bool is[MAXN];
vector<int> dive;
map< pair<int,int>,int > rem; 

void init()
{
	jie[0] = 1;
	for(int i=1;i<MAXN;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
	rem.clear();
}

void get_dive(int sum,int n)
{
	int e = (int)sqrt(sum + 0.0);
	dive.clear();
	int j;
	for(int i=1;i<=e;i++){
		if(sum % i == 0){
			if(sum / i >= n)
				dive.pb(i);
			j = sum / i;
			if(j != i && sum / j >= n)
				dive.pb(j);
		}
	}
	sort(dive.begin(),dive.end());
	for(int i=0;i<dive.size();i++){
		is[dive[i]] = true;
	}
}

LL qp(LL x,LL y)
{
	LL res = 1LL;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL comb(int x ,int y)
{
	if(y < 0 || y > x)
		return 0;
	if(y == 0 || y == x)
		return 1;
	return jie[x] * qp(jie[y] * jie[x-y] % MOD,MOD  - 2) % MOD;
}

void solve(int sum,int n)
{
	map< pair<int,int>,int >::iterator it;
	it = rem.find(make_pair(sum,n));
	if(it != rem.end()){
		printf("%d\n",(int)(it->second));
		return ;
	}
	memset(f,0,sizeof f);
	memset(is,false,sizeof is);
	get_dive(sum,n);
	int ma = dive.size();
	for(int i=ma-1;i>=0;i--){
		int d = dive[i];
		f[d] = comb(sum / d - 1,n - 1);
		for(int j=2*d;j<=dive[ma-1];j+=d){
			if(is[j]){
				f[d] = ((f[d] - f[j] + MOD) % MOD + MOD) % MOD;
			}
		}
	}
	printf("%d\n",(int)f[1]);
	rem[make_pair(sum,n)] = f[1];
	return ;
}

int main()
{
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int sum,n;
		scanf("%d %d",&sum,&n);
		solve(sum,n);
	}
	return 0;
}
