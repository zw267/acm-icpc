                                            
  //File Name: nod1406.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月09日 星期日 11时53分29秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1<<20];
void solve(int pre,int i){
	if(i < 0) return ;
	solve(pre,i-1);
	solve(pre+(1<<i),i-1);
	for(int j=0;j<(1<<i);j++)
		f[pre+j] += f[pre+(1<<i)+j];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0,u;i<n;i++){
		scanf("%d",&u);
		f[u]++;
	}
	solve(0,19);
	for(int i=0;i<=1000000;i++)
		printf("%d\n",f[i]);
	return 0;
}
