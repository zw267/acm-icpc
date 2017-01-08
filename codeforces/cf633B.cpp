                                            
  //File Name: cf633B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月27日 星期六 22时22分55秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 500000+5;

int num[MAXN];
int ans[MAXN];
void init()
{
	num[0] = 0;
	for(int i=1;i<MAXN;i++){
		num[i] = num[i/5] + i/5;
	}
	//for(int i=0;i<20;i++)
	//	printf("%d  ",num[i]);
}

int bs(int m)
{
	int l = 1,r = 5 * m;
	int mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(num[mid] < m)
			l = mid;
		else
			r = mid;
	}
	if(num[l] == m)
		return l;
	return r;
}

int main()
{
	int m;
	while(~scanf("%d",&m)){
		init();
		int pos = bs(m);
		int len = 0;
		for(int i=pos;num[i] == m;i++){
			ans[len++] = i;
		}
		printf("%d\n",len);
		if(len > 0){
			for(int i=0;i<len-1;i++)
				printf("%d ",ans[i]);
			printf("%d\n",ans[len-1]);
		}
	}
	return 0;
}
