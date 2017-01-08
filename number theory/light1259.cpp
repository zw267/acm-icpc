                                            
  //File Name: light1259.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月20日 星期日 13时37分52秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10000000 + 5;
bool check[MAXN],is[MAXN];
int prime[MAXN / 10],tot;
void init(){
	tot = 0;
	memset(check,false,sizeof(check));
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			is[i] = true;
		}
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
		   	if(i % prime[j] == 0) break;	
		}
	}
}
int solve(int n){
	int res = 0;
	for(int i=0;i<tot;i++){
		int u = n - prime[i];
		if(u < prime[i]) break;
		if(is[u]) res++;
	}
	return res;
}
int main(){
	init();
	int t,n,cas = 1;
	cin >> t;
	while(t--){
		cin >> n;
		printf("Case %d: %d\n",cas++,solve(n));
	}
	return 0;
}
