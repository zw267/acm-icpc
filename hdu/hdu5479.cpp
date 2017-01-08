                                            
  //File Name: hdu5479.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月14日 星期四 19时37分09秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1005;

char str[MAXN];

int solve()
{
	int n = strlen(str);
	int x = 0;
	while(x < n && str[x] == ')')
		x++;
	int y = n-1;
	while(y >= 0 && str[y] == '(')
		y--;
	if(y <= x)
		return 0;
	int ans1 = 0,ans2 = 0;
	for(int i=x;i<=y;i++){
		if(str[i] == '(')
			ans1++;
		else
			ans2++;
	}
	return ans1 < ans2 ? ans1 : ans2;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%s",str);
		printf("%d\n",solve());
	}
	return 0;
}
