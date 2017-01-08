                                            
  //File Name: nod1007.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月28日 星期六 20时12分23秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool f[101][10001];
int a[101];

void solve(int n){
	memset(f,false,sizeof f);
	f[0][0] = true;
	int now = 0;
	for(int i=1;i<=n;i++){
		now += a[i];
		for(int j=0;j<=now;j++){
			f[i][j] = f[i-1][j];
			if(j >= a[i]) f[i][j] |= f[i-1][j-a[i]];
		}
	}
	int ans = 100000;
	for(int i=0;i<=now;i++){
		if(!f[n][i]) continue;
		ans = min(ans,abs(now - 2 * i));
	}
	printf("%d\n",ans);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
	}
	return 0;
}
