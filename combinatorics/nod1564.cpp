                                            
  //File Name: nod1564.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年10月10日 星期一 19时59分32秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
const LL INF = (1<<18);
LL a[MAXN],ans[MAXN];
int l[MAXN],r[MAXN];
void solve(int n){
	l[1] = 1;
	for(int i=2;i<=n;i++){
		l[i] = i;
		while(l[i] > 1 && a[l[i]-1] <= a[i])
			l[i] = l[l[i]-1];
	}
	r[n] = n;
	for(int i=n-1;i>0;i--){
		r[i] = i;
		while(r[i] < n && a[r[i]+1] < a[i])
			r[i] = r[r[i]+1];
	}
	memset(ans,0,sizeof ans);
	for(int i=1;i<=n;i++){
		LL mi1 = a[i];
/*
		for(int j=i;j>=l[i];j--){
			mi1 = min(mi1,a[j]);
			LL mi2 = mi1;
			for(int k=i;k<=r[i];k++){
				mi2 = min(mi2,a[k]);
				ans[k-j+1] = max(ans[k-j+1],a[i] * mi2);
			}
		}
*/
		int j = i,k = i;
		while(true){
			ans[k-j+1] = max(ans[k-j+1],mi1 * a[i]);
			if(j == l[i] && k == r[i]) break;
			else if(j == l[i] && k < r[i])
				k+=1,mi1 = min(mi1,a[k]);
			else if(j > l[i] && k == r[i])
				j-=1,mi1 = min(mi1,a[j]);
			else{
				if(a[j-1] >= a[k+1])
					j-=1,mi1 = min(mi1,a[j]);
				else
					k+=1,mi1 = min(mi1,a[k]);
			}
		}
	}
	for(int i=n-1;i>=1;i--)
		ans[i] = max(ans[i],ans[i+1]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a + i);
	solve(n);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
