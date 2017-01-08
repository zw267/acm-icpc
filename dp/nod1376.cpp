                                            
  //File Name: nod1376.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月17日 星期六 22时29分21秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
const int MAXN = 50000 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
int a[MAXN],f[MAXN],st[MAXN],en[MAXN];
vector<int> pos[MAXN];
LL rem[MAXN];
int cal1(int l,int r,int x){
	int m;
	while(r - l > 1){
		m = l + r >> 1;
		if(f[m] < x) l = m;
		else r = m;
	}
	if(f[r] < x){
		f[r+1] = min(f[r+1],x);
		return r + 1;
	}
	f[l+1] = min(f[l+1],x);
	return l + 1;
}
int cal2(int l,int r,int x){
	int m;
	while(r - l > 1){
		m = l + r >> 1;
		if(f[m] > x) l = m;
		else r = m;
	}
	if(f[r] > x){
		f[r+1] = max(f[r+1],x);
		return r + 1;
	}
	f[l+1] = max(f[l+1],x);
	return l + 1;
}
void solve(int n){
	int len = 0;
	for(int i=1;i<=n;i++) f[i] = INF;
	f[0] = -1;
	for(int i=1;i<=n;i++){
		en[i] = cal1(0,i-1,a[i]);
		len = max(len,en[i]);
	}
	for(int i=1;i<=n;i++) f[i] = -1;
	f[0] = INF;
	for(int i=n;i>0;i--){
		st[i] = cal2(0,n-i,a[i]);
	}
//	for(int i=1;i<=n;i++)
//		printf("i = %d en = %d st = %d\n",i,en[i],st[i]);
	for(int i=0;i<=len;i++) pos[i].clear();
	for(int i=1;i<=n;i++){
		if(st[i] + en[i] - 1 == len)
			pos[en[i]].push_back(i);
	}
//	cout << len << endl;
	pos[0].push_back(0);
	memset(rem,0,sizeof rem);
	a[0] = -1;
	rem[0] = 1;
	for(int i=1;i<=len;i++){
		for(int j=0;j<pos[i].size();j++){
			int u = pos[i][j];
			for(int k=0;k<pos[i-1].size();k++){
				int v = pos[i-1][k];
				if(v >= u) break;
				if(a[v] < a[u])
					rem[u] = (rem[u] + rem[v]) % MOD;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("i = %d rem = %d\n",i,rem[i]);
	LL ans = 0;
	for(int i=0;i<pos[len].size();i++) 
		ans = (ans + rem[pos[len][i]]) % MOD;
	printf("%lld\n",ans);
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",a + i);
		solve(n);
	}
	return 0;
}
