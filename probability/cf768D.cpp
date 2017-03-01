                                            
  //File Name: cf768D.cpp
  //Created Time: 2017年02月27日 星期一 13时57分53秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10000;
const int N = 1001;
double f[MAXN][N];
void solve(int n,int q){
	f[0][0] = 1.0;
	for(int i=1;i<MAXN;++i){
		for(int j=1;j<=n;++j)
			f[i][j] = f[i-1][j]*j/n + f[i-1][j-1]*(n-j+1)/n;
	}
	int p;
	while(q--){
		scanf("%d",&p);
		int ans = -1;
		for(int i=1;i<MAXN;++i){
			if(f[i][n] >= (double)p / 2000){
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	solve(n,q);
	return 0;
}
