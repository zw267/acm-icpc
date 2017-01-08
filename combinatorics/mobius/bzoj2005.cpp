                                            
  //File Name: bzoj2005.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 14时08分18秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 100000+5;

LL f[MAXN];

void solve(int n,int m)
{
	LL ans = 0LL;
	int mi = min(n,m);
	memset(f,0,sizeof f);
	for(int i=mi;i>0;i--){
		f[i] = (LL)(n/i) * (m/i);
		for(int j=2;j<=mi/i;j++){
			f[i] -= f[j*i];
		}
		ans += f[i] * (i * 2LL - 1);
	}

	cout << ans << endl;
	return ;
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		solve(n,m);
	}
	return 0;
}
