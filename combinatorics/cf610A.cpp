                                            
  //File Name: cf610A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 20时16分14秒
                                   

#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	if(n % 2)
		puts("0");
	else
		printf("%d\n",(n/2 - 1) / 2);
	return 0;
}
