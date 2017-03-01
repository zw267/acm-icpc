                                            
  //File Name: cf601C.cpp
  //Created Time: 2017年02月28日 星期二 15时22分01秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 101;
const int N = 1001;
int a[MAXN];
double f[MAXN][MAXN * N];
double solve(int n,int m){
	if(m == 1) return 1.0;
	int ma = n * m;
	for(int i=0;i<=ma;++i)
		f[0][i] = m - 1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=ma;++j){
			int l = max(0,j - m);
			double tmp = 0.0;
			if(l == 0) tmp = f[i-1][j-1];
			else tmp = f[i-1][j-1] - f[i-1][l-1];
			if(l <= j - a[i] && j - a[i] <= j - 1){
				tmp -= f[i-1][j-a[i]];
				if(j - a[i] - 1 >= 0)
					tmp += f[i-1][j-a[i]-1];
			}
			f[i][j] = tmp / (m - 1.0) + f[i][j-1];
		}
	}
	int sum = 0;
	for(int i=1;i<=n;++i)
		sum += a[i];
	return f[n][sum - 1] + 1.0;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a + i);
	}
	printf("%.14f\n",solve(n,m));
	return 0;
}
