                                            
  //File Name: 11.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月02日 星期三 22时55分47秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
int a[20][20];
int solve(){
	int res = 1,tmp;
	for(int i=0;i<17;i++){
		for(int j=0;j<17;j++){
			tmp = a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];
			res = max(res,tmp);
		}
	}
	for(int i=0;i<17;i++){
		for(int j=0;j<20;j++){
			tmp = a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j];
			res = max(res,tmp);
		}
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<17;j++){
			tmp = a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j + 3];
			res = max(res,tmp);
		}
	}
	for(int i=0;i<17;i++){
		for(int j=3;j<20;j++){
			tmp = a[i][j] * a[i+1][j-1] * a[i+2][j-2] * a[i+3][j-3];
			res = max(res,tmp);
		}
	}
	return res;
}
int main(){
	freopen("data.in","r",stdin);
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			scanf("%d",&a[i][j]);
	printf("%d\n",solve());
	return 0;
}
