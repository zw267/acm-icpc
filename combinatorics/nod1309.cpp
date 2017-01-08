                                            
  //File Name: nod1309.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月05日 星期三 13时22分11秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#define LL long long
#define fir first
#define sec second
using namespace std;
const int MAXN = 50010;
const int MOD = (int)1e9 + 7;
int a[MAXN];
map<int,LL> pre_s,ans;
map<int,int> pre_num;
LL P,jie[MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}
int bs(int l,int r,int x){
	if(a[l] > x) return -1;
	if(a[r] <= x) return a[r];
	while(r - l > 1){
		int mid = l + r >> 1;
		if(a[mid] <= x) l = mid;
		else r = mid;
	}
	return a[l];
}
void solve(int n,int q){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++) jie[i] = jie[i-1] * i % MOD;
	sort(a,a+n);
	P = jie[n];
	for(int i=0;i<n;i++){
		pre_s[a[i]] += a[i];
		pre_num[a[i]]++;
	}
	for(map<int,int>::iterator it=pre_num.begin();it!=pre_num.end();it++)
		P = P * qp(jie[it->sec],MOD - 2) % MOD;
//	cout << P << endl;
	for(map<int,int>::iterator pre=pre_num.begin(),it;pre!=pre_num.end();pre++){
		it = ++pre;
		--pre;
		if(it==pre_num.end()) break;
		pre_num[it->fir] += pre_num[pre->fir];
//		cout << it->fir << " " << pre_num[it->fir] << endl;
	}
	for(map<int,LL>::iterator pre=pre_s.begin(),it;pre!=pre_s.end();pre++){
		it = ++pre;
		--pre;
		if(it == pre_s.end()) break;
		(pre_s[it->fir] += pre_s[pre->fir]) %= MOD;
//		cout << it->fir << " " << pre_s[it->fir] << endl;
	}
	for(int i=0;i<n;i++){
		ans[a[i]] = pre_s[a[i]] * P % MOD * qp(n-pre_num[a[i]]+1,MOD - 2) % MOD;
//		cout << a[i] << " " << pre_s[a[i]] << " " << n - pre_num[a[i]] + 1 <<endl;
	}
	for(int i=0,x;i<q;i++){
		scanf("%d",&x);
		x = bs(0,n-1,x);
//		cout << x << endl;
		if(x == -1) puts("0");
		else printf("%lld\n",ans[x]);
	}	
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",a + i);
	solve(n,q);
	return 0;
}
