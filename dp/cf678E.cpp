                                            
  //File Name: cf678E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月12日 星期三 20时12分49秒

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
double p[18][18],f[1<<18][18];
double solve(int n){
	f[1][0] = 1.0;
	for(int i=2;i<(1<<n);i++){
		if(i & 1 == 0) continue;
		for(int j=0;j<n;j++){
			if((i & (1<<j)) == 0) continue;
			for(int k=0;k<n;k++){
				if(k != j && (i & (1<<k)))
				f[i][j]=max(f[i][j],f[i-(1<<k)][j]*p[j][k]+f[i-(1<<j)][k]*p[k][j]);
			}
		}
	}
	double ans = 0.0;
	for(int i=0;i<n;i++)
		ans = max(ans,f[(1<<n)-1][i]);
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lf",&p[i][j]);
	printf("%.12f\n",solve(n));
	return 0;
}

