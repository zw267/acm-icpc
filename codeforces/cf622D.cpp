                                            
  //File Name: cf622D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月11日 星期四 10时47分40秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		printf("%d %d ",i,i);
	}
	printf("%d %d\n",n,n);
	return 0;
}
