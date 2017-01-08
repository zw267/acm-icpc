                                            
  //File Name: cf687B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月30日 星期三 19时19分24秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 3;
LL c[MAXN];
LL gcd(LL x,LL y){
	if(!y) return x;
	return gcd(y,x % y);
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lld",c + i);
	LL C = 1;
	LL ans = k;
	for(int i=0;i<n;i++){
		LL d = gcd(C,c[i]);
		C = gcd(k,C / d * c[i]);
	}
	if(C == k) puts("Yes");
	else puts("No");
	return 0;
}
