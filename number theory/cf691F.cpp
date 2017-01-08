                                            
  //File Name: cf691F.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月19日 星期一 14时34分19秒
                                   
#include <bits/stdc++.h>
#define LL long long
const int MAXN = 1000000 + 1;
const int N = 3000000 + 1;
int num[N];
LL sum[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0,u;i<n;++i){
		scanf("%d",&u);
		num[u]++;
	}
	for(int i=1;i<N;++i){
		for(int j=1;j<N;++j){
			if(1LL * i * j >= N) break;
			sum[i * j] += 1LL * num[i] * num[j];
			if(i == j) sum[i * j] -= num[i];
		}
	}
	for(int i=1;i<N;++i)
		sum[i] += sum[i - 1];
	int m;
	scanf("%d",&m);
	for(int i=0,u;i<m;++i){
		scanf("%d",&u);
		printf("%lld\n",1LL * n * (n - 1) - sum[u - 1]);
	}
	return 0;
}
