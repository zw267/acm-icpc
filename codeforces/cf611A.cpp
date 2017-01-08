                                            
  //File Name: cf611A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月14日 星期四 20时30分36秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[3],t[5];

int solve(int n)
{
	if(t[0] == 'm'){
		if(n <= 29)
			return 12;
		else if(n == 30)
			return 11;
		else
			return 7;
	}
	else{
		int ans = (366 - 3) / 7;
		if(n <= 6)
			ans++;
		if(n >= 5)
			ans++;
		return ans;
	}
}

int main()
{
	int n;
	scanf("%d %s %s",&n,s,t);
	printf("%d\n",solve(n));
	return 0;
}
