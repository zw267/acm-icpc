                                            
  //File Name: cf624A.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月05日 星期五 21时50分34秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int d,l,v1,v2;
	scanf("%d %d %d %d",&d,&l,&v1,&v2);

	printf("%.10f\n",(l - d + 0.0) / (v1 + v2 + 0.0));
	return 0;
}
