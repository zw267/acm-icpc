                                            
  //File Name: 87.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 13时38分25秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#define LL long long
using namespace std;
const int MAXN = 50000000 + 1;
bool check[MAXN];
int prime[MAXN];
int is[MAXN];
vector<int> a[3];
int solve(int n){
	memset(check,false,sizeof(check));
	memset(is,false,sizeof(is));
	int tot = 0;
	int ma = sqrt(n + 0.5);
	for(int i=2;i<=ma;i++){
		if(!check[i])
			prime[tot++] = i;
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] > ma) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i=0;i<tot;i++){
		LL now = prime[i] * prime[i];
		if(now <= n) a[0].push_back(now);
		now *= prime[i];
		if(now <= n) a[1].push_back(now);
		now *= prime[i];
		if(now <= n) a[2].push_back(now);
	}
	for(int i=0;i<a[0].size();i++){
		for(int j=0;j<a[1].size();j++){
			for(int k=0;k<a[2].size();k++){
				int now = a[0][i] + a[1][j] + a[2][k];
				if(now <= n) is[now] = 1;
			}
		}
	}
	int res = 0;
	for(int i=2;i<=n;i++)
		if(is[i]) res++;
	return res;
}
int main(){
	cout << solve(50000000) << endl;
}
