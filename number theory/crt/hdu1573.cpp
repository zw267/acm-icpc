                                            
  //File Name: hdu1573.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月30日 星期三 20时02分36秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 10;
int a[MAXN],m[MAXN];
int ext_gcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	int res = ext_gcd(b,a % b,y,x);
	y -= a / b * x;
	return res;
}
int crt(int n,int ma){
	int M  = m[0],p = a[0];
	for(int i=1;i<n;i++){
		int x,y,d;
		d = ext_gcd(M,m[i],x,y);
		if((a[i] - p) % d) return 0;
		x = (a[i] - p) / d * x % (m[i] / d);
		p += x * M;
		M = M / d * m[i];
		p %= M;
	}
	p = (p + M) % M;
	if(ma < p) return 0;
	int ans = (ma - p) / M + 1;
	if(!p) ans--;
	return ans;
}
int main(){
	int t,ma,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&ma,&n);
		for(int i=0;i<n;i++)
			scanf("%d",m + i);
		for(int i=0;i<n;i++)
			scanf("%d",a + i);
		printf("%d\n",crt(n,ma));
	}
	return 0;
}
