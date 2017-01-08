                                            
  //File Name: nod1439.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月19日 星期六 14时41分18秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 500000 + 2;
int fir[MAXN],prime[MAXN],mu[MAXN];
int a[MAXN],d[MAXN],tmp[MAXN],sum[MAXN],tot;
bool in[MAXN];
void init(){
	int tot = 0;
	mu[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!fir[i]){
			fir[i] = i;
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			fir[i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}
void dfs(int now,int p,int &len){
	if(p >= len){
		d[tot++] = now;
		return ;
	}
	dfs(now,p + 1,len);
	dfs(now * tmp[p],p+1,len);
}
void cal_d(int x){
	int len = 0;
	while(x > 1){
		tmp[len++] = fir[x];
		int now = fir[x];
		while(fir[x] == now) x /= fir[x];
	}
	tot = 0;
	dfs(1,0,len);
}
int cal(int x,int f){
	cal_d(x);
	int res = 0;
	if(f == -1){
		for(int i=0;i<tot;i++)
			sum[d[i]] += f;
	}
	for(int i=0;i<tot;i++)
		res += f * mu[d[i]] * sum[d[i]];
	if(f == 1){
	for(int i=0;i<tot;i++)
		sum[d[i]] += f;
	}
	return res;
}
void solve(int n,int q){
	int p;
	LL now = 0;
	while(q--){
		scanf("%d",&p);
		if(!in[p])
			now += cal(a[p],1);
		else 
			now += cal(a[p],-1);
		in[p] = !in[p];
		printf("%lld\n",now);	
	}
}
int main(){
	init();
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a + i);
	solve(n,q);
	return 0;
}
