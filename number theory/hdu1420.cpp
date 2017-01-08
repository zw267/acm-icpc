                                            
  //File Name: hdu1420.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月30日 星期三 21时55分42秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL qp(LL x,LL y,LL mod){
	LL res = 1;
	for(;y;y>>=1){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		LL a,b,c;
		cin >> a >> b >> c;
		cout << qp(a,b,c) << endl;
	}
	return 0;
}
