                                            
  //File Name: la3295.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月24日 星期四 01时32分15秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

using namespace std;

int gcd(int x,int y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

int get(int i,int j)
{
	return 4 * (i -1) * (j - 1) + 2 * (i + j - 2) + 2 * ((i + 1) * (j + 1) - gcd(i,j) - 1);
}

LL solve(int r,int c)
{
	LL res = 0;
	for(int i=1;i<=r;i++){
		for(int j= 1;j<=c;j++){
			res += (LL) (r - i + 1LL) * (c - j + 1LL) * get(i,j);
		}
	}
	return res;
}

int main()
{
	int r,c;
	int cas = 1;
	while(~scanf("%d %d",&r,&c)){
		if(r == 0 && c == 0)
			break;
	
		printf("Case %d: %lld\n",cas++,solve(r,c));
	}
	return 0;
}
