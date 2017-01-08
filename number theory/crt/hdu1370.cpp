                                            
  //File Name: hdu1370.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月30日 星期三 21时04分00秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 3;
int m[3] = {23,28,33};
int a[3];
int ext_gcd(int a,int b,int &x,int &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	int res = ext_gcd(b,a % b,y,x);
	y -= a / b * x;
	return res;
}
int crt(int n){
	int M = 1,res = 0;
	for(int i=0;i<n;i++) M *= m[i];
	for(int i=0;i<n;i++){
		int w = M / m[i];
		int d,x,y;
		d = ext_gcd(w,m[i],x,y);
		res = (res + a[i] * w * x) % M;
	}
	return (res + M) % M;
}
int main(){
	int t,cas = 1,d;
	scanf("%d",&t);
	while(~scanf("%d %d %d %d",&a[0],&a[1],&a[2],&d)){
		if(a[0] == -1 && a[1] == -1 && a[2] == -1 && d == -1) 
			break;
		int ans = crt(3);
		if(d >= ans) ans = 21252 - d + ans;
		else ans = ans - d;
		printf("Case %d: the next triple peak occurs in %d days.\n",cas++,ans);
	}
	return 0;
}
