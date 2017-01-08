                                            
  //File Name: cf615D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月04日 星期四 23时24分53秒
                                   

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 200000+5;
const int MOD = 1e9 + 7;

int has[MAXN];
int p[MAXN];
int num[MAXN];
LL inv_2;

LL qp(LL x,LL y)
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

LL get(LL x)
{
	return  x * (x + 1) / 2;
}

void solve(int tot)
{
	//for(int i=1;i<=tot;i++){
	//	printf("%d %d\n",p[i],num[i]);
	//}
	//[1,tot]
	LL sum = 1LL;
	for(int i=1;i<=tot;i++){
		sum = sum * (num[i] + 1) % (MOD - 1);
	}
	LL ans = 1LL;
	for(int i=1;i<=tot;i++){
		LL tmp = qp(qp(p[i],),p[i],sum * num[i]);
		ans = ans * tmp % MOD;
	}

	cout << ans << endl;
	return ;
}

int main()
{
	//inv_2 = qp(2,MOD - 2);
	//LL ans = qp(135391,get(200000));
	//cout << get(200000) << endl;
	//cout << ans << endl;
	int tot = 0;
	memset(has,-1,sizeof has);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		if(has[u] > 0){
			num[has[u]]++;
		}
		else{
			has[u] = ++tot;
			p[has[u]] = u;
			num[has[u]] = 1;
		}
	}
	solve(tot);
	return 0;
}
