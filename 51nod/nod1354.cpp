                                            
  //File Name: nod1354.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月16日 星期四 10时33分57秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 1000 + 3;
const int MOD = (int)1e9 + 7;

map<int,int> mp;
map<int,int>::iterator it;
vector<int> dive;
LL a[MAXN];
LL f[MAXN][MAXN];

void init_dive(int K){
	mp.clear();
	dive.clear();
	int ma = (int)sqrt(K + 0.5);
	for(int i=1;i<=ma;i++){
		if(K % i == 0){
			dive.push_back(i);
			int j = K / i;
			if(j != i){
				dive.push_back(j);
			}
		}
	}
	sort(dive.begin(),dive.end());
	for(int i=0;i<dive.size();i++){
		mp[dive[i]] = i;
	}
}

LL solve(int n,int K){
	init_dive(K);
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		int ma = dive.size();
		for(int j=0;j<ma;j++){
			f[i][j] = f[i-1][j];
			if(dive[j] % a[i] == 0){
				int now = dive[j] / a[i];
				if(mp.count(now)){
					(f[i][j] += f[i-1][mp[now]]) %= MOD;
				}
			}
			//printf("i = %d j = %d f = %lld\n",i,dive[j],f[i][j]);
		}
	}
	return f[n][mp[K]];
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		LL K;
		scanf("%d %lld",&n,&K);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		printf("%d\n",(int)solve(n,K));
	}
	return 0;
}
