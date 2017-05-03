                                            
  //File Name: hdu3480.cpp
  //Created Time: 2017年05月02日 星期二 18时06分14秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10000 + 2;
const int MAXM=  5000 + 2;
int f[MAXM][MAXN];
int a[MAXN];
int deqk[MAXN],deqb[MAXN];
bool g1(int i,int j,int cur){
	return deqb[i] - deqb[j] <= cur * (deqk[i] - deqk[j]);
}
bool g2(int i,int j,int k){
	return (deqb[i] - deqb[j]) * (deqk[j] - deqk[k]) <=
		   (deqb[j] - deqb[k]) * (deqk[i] - deqk[j]);
}
int solve(const int n,const int m){
	sort(a + 1,a + n + 1);
	f[1][0] = 0;
	for(int i=1;i<=n;++i)
		f[1][i] = (a[i] - a[1]) * (a[i] - a[1]);
	for(int i=2;i<=m;++i){
		int head(0),tail(0);
		deqk[tail] = a[1];
		deqb[tail++] = a[1] * a[1];
		for(int j=1;j<=n;++j){
			while(head + 1 < tail && g1(head + 1,head,2 * a[j]))
				++head;
			f[i][j] = a[j] * a[j] - 2 * a[j] * deqk[head] + deqb[head];
			deqk[tail] = a[j + 1];
			deqb[tail++] = a[j + 1] * a[j + 1] + f[i-1][j];
			while(tail - head >= 3 && g2(tail - 1,tail - 2,tail - 3)){
				deqk[tail - 2] = deqk[tail - 1];
				deqb[tail - 2] = deqb[tail - 1];
				--tail;
			}
		}
	}
	return f[m][n];
}
int main(){
	int t,cas(1),n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",a + i);
		printf("Case %d: %d\n",cas++,solve(n,m));
	}
	return 0;
}
