                                            
  //File Name: 231.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月06日 星期日 01时02分40秒
                                   
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#define LL long long
using namespace std;
const int MAXN = 20000000  + 1;
int prime[MAXN],sum[MAXN],fir[MAXN];
void cal(int x,int f){
	if(x == 1) return ;
	int pre = fir[x],num = 0;
	while(x > 1){
		num = 0;
		while(x > 1 && prime[fir[x]] == prime[pre]){
			x /= prime[pre];
			num++;
		}
		sum[pre] += f * num;
		pre = fir[x];
	}
}
LL solve(int n,int m){
	m = min(m,n - m);
	memset(fir,-1,sizeof(fir));
	int tot = 0;
	for(int i=2;i<=n;i++){
		if(fir[i] == -1){
			prime[tot++] = i;
			fir[i] = tot - 1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] > n) break;
			fir[i * prime[j]] = j;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i=n-m+1;i<=n;i++)
		cal(i,1);
	for(int i=2;i<=m;i++)
		cal(i,-1);
	LL res = 0;
	for(int i=0;i<tot;i++){
		res += 1LL * prime[i] * sum[i];
	}
	return res;
}
int main(){
	int n,m;
	cin >> n >> m;
	cout << solve(n,m) << endl;
	return 0;
}
