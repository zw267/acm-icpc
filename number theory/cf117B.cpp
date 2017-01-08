                                            
  //File Name: cf117B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月17日 星期六 10时17分45秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int ans[10];
LL ext_gcd(LL a,LL b,LL &x,LL &y){
	if(a == 0 && b == 0) return -1;
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	LL d = ext_gcd(b,a % b,y,x);
	y -= a / b * x;
	return d;
}
int solve(LL a,LL b,LL p){
	LL ma = 1000000000,res = -1;
	if(ma % p == 0 || b >= p - 1) return -1;
	ma = ma % p;
//	printf("ma = %lld\n",ma);
//	LL x,y;
//	LL d = ext_gcd(ma,p,x,y);
//	x = (x % p + p) % p;
	for(LL i=1;i<=min(a,p);i++){
		LL tmp = i * ma % p;
		if(1 <= tmp && tmp <= p - b - 1){
			res = i;
			break;
		}
	}
	if(res == -1) return -1;
	int tot = 0;
	while(res){
		ans[tot++] = res % 10;
		res /= 10;
	}
	return 1;
}
int main(){
	LL a,b,p;
	cin >> a >> b >> p;
	int f = solve(a,b,p);
	if(f == -1) puts("2");
	else{
		printf("1 ");
		for(int i=8;i>=0;i--)
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
