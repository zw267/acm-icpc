                                            
  //File Name: 345.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 01时24分12秒
                                   
#include <stdio.h>
#include <algorithm>
#define LL long long
int a[15][15];
int f[15][1<<15];
void solve(int n){
	for(int i=0;i<n;i++)
		f[0][1<<i] = a[0][i];
	for(int i=1;i<n;i++){
		for(int j=1;j<(1<<n);j++){
			f[i][j] = 0;
			for(int k=0;k<n;k++){
				if(j & (1 << k))
					f[i][j] = std::max(f[i][j],f[i-1][j-(1<<k)] + a[i][k]);
			}
		}
	}
}
int main(){
	int n = 15;
	freopen("data.in","r",stdin);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	solve(n);
	printf("%d\n",f[n-1][(1<<n)-1]);
	fclose(stdin);
	return 0;
}
