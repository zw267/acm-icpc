                                            
  //File Name: cf626D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月08日 星期五 14时34分31秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 2001;

int a[MAXN];
int dif[5000];
int pre[5000];

double solve(const int n){
	memset(dif,0,sizeof dif);
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dif[a[j] - a[i]]++;
		}
	}
	pre[0] = 0;
	for(int i=1;i<5000;i++)
		pre[i] = pre[i-1] + dif[i];
	LL ans = 0;
	for(int i=1;i<5000;i++){
		if(!dif[i]) continue;
		for(int j=1;j<i;j++){
			if(dif[j])
				ans += (LL)pre[i - j - 1] * dif[j] * dif[i];
		}
		//printf("ans = %d\n",ans);
	}
	LL tmp = n * (n - 1) / 2;
	tmp = tmp * tmp * tmp;
	//cout << ans << endl;
	//cout << tmp << endl;
	return (ans + 0.0) / (tmp + 0.0);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%.10f\n",solve(n));
	}
	return 0;
}
