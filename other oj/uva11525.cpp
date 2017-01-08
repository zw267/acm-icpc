                                            
  //File Name: uva11525.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 19时16分00秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 50000+5;

int c[MAXN];
int ans[MAXN];

inline int lb(int x)
{
	return x & (-x);
}

void update(int x,int add,int n)
{
	while(x <= n){
		c[x] += add;
		x += lb(x);
	}
}

int query(int x)
{
	int res = 0;
	while(x > 0){
		res += c[x];
		x -= lb(x);
	}
	return res;
}

int get(int s,int n)
{
	int l = 1;
	int r = n;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(query(mid) < s)
			l = mid;
		else
			r = mid;
	}
	if(query(l) == s)
		return l;
	else
		return r;
}

void solve(int n)
{
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++){
		update(i,1,n);
	}
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		tmp++;
		ans[i] = get(tmp,n);
		update(ans[i],-1,n);
	}

	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int k;
		scanf("%d",&k);
		solve(k);
	}
	return 0;
}
