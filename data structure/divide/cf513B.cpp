                                            
  //File Name: cf513B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月17日 星期四 11时30分58秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 51;
int p[MAXN];
int n;
LL K;
void dfs(int i,int l,int r,LL L,LL R){
	if(l == r){
		p[l] = i;
		return ;
	}
	LL mid = L + (R - L + 1) / 2 - 1;
	if(K <= mid){
		p[l] = i;
		dfs(i+1,l+1,r,L,mid);
	}
	else{
		p[r] = i;
		dfs(i+1,l,r-1,mid+1,R);
	}
}
int main(){
	scanf("%d %lld",&n,&K);
	dfs(1,1,n,1,1LL<<(n-1));
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
	return 0;
}
