                                            
  //File Name: nod1362.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月09日 星期日 19时14分21秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
vector<int> dive;
int s[50];
LL mod;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
LL ext_gcd(LL a,LL b,LL &x,LL &y){
	if(a == 0 && b == 0) return -1;
	if(b == 0){x = 1;y = 0;return a;}
	LL d = ext_gcd(b,a%b,y,x);
	y -= a / b * x;
	return d;
}
LL inv(LL a,LL n){
	LL x,y;
	LL d = ext_gcd(a,n,x,y);
	if(d == 1) return (x % n + n) % n;
	return -2;
}
void cal_dive(LL p){
	dive.clear();
	for(int i=2;i*i<=p;i++){
		if(p % i == 0){
			dive.push_back(i);
			while(p % i == 0) p /= i;
		}
	}
	if(p > 1) dive.push_back(p);
	sort(dive.begin(),dive.end());
}
LL fact(LL x,int f){
	for(int i=0;i<dive.size();i++){
		while(x % dive[i] == 0){
			s[i]+=f;
			x /= dive[i];
		}
	}
	if(f == -1) return inv(x,mod);
	return x;
}
LL cal(LL l,LL r,LL a,LL b,LL c){
	memset(s,0,sizeof s);
	LL ans = fact(a,-1);
	for(int i=2;i<=b;i++)
		ans = ans * fact(i,-1) % mod;
	for(int i=2;i<=c;i++)
		ans = ans * fact(i,-1) % mod;
	for(LL i=l;i<=r;i++)
		ans = ans * fact(i,1) % mod;
	for(int i=0;i<dive.size();i++){
		ans = ans * qp(dive[i],s[i]) % mod;
	}
	return ans;
}
LL solve(LL n,LL m){
	LL ans = 0;
	LL ma = min(n,m);
	cal_dive(mod);
	for(int c=0;c<=ma;c++){
		ans = (ans + cal(m-c+1,m-c+1+n,n+1,c,n-c)) % mod;
	}
	return ans;
}
int main(){
	LL n,m;
	cin >> n >> m >> mod;
	cout << solve(n,m) << endl;
	return 0;
}
