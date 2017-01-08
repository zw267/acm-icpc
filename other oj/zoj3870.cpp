                                            
  //File Name: zoj3870.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 13时26分29秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 100000+5;

int a[MAXN];
int b[35];
LL p[35];

bool cmp(int x,int y)
{
	return x > y;
}

void init()
{
	p[0] = 1LL;
	for(int i=1;i<33;i++){
		p[i] = p[i-1] * 2;
	}
}

int bs(int l,int r,int v)
{
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(a[mid] >= v)
			r = mid;
		else
			l = mid;
	}
	//printf("l = %d r = %d a[l] = %d a[r] = %d\n",l,r,a[l],a[r]);
	if(a[l] >= v)
		return l;
	return r;
}

LL get(int r,int tot)
{
	LL ans = 0;
	int pos = tot - 1;
	for(int i=tot-2;i>=0;i--){
		if(b[i] == 0)
			continue;
		ans += (LL)bs(1,r,p[pos]) - bs(1,r,p[i+1]);
		pos = i;
	}
	ans += (LL)bs(1,r,p[pos]) - 1;
	return ans;
}

void solve(int n)
{
	sort(a+1,a+n+1);
	LL ans = 0;
	for(int i=n;i>0;i--){
		int tot = 0;
		int tmp = a[i];
		while(tmp){
			b[tot++] = tmp % 2;
			tmp /= 2;
		}
		ans += get(i,tot);
		//printf("i = %d ans = %d\n",i,ans);
	}
	cout << ans << endl;
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	init();
	while(test--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
