                                            
  //File Name: cf204C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月24日 星期日 13时50分09秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 200000 + 5;

LL p[26][MAXN];
int num[26][MAXN];
char a[MAXN],b[MAXN];

double solve(const int n){
	memset(p,0,sizeof p);
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++){
		int u = b[i] - 'A';
		p[u][i] = i;
		p[u][n+1] += i;
		num[u][i] = 1;
	}
	for(int j=0;j<26;j++){
		for(int i=n-1;i>0;i--){
			num[j][i] += num[j][i+1];
			p[j][i] += p[j][i+1];
		}
	}
	double ans = 0.0;
	LL tot = (LL)n * (n + 1) * (2 * n + 1) / 6;
	for(int i=1;i<=n;i++){
		int u = a[i] - 'A';
		LL tmp = (n + 1LL - i) * (p[u][n+1] - p[u][i]) +
				 (LL)num[u][i] * i * (n + 1LL) - (LL)i * p[u][i];
		ans += (double)tmp / tot;
	}
	//cout << ans << "  " << tot << endl;
	return ans;
}

int main(){
	int n;
	//n = 200000;
	//printf("%lld\n",n * (n + 1LL) * (2 * n + 1) / 6);
	while(~scanf("%d",&n)){
		scanf("%s %s",a + 1,b + 1);
		printf("%.10f\n",solve(n));
	}
	return 0;
}
