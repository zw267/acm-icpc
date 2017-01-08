                                            
  //File Name: nod1667.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月04日 星期二 20时22分27秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MOD = (int)1e9 + 7;
const LL INF = 1000000000000;
int l[20],r[20],k1,k2;
LL A,inv[20],ma[20];
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
	if(y == 0 || y == x) return 1;
	LL res = 1;
	for(LL i=0;i<y;i++)
		res = res * (x - i) % MOD * inv[y-i] % MOD;
//	cout << x << " " << y << endl;
//	cout << res << endl;
	return res;
}
LL cal(int n){
	if(A < 0) return 0;
	LL res = 0,s,tmp;
	for(int i=0,num;i<(1<<n);i++){
		num = 0,s = 0;
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				num++;
				s += ma[j] + 1;
			}
		}
		tmp = C(A-s+n-1,n-1);
		if(num & 1) (res = res - tmp + MOD) %= MOD;
		else (res += tmp) %= MOD;
	}
//	if(res < 0) cout << "fff " << endl;
	return res;
}
void solve(){
	LL ansl = 0,ansg = 0,anseq = 0,sum = 1;
	A = 0;
	for(int i=0;i<k1;i++) A -= l[i];
	for(int i=k1;i<k1+k2;i++) A += r[i];
	anseq = cal(k1+k2);
	A--;
	ansl = cal(k1+k2+1);
	A = 0;
	for(int i=0;i<k1;i++) A += r[i];
	for(int i=k1;i<k1+k2;i++) A -= l[i];
	A--;
	ansg = cal(k1+k2+1);
	for(int i=0;i<k1+k2;i++){
		sum = sum * (r[i] - l[i] + 1) % MOD;
	}
	sum = qp(sum,MOD - 2);
	ansl = ansl * sum % MOD;
	ansg = ansg * sum % MOD;
	anseq = anseq * sum % MOD;
	printf("%lld %lld %lld\n",ansg,anseq,ansl);
}
int main(){
	for(int i=1;i<20;i++) inv[i] = qp(i,MOD - 2);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k1);
		for(int i=0;i<k1;i++)	
			scanf("%d %d",&l[i],&r[i]),ma[i] = r[i] - l[i];
		scanf("%d",&k2);
		for(int i=k1;i<k1+k2;i++)
			scanf("%d %d",&l[i],&r[i]),ma[i] = r[i] - l[i];
		ma[k1+k2] = INF;
		solve();
	}
	return 0;
}
