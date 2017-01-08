                                            
  //File Name: light1370.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 10时43分13秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2000000;
bool check[MAXN];
int prime[MAXN],phi[MAXN];
int ans[MAXN];
void update(int p,int x){
	if(0 <= p && p < MAXN){
		if(ans[p] == -1 || ans[p] > x)
			ans[p] = x;
	}
}
void init(){
	memset(check,false,sizeof(check));
	memset(ans,-1,sizeof ans);
	int tot = 0;
	phi[1] = 1;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			phi[i] = i - 1;
			update(phi[i],i);
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				update(phi[i] * prime[j],i * prime[j]);
				break;
			}
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	for(int i=MAXN-2;i>=0;i--){
		if(ans[i] == -1)
			ans[i] = ans[i + 1];
		else if(ans[i+1] != -1)
			ans[i] = min(ans[i + 1],ans[i]);
	}
}
int main(){
	init();
	int t,cas = 1;
	scanf("%d",&t);
	while(t--){
		int n,a;
		LL res = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			res += ans[a];
		}
		printf("Case %d: %lld Xukha\n",cas++,res);
	}
	return 0;
}

