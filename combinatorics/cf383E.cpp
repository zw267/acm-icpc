                                            
  //File Name: cf383E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月21日 星期三 20时09分07秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1<<24];
char str[5];
void solve(int pre,int i){
	if(i < 0) return ;
	solve(pre,i-1);
	solve(pre+(1<<i),i-1);
	for(int j=0;j<(1<<i);j++)
		a[pre+(1<<i)+j] += a[pre+j];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		int t = 0;
		for(int j=0;j<3;j++)
			t |= (1<<(str[j]-'a'));
		a[t]++;
	}
	solve(0,23);
	int ans = 0;
	for(int i=0;i<(1<<24);i++){
		int t = n - a[i];
		ans ^= t * t;
	}
	printf("%d\n",ans);
	return 0;
}
