                                            
  //File Name: poj2739.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月13日 星期日 23时38分10秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 10004;

bool is_prime[MAXN];
int prime[MAXN >> 1];
int sum[MAXN >> 1];
int init()
{
	int e = (int)sqrt(MAXN + 0.0);
	int i,tot = 0;
	for(i=0;i<MAXN;i++)
		is_prime[i] =true;
	is_prime[1] = false;
	prime[++tot] = 2;
	for(i = 4;i<MAXN;i+=2)
		is_prime[i] = false;
	for(i=3;i<=e;i+=2){
		if(is_prime[i]){
			prime[++tot] = i;
			for(int j=i*i,s=2*i;j<MAXN;j+=s){
				is_prime[j] = false;
			}
		}
	}
	for(;i<MAXN;i+=2){
		if(is_prime[i])
			prime[++tot] = i;
	}
	sum[0] = 0;
	for(i=1;i<=tot;i++){
		sum[i] = sum[i-1] + prime[i];
	}
	return tot;
}

void solve(int cur,int tot)
{
	int l=1,r=1;
	int ans = 0;
	while(l <= tot){
		while(sum[r] - sum[l-1] < cur && r + 1 <= tot)
			r++;
		if(sum[r] - sum[l - 1] == cur)
			ans++;
		l++;
		r = max(r,l);
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int tot = init();
	//printf("%d\n",tot);
	int n;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		solve(n,tot);
	}
	return 0;
}
