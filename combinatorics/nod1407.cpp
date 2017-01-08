                                            
  //File Name: nod1407.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月09日 星期日 22时04分55秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 1 << 20;
const int MOD = (int)1e9 + 7;
int f[MAXN];
LL p2[MAXN];
void init(){
	p2[0] = 1;
	for(int i=1;i<MAXN;i++)
		p2[i] = p2[i-1] * 2 % MOD;
}
void cal(int pre,int i){
	if(i < 0) return ;
	cal(pre,i-1);
	cal(pre+(1<<i),i-1);
	for(int j=0;j<(1<<i);j++)
		(f[pre+j] += f[pre+(1<<i)+j] )%=MOD;
}
LL solve(int n){
	cal(0,19);
//	for(int i=0;i<=10;i++)
//		cout << f[i] << endl;
	LL ans = 0;
	for(int i=0,s;i<(1<<20);i++){
		s = 0;
		for(int j=0;j<20;j++)
			if(i & (1<<j)) s++;
		LL tmp = (p2[f[i]] - 1 + MOD) % MOD;
		if(s & 1) ans = (ans - tmp + MOD) % MOD;
		else ans = (ans + tmp) % MOD;
	}
	return ans;
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i=0,a;i<n;i++){
		scanf("%d",&a);
		f[a]++;
	}
	cout << solve(n) << endl;
	return 0;
}
