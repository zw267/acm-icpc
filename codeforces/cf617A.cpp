                                            
  //File Name: cf617A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月23日 星期六 23时39分30秒
                                   
#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	int ans = n / 5;
	if(n % 5 > 0)
		ans++;
	printf("%d\n",ans);

	return 0;
}
