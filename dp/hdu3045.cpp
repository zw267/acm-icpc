                                            
  //File Name: hdu3045.cpp
  //Created Time: 2017年05月02日 星期二 18时46分56秒
                                   
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 400000 + 5;
const LL INF = 1e17;
LL a[MAXN],sum[MAXN];
LL f[MAXN];
LL deqk[MAXN],deqb[MAXN];
bool g1(int i,int j,LL cur){
	return deqb[i] - deqb[j] <= cur * (deqk[i] - deqk[j]);
}
bool g2(int i,int j,int k){
	return (deqb[i] - deqb[j]) * (deqk[j] - deqk[k]) <=
		   (deqb[j] - deqb[k]) * (deqk[i] - deqk[j]);
}
LL solve(const int n,const int m){
	sort(a + 1,a + n + 1);
	for(int i=1;i<=n;++i)
		sum[i] = sum[i - 1] + a[i];
	f[0] = 0;
	int head(0),tail(0);
	for(int i=1;i<=n;++i){
		if(i - m >= 0 && f[i - m] < INF){
			int k = i - m;
			deqk[tail] = a[k + 1];
			deqb[tail++] = f[k] - sum[k] + k * a[k + 1];
			while(tail - 3 >= head && g2(tail - 1,tail - 2,tail - 3)){
				deqk[tail - 2] = deqk[tail - 1];
				deqb[tail - 2] = deqb[tail - 1];
				--tail;
			}
		}
		if(head == tail) 
			f[i] = INF;
		else{
			while(head + 1 < tail && g1(head + 1,head,i))
				++head;
			f[i] = sum[i] - i * deqk[head] + deqb[head];
		}
	}
//	for(int i=0;i<=n;++i)
//		printf("i = %d f = %lld\n",i,f[i]);
	return f[n];
}
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;++i)
			scanf("%lld",a + i);
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
