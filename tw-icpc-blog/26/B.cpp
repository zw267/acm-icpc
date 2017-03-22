                                            
  //File Name: B.cpp
  //Created Time: 2017年03月22日 星期三 12时14分08秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 5;
int a[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int l,r;
		scanf("%d %d",&l,&r);
		++a[l];
		--a[r];
	}
	for(int i=1;i<MAXN;++i)
		a[i] += a[i - 1];
	LL res = 0;
	for(int i=1;i<MAXN;++i)
		res += 1LL * a[i] * a[i];
	printf("%lld\n",res);
	return 0;
}
