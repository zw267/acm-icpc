                                            
  //File Name: cf630F.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 13时08分28秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

LL f[778][8];

void init(){
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=1;i<778;i++){
		f[i][0] = 1;
		for(int j=1;j<=min(i,7);j++)
			f[i][j] = f[i-1][j] + f[i-1][j-1];
	}
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		cout << f[n][5] + f[n][6] + f[n][7] << endl;
	}
	return 0;
}
