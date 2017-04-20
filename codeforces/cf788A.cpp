                                            
  //File Name: cf788A.cpp
  //Created Time: 2017年04月21日 星期五 01时19分38秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
const LL INF = 1LL << 60;
LL a[MAXN],b[MAXN];
LL solve(int n){
	LL odd = 0,even = 0;
	for(int i=1;i<n;++i)
		b[i] = abs(a[i] - a[i + 1]);
	LL cur = -INF;
	for(int i=n-1;i;--i){
		if(i & 1){
			odd = max(b[i],b[i] + odd);
			even = max(-b[i],even - b[i]);
		}
		else{
			odd = max(-b[i],-b[i] + odd);
			even = max(b[i],b[i] + even);
		}
		cur = max(cur,max(odd,even));
	}
	return cur;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",a + i);
	}
	printf("%lld\n",solve(n));
	return 0;
}
