                                            
  //File Name: cf459C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 23时54分25秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 1005;

int ans[MAXN][MAXN];

void solve(int n,LL k,int d)
{
	LL cur = k;
	int num = 1;
	while(cur < n && num < d){
		cur *= k;
		num++;
	}
	if(num == d && cur < n){
		puts("-1");
		return ;
	}
	for(int j=1;j<=d;j++)
		ans[1][j] = 0;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=d;j++)
			ans[i][j] = ans[i-1][j];
		ans[i][1]++;
		int cnt = 1;
		while(cnt <d && ans[i][cnt] >= k){
			ans[i][cnt+1]++;
			ans[i][cnt] %= k;
			cnt++;
		}
	}

	for(int j=1;j<=d;j++){
		bool flag = false;
		for(int i=1;i<=n;i++){
			if(flag)
				printf(" ");
			flag = true;
			printf("%d",ans[i][j]+1);
		}
		puts("");
	}
	return ;
}

int main()
{
	int n,d;
	LL k;
	cin >> n >> k >> d;
	solve(n,k,d);
	return 0;	
}
