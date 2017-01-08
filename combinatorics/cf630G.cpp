                                            
  //File Name: cf630G.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月30日 星期一 00时06分16秒
                                   
#include <stdio.h>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 510;

LL c[MAXN][6];

void init_c(){
	for(int i=0;i<MAXN;i++)
		c[i][0] = 1;
	for(int i=0;i<MAXN;i++){
		int mi = min(i,5);
		for(int j=1;j<=mi;j++){
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
}

int main(){
	init_c();
	int n;
	scanf("%d",&n);
	printf("%lld\n",c[n+2][3] * c[n+4][5]);
	return 0;
}
