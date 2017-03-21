                                            
  //File Name: D.cpp
  //Created Time: 2017年03月21日 星期二 20时32分44秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2000 + 5;
const int P = (int)1e9 + 7;
const int INF = 2000000000 + 1;
int a[MAXN];
LL f[MAXN][MAXN][2];
LL solve(int n){
	sort(a + 1,a + n + 1);
	int mi = INF;
	for(int i=2;i<=n;++i)
		if(a[i] - a[i - 1] < mi)
			mi = a[i] - a[i - 1];
	f[1][0][0] = 1;
	for(int i=2;i<=n;++i){
		for(int j=0;j<=i;++j){
			if(a[i] - a[i - 1] != mi){
				f[i][j][1] = 0;
				f[i][j][0] = (f[i-1][j][0] + f[i-1][j][1]) * (i-j) % P +
					(f[i-1][j+1][0] + f[i-1][j+1][1]) * (j + 1) % P;
			}
			else{
				f[i][j][0] = f[i-1][j][0] * (i-j-2) % P +
					         f[i-1][j][1] * (i-j-1) % P +
							 f[i-1][j+1][0] * (j+1) % P +
							 f[i-1][j+1][1] * j % P;
				f[i][j][1] = f[i-1][j][1];
				if(j > 0)
					f[i][j][1] += f[i-1][j-1][0] * 2 + f[i-1][j-1][1];
			}
			f[i][j][0] %= P;
			f[i][j][1] %= P;
		}
	}
	LL res = 0;
   	for(int j=1;j<=n;++j)
		res = (res + f[n][j][0] + f[n][j][1]) % P;
	return res;	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a + i);
	printf("%lld\n",solve(n));
	return 0;
}
