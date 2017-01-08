                                            
  //File Name: light1341.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 12时18分59秒

#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 5;
int prime[MAXN],tot;
bool check[MAXN];
void init(){
	tot = 0;
	memset(check,false,sizeof(check));
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
LL solve(LL a,LL b){
	LL res = 1,init_a = a;
	for(int i=0;i<tot && (LL)prime[i] * prime[i] <= a;i++){
		if(a % prime[i] == 0){
			int tmp = 0;
			while(a % prime[i] == 0){
				tmp++;
				a /= prime[i];
			}
			res *= (tmp + 1);
		}
	}
	if(a > 1) res *= 2;
	res >>= 1;
	for(int i=1;i<b;i++)
		if(init_a % i == 0)
			res--;
	return res;
}
int main(){
	init();
	int t,cas = 1;
	scanf("%d",&t);
	while(t--){
		LL a,b,ans;
		scanf("%lld %lld",&a,&b);
		if(b * b >= a)
			ans = 0;
		else
			ans = solve(a,b);
		printf("Case %d: %lld\n",cas++,ans);
	}
	return 0;
}


