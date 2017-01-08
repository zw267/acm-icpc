                                            
  //File Name: hdu1695.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月17日 星期日 14时36分44秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 100000 + 4;
const int INF = 0x3f3f3f3f;

int mu[MAXN];
bool check[MAXN];
int prime[MAXN];

void moebius(){
	memset(check,false,sizeof check);
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<=MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] > MAXN)
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
	return ;
}

LL get_g(LL b,LL d,LL i){
	b /= i;
	d /= i;
	return b * d - (b - 1) * b / 2;
}

void solve(int b,int d,int k){
	LL ans = 0;
	for(int i=1;i<=b;i++){
		ans = ans + (LL)mu[i] * get_g(b,d,i);
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	moebius();
	int test,cas = 1;
	scanf("%d",&test);
	while(test--){
		printf("Case %d: ",cas++);
		int a,b,c,d,k;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		if(k == 0){
			puts("0");
			continue;
		}
		b = b / k;
		d = d / k;
		if(b > d)
			swap(b,d);
		solve(b,d,k);
	}
	return 0;
}
