                                            
  //File Name: nod1218.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月17日 星期六 21时57分01秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 50000 + 10;
const int INF = 0x3f3f3f3f;
int a[MAXN],f[MAXN],st[MAXN],en[MAXN];
vector<int> pos[MAXN],ansa,ansb;
int cal1(int l,int r,int x){
	int m;
	while(r - l > 1){
		m = l + r >> 1;
		if(f[m] <= x) l = m;
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
	f[0] = 0;
	for(int i=1;i<=n;i++){
		en[i] = cal1(0,i-1,a[i]);
		len = max(len,en[i]);
	}
	for(int i=1;i<=n;i++) f[i] = 0;
	f[0] = INF;
	for(int i=n;i>0;i--){
		st[i] = cal2(0,n-i,a[i]);
	}
//	for(int i=1;i<=n;i++)
//		printf("i = %d st = %d en = %d\n",i,st[i],en[i]);
	for(int i=1;i<=n;i++) pos[i].clear();
	for(int i=1;i<=n;i++){
		if(st[i] + en[i] - 1 == len)
			pos[en[i]].push_back(i);
	}
	ansa.clear();
	ansb.clear();
	for(int i=1;i<=n;i++){
		if(pos[i].size() == 1)
			ansb.push_back(pos[i][0]);
		else{
			for(int j=0;j<pos[i].size();j++)
				ansa.push_back(pos[i][j]);
		}
	}
	sort(ansa.begin(),ansa.end());
	sort(ansb.begin(),ansb.end());
	printf("A:");
	for(int i=0;i<ansa.size();i++){
		printf("%d",ansa[i]);
		if(i < ansa.size()-1) printf(" ");
		else puts("");
	}
	printf("B:");
	for(int i=0;i<ansb.size();i++){
		printf("%d",ansb[i]);
		if(i < ansb.size()-1) printf(" ");
		else puts("");
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",a + i);
		solve(n);
	}
	return 0;
}
