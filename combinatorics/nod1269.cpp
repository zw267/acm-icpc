                                            
  //File Name: nod1269.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月10日 星期一 13时11分23秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
int inv[20];
LL a[20];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
LL C(LL x,LL y){
	if(x < y || y < 0) return 0;
	if(y == x || y == 0) return 1;
	LL ans = 1;
	for(int i=0;i<y;i++){
		ans = (x - i) % MOD * inv[y - i] % MOD * ans % MOD;
	}
//	printf("x = %lld y = %lld ans = %lld\n",x,y,ans);
	return ans;
}
LL solve(int n,LL s){
	for(int i=1;i<n;i++) 
		inv[i] = qp(i,MOD - 2);
	LL ans = 0;
	for(int i=0;i<(1<<n);i++){
		LL now = 0;
		int num = 0;
		for(int j=0;j<n;j++){
			if(i & (1 << j)){
				num++;
				now += a[j] + 1;
			}
		}
		
		LL tmp = C(s - now + n -1,n - 1);
		if(num & 1) ans = (ans - tmp + MOD) % MOD;
		else ans = (ans + tmp) % MOD;
	}
	return ans;
}
int main(){
	LL s;
	int n;
	scanf("%d %lld",&n,&s);
	for(int i=0;i<n;i++) scanf("%lld",a + i);
	cout << solve(n,s) << endl;
	return 0;
}
