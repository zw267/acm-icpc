                                            
  //File Name: bc69A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 19时04分11秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(int a,int b,int c)
{
	if(c % 2 == 1){
		puts("Impossible");
		return ;
	}

	c /= 2;
	int ans1 = -1,ans2 = -1;
	bool flag = false;
	for(int x = 0;x * a <= c;x++){
		int tmp  = c - a * x;
		if(tmp % b)
			continue;
		int y = tmp / b;
		if(!flag || x + y < ans1 + ans2){
			ans1 = x;
			ans2 = y;
			flag = true;
		}
	}
	if(!flag)
		puts("Impossible");
	else
		printf("%d %d\n",ans1 * 2,ans2 * 2);
	return ;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		solve(a,b,c);
	}
	return 0;
}
