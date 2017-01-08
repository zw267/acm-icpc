                                            
  //File Name: fzu2216.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 00时27分42秒
                                   
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100000+5;

int a[MAXN];
int vis[MAXN];

void solve(const int n,const int m,const int sum)
{
	sort(a+1,a+n+1);
	int l = 1,r = 1,use = 0,ans = min(m,sum);
	while(l <= n){
		while(r < n && a[r+1] - a[r] - 1 <= sum - use){
			use += a[r+1] - a[r] - 1;
			r++;
		}
		//if(r - l + 1 + sum - use > ans){
		//	printf("l = %d  r = %d  sum = %d  use = %d\n",l,r,sum,use);
		//	ans=  r - l + 1 + sum - use;
		//	printf("ans = %d\n",ans);
		//}
		ans = max(ans,min(r - l + 1 + sum ,m));
		if(r > l)
			use -= a[l+1] - a[l] - 1;
		l++;
		r = max(l,r);
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,sum = 0,tot = 0;
		scanf("%d %d",&n,&m);
		memset(vis,0,sizeof vis);
		int u;
		for(int i=1;i<=n;i++){
			scanf("%d",&u);
			if(u == 0)
				sum++;
			else if(!vis[u]){
				a[++tot] = u;
				vis[u] = 1;
			}
		}
		solve(tot,m,sum);
	}
	return 0;
}
