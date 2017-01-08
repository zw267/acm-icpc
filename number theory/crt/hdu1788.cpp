                                            
  //File Name: hdu1788.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月30日 星期三 21时59分46秒
                                   
#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int MAXN = 10;
int a[MAXN],m[MAXN];
LL ext_gcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	LL res = ext_gcd(b,a % b,y, x);
	y -= a / b * x;
	return res;
}
LL crt(int n){
	LL M = m[0],res = a[0];
	for(int i=1;i<n;i++){
		LL x,y,d;
		d = ext_gcd(M,m[i],x,y);
		if((a[i] - res) % d) return -1;
		x = (a[i] - res) / d * x % (m[i] / d);
		res += x * M;
		M = M / d * m[i];
		res %= M;
	}
	res = (res + M) % M;
	return res == 0 ? M : res;
}
int main(){
	int n,d;
	while(~scanf("%d %d",&n,&d)){
		if(!n && !d) break;
		for(int i=0;i<n;i++)
			scanf("%d",m + i);
		for(int i=0;i<n;i++)
			a[i] = m[i] - d;
		printf("%lld\n",crt(n));
	}
	return 0;
}
