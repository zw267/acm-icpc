                                            
  //File Name: cf632D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月09日 星期三 22时31分35秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = (int)1e6 + 5;
int sum[MAXN],a[MAXN],ans[MAXN];
void solve(int n,int m){
	for(int i=m;i>0;i--){
		for(int j=i;j<=m;j+=i)
			sum[j] += sum[i];
	}
	int lcm = 0,tot = 0;
	for(int i=1;i<=m;i++){
		if(sum[i] > tot)
			tot = sum[i],lcm = i;
	}
	if(tot == 0){
		printf("1 0\n\n");
		return ;
	}
	tot = 0;
	for(int i=1;i<=n;i++){
		if(lcm % a[i] == 0)
			ans[tot++] = i;
	}
	printf("%d %d\n",lcm,tot);
	for(int i=0;i<tot;i++)
		printf("%d ",ans[i]);
//	puts("");
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a + i);
		if(a[i] <= m)
			sum[a[i]]++;
	}
	solve(n,m);
	return 0;
}
