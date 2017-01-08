                                            
  //File Name: cf547C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月17日 星期六 13时32分09秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
const int N = 500000 + 1;
int a[MAXN],num[N],mu[N],prime[MAXN];
bool check[N],is[MAXN];
int dive[MAXN],tot;
void init(){
	memset(check,false,sizeof check);
	mu[1] = 1;
	tot = 0;
	for(int i=2;i<N;i++){
		if(!check[i]){
			mu[i] = -1;
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
}
void cal_dive(int x){
	tot = 0;
	for(int i=1;i*i<=x;i++){
		if(x % i == 0){
			dive[tot++] = i;
			if(x / i != i){
				dive[tot++] = x / i;
			}
		}
	}
}
void solve(int n,int q){
	memset(is,false,sizeof is);
	memset(num,0,sizeof num);
	LL ans = 0;
	for(int i=0,x;i<q;i++){
		scanf("%d",&x);
		cal_dive(a[x]);
		if(is[x]){
			for(int j=0;j<tot;j++)
				num[dive[j]]--;
			for(int j=0;j<tot;j++)
				ans -= 1LL * mu[dive[j]] * num[dive[j]];
			is[x] = false;
		}
		else{
			for(int j=0;j<tot;j++){
				ans += 1LL * mu[dive[j]] * num[dive[j]];
//				printf("%d\n",mu[dive[j]] * num[dive[j]]);
			}
			for(int j=0;j<tot;j++)
				num[dive[j]]++;
			is[x] = true;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	init();
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",a + i);
	solve(n,q);
	return 0;
}
