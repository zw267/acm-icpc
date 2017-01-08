                                            
  //File Name: cf261B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月23日 星期六 15时59分05秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 52;

LL f[MAXN][MAXN][MAXN];
int a[MAXN];
double g[MAXN];

void init(const int n){
	for(int j=1;j<n;j++){
		g[j] = 1.0;
		int u = n - j - 1;
		for(int i=1;i<=j;i++){
			g[j] = g[j] * i / (i + u);
		}
		g[j] /= n;
	}
}

double solve(const int n,const int p){
	int s = 0;
	for(int i=1;i<=n;i++)
		s += a[i];
	if(s <= p)
		return n;
	init(n);
	double ans = 0;
	for(int t=1;t<=n;t++){
		memset(f,0,sizeof f);
		f[0][0][0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=p;k++){
					f[i][j][k] = f[i-1][j][k];
					if(j > 0 && k >= a[i] && i != t){
						f[i][j][k] += f[i-1][j-1][k-a[i]];
					}
				}
			}
		}
		for(int j=1;j<n;j++){
			LL tmp = 0;
			for(int k=p-a[t]+1;k<=p;k++)
				tmp += f[n][j][k];
			//printf("t = %d j = %d tmp = %lld\n",t,j,tmp);
			ans += tmp * g[j] * j;
		}
	}
	return ans;
}

int main(){
	int n,p;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&p);
		printf("%.8f\n",solve(n,p));
	}
	return 0;
}
