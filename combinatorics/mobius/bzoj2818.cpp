                                            
  //File Name: bzoj2818.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月18日 星期一 10时23分00秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 10000000 + 2;

bool check[MAXN];
int prime[MAXN];
int mu[MAXN];

int moebius(){
	memset(check,false,sizeof check);
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= MAXN)
				break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
	return tot;
}

void solve(int n,int tot){
	LL ans = 0;
	int d;
	for(int i=0;i<tot;i++){
		if(prime[i] > n)
			break;
		d = prime[i];
		for(int j=1;j <= n / d;j++){
			ans += (LL)mu[j] * (n / (d * j)) * (n / (d * j));
		}
		//cout << d << " " << ans << endl;
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	int tot = moebius();
	int n;
	while(~scanf("%d",&n)){
		solve(n,tot);
	}
	return 0;
}
