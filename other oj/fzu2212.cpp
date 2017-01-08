                                            
  //File Name: fzu2212.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月04日 星期五 23时17分44秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[105];

void solve(int n,int m)
{
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(m < a[i])
			break;
		ans++;
		m -= a[i];
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i] = 100 - a[i];
		}
		solve(n,m);
	}
	return 0;
}
