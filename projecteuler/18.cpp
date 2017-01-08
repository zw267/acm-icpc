                                            
  //File Name: 18.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 01时26分21秒
                                   
#include <stdio.h>
#include <algorithm>
int a[16][16],f[16][16];
int main(){
	freopen("data.in","r",stdin);
	int n = 15;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		f[n][i] = a[n][i];
	for(int i=n-1;i>0;i--){
		for(int j=1;j<=i;j++)
			f[i][j] = std::max(f[i+1][j],f[i+1][j+1]) + a[i][j];
	}
	printf("%d\n",f[1][1]);
	return 0;
}
