                                            
  //File Name: hdu2829.cpp
  //Created Time: 2017年05月02日 星期二 16时21分13秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000 + 10;
int a[MAXN];
int sum1[MAXN],sum2[MAXN];
int f[MAXN][MAXN];
int deqk[MAXN],deqb[MAXN];
void init(const int n){
	sum1[0] = sum2[0] = 0;
	for(int i=1;i<=n;++i){
		sum1[i] = sum1[i - 1] + a[i];
		sum2[i] = sum2[i - 1] + a[i] * sum1[i - 1];
	}
}
bool g1(int j,int k,int cur){
	return deqb[j] - deqb[k] <= cur * (deqk[j] - deqk[k]);
}
bool g2(int i,int j,int k){
	return (deqb[i] - deqb[j]) * (deqk[j] - deqk[k]) <= 
		   (deqb[j] - deqb[k]) * (deqk[i] - deqk[j]);
}
int solve(const int n,const int m){
	init(n);
	for(int i=1;i<=n;++i)
		f[1][i] = sum2[i];
	for(int i=2;i<=m;++i){
		int head(0),tail(0);
		deqk[tail] = 0;
		deqb[tail++] = 0;
		for(int j=1;j<=n;++j){
			while(head + 1 < tail && g1(head + 1,head,sum1[j]))
				++head;
			f[i][j] = sum2[j] - sum1[j] * deqk[head] + deqb[head];
			deqk[tail] = sum1[j];
			deqb[tail++] = f[i-1][j] - sum2[j] + sum1[j] * sum1[j];
			while(tail - 3 >= head && g2(tail-1,tail-2,tail-3)){
				deqk[tail - 2] = deqk[tail - 1];
				deqb[tail - 2] = deqb[tail - 1];
				--tail;
			}
		}
	}
	return f[m][n];
}
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(!n && !m) break;
		for(int i=1;i<=n;++i)
			scanf("%d",a + i);
		printf("%d\n",solve(n,m + 1));
	}
	return 0;
}
