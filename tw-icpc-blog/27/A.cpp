                                            
  //File Name: A.cpp
  //Created Time: 2017年03月21日 星期二 13时48分51秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
int a[MAXN];
int l,n;
int solve(){
	if(n <= 2) return -1;
	l = 0;
	sort(a + 1,a + n + 1);
	bool flag = true;
	int mi = 2000000001,p = -1;
	for(int i=2;i<=n;++i){
		if(a[i] - a[i - 1] != 0)
			flag = false;
		if(a[i] - a[i - 1] < mi){
			mi = a[i] - a[i - 1];
			p = i - 1;
		}
	}
	if(flag) return -1;
	for(int i=2;i<=n;++i){
		if(i != p && i != p + 1 && a[i] > a[1]){
			swap(a[0],a[i]);
			return i;
		}
	}
	a[++n] = a[1];
	l = 2;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a + i);
	int p = solve();
	if(p == -1) puts("-1");
	else{
		for(int i=l;i<p;++i)
			printf("%d ",a[i]);
		for(int i=p+1;i<=n;++i)
			printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
