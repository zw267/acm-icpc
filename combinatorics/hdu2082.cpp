                                            
  //File Name: hdu2082.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月19日 星期六 14时15分48秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int a[27];
LL ans[51];
LL c[51];

void solve(){
	memset(ans,0,sizeof ans);
	memset(c,0,sizeof c);
	for(int i=0;i<=a[1];i++)
		ans[i] = 1;
	for(int i=2;i<=26;i++){
		for(int j=0;j<=50;j++){
			for(int k=0;k<=a[i] && k*i+j<=50;k++){
				c[j+k*i] += ans[j];
			}
		}
		for(int j=0;j<=50;j++){
			ans[j] = c[j];
			c[j] = 0;
		}
	}
	LL res = 0;
	for(int i=1;i<=50;i++)
		res += ans[i];

	printf("%lld\n",res);
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		for(int i=1;i<=26;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
