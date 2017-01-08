                                            
  //File Name: hdu5364.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月21日 星期四 23时11分07秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int mon[MAXN];

int main()
{
	int n;
	while(~scanf("%d",&n)){
		memset(mon,0,sizeof mon);
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			mon[tmp]++;
		}

		int res = -1;
		for(int i=0;i<MAXN;i++){
			if(mon[i] > n / 2)
				res = i;
		}
		printf("%d\n",res);
	}
	return 0;
}
