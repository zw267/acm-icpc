                                            
  //File Name: zoj3869.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月05日 星期六 12时48分58秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int a[MAXN];

void solve(int n)
{
	memset(a,0,sizeof a);
	int cur;
	for(int i=1;i<=n;i++){
		scanf("%d",&cur);
		a[cur]++;
	}
	int ma = 0;
	for(int i=1;i<=1000;i++){
		if(a[i] > a[ma])
			ma = i;
	}
	int num = 0;
	for(int i=1;i<=1000;i++){
		if(a[i] == a[ma])
			num++;
	}
	if(num > 1)
		puts("Nobody");
	else
		printf("%d\n",ma);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}
