                                            
  //File Name: zoj3872.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 14时08分16秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long

using namespace std;

int a[100000+5];
int l[1000000+5];

void solve(int n)
{
	memset(l,0,sizeof l);
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans += (LL)a[i] * (n - i + 1) * (i - l[a[i]]);
		l[a[i]] = i;
	}
	cout << ans << endl;
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
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
