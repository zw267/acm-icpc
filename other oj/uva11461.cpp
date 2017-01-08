                                            
  //File Name: uva11461.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2015年12月23日 星期三 18时43分27秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 100000+5;

int sum[MAXN];

void init()
{
	sum[0] = 0;
	for(double i=1.0;i<(double)MAXN;i+=1.0){
		int e = (int)sqrt(i);
		int j = (int)i;
		if((double)e * e == i)
			sum[j] = sum[j-1] + 1;
		else
			sum[j] = sum[j-1];
	}
}

int main()
{
	init();
	int l,r;
	while(~scanf("%d %d",&l,&r)){
		if(!l && !r)
			break;
		printf("%d\n",sum[r] - sum[l - 1]);		
	}
	return 0;
}
