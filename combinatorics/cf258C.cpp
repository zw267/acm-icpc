                                            
  //File Name: cf258C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月23日 星期二 18时30分26秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define LL long long 
#define pb push_back

using namespace std;

const int MAXN = (int)1e5+5;
const int MOD = (int)1e9+7;

int a[MAXN];
vector<int> dive[MAXN];
int pos[MAXN];
int ma;

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

void get_dive(int x)
{
	for(int i=1;i<=x;i++){
		dive[i].clear();
		int e = (int)sqrt(i + 0.0);
		for(int j=1;j<=e;j++){
			if(i % j == 0){
				dive[i].pb(j);
				if((i / j) != j)
					dive[i].pb(i / j);
			}
		}
		sort(dive[i].begin(),dive[i].end());
	}
}

int bs(int l,int r,int x)
{
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(a[mid] < x)
			l = mid;
		else
			r = mid;
	}
	if(a[l] >= x)
		return l;
	return r;
}

void solve(int n)
{
	sort(a+1,a+n+1);
	ma = a[n];
	get_dive(ma);
	pos[1] = 1;
	for(int i=2;i<=ma;i++){
		pos[i] = bs(pos[i-1],n,i);
	}
	LL ans = 0LL;
	LL tmp;
	for(int i=1;i<=ma;i++){
		int x = n - pos[i] + 1;
		int y = (int)dive[i].size();
		tmp = (qp(y,x) - qp(y-1,x) + MOD) % MOD;
		for(int j=0;j<dive[i].size() - 1;j++){
			tmp = tmp * qp(j+1,pos[dive[i][j+1]] - pos[dive[i][j]]) % MOD;
		}
		ans = (ans + tmp) % MOD;
	}
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
