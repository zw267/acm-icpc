                                            
  //File Name: 407.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月07日 星期一 20时55分38秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
const int MAXN = 10000000 + 1;
int f[MAXN];
bool ok(int n,int fn){
	if(fn >= n) return false;
	for(int i=fn+1;i<n;i++){
		if(1LL * i * (i - 1) % n == 0)
			return false;
	}
	return true;
}
LL solve(){
	f[1] = 0;
	for(int i=2;i<MAXN;i++)
		f[i] = 1;
	vector<int> now,pre;
	pre.push_back(1);
	for(int i=2;i<MAXN;i++){
		for(int j=1;j*j<=i;j++){
			if(i % j == 0){
				now.push_back(j);
				if(i / j != j)
					now.push_back(i / j);
			}
		}
		sort(now.begin(),now.end());
		int len1 = now.size(),len2 = pre.size();
		for(int j=0;j<len1;j++){
			for(int k=0;k<len2;k++){
				int u = now[j],v = pre[k];
				if((LL)u * v >= MAXN) break;
				if(i < u * v)
					f[u * v] = max(f[u * v],i);
			}
		}
		pre = now;
		now.clear();
	}
//	for(int i=1;i<MAXN;i++){
//		if(!ok(i,f[i])){
//			printf("i = %d\n",i);
//			return -1;
//		}
//	}
	LL res = 0;
	for(int i=1;i<MAXN;i++)
		res += f[i];
	return res;
}
int main(){
	printf("%lld\n",solve());
	return 0;
}
