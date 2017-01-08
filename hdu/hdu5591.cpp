                                            
  //File Name: hdu5591.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月11日 星期一 21时37分17秒
                                   


#include <cstdio>

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		if(n % 2 == 1)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
