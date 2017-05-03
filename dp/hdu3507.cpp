                                            
  //File Name: hdu3507.cpp
  //Created Time: 2017年05月02日 星期二 14时36分15秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 500000 + 5;
const double INF = 1e15;
int sum[MAXN],f[MAXN];
int deqk[MAXN],deqb[MAXN];
bool g(int x,int y,int cur){
   	return deqb[x] - deqb[y] <= cur * (deqk[x] - deqk[y]);
}
bool g2(int k,int j,int i){
	return (deqb[i] - deqb[j]) * (deqk[j] - deqk[k]) <=
		   (deqb[j] - deqb[k]) * (deqk[i] - deqk[j]);
}
LL solve(const int n,const int m){
	f[0] = 0;
	int head(0),tail(0);
	deqk[tail++] = 0;
	deqb[tail - 1] = 0;
	for(int i=1;i<=n;++i){
		while(head + 1 < tail && g(head + 1,head,2 * sum[i]))
			++head;
		f[i] = -2 * sum[i] * deqk[head] + deqb[head] + sum[i] * sum[i] + m;
		deqk[tail++] = sum[i];
		deqb[tail - 1] = f[i] + sum[i] * sum[i];
		while(head + 2 < tail && g2(tail - 3,tail - 2,tail - 1)){
			deqk[tail - 2] = deqk[tail - 1];
			deqb[tail - 2] = deqb[tail - 1];
			--tail;
		}
	}
	return f[n];
}
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		sum[0] = 0;
		for(int i=1,u;i<=n;++i){
			scanf("%d",&u);
			sum[i] = sum[i - 1] + u;
		}
		printf("%d\n",solve(n,m));
	}
	return 0;
}
