                                            
  //File Name: poj1284.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月13日 星期日 20时51分34秒
                                   

#include <cstdio>
#include <cstring>

const int MAXN = 65537;

int phi[MAXN];

void init()
{
	for(int i=0;i<MAXN;i++)
		phi[i] = i;
	for(int i=2;i<MAXN;i++){
		if(phi[i] == i){
			for(int j=i;j<MAXN;j+=i){
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main()
{
	init();
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",phi[n-1]);
	}
	return 0;
}
