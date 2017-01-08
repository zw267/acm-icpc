                                            
  //File Name: cf421D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月07日 星期三 22时28分25秒
                                  
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int MAXN = 300000 + 10;
int s[MAXN],s2[MAXN];
pii a[MAXN];
map<pii,int> rem;
int cal(int l,int r,int x){
	if(s[l] >= x) return r - l + 1;
	if(s[r] < x) return 0;
	int mid,init_r = r;
	while(r - l > 1){
		mid = l + r >> 1;
		if(s[mid] < x) l = mid;
		else r = mid;
	}
	return init_r - r + 1;
}
LL solve(int n,int p){
	LL ans = 0;
	for(int i=1;i<=n;i++) s2[i] = s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<n;i++){
		ans += cal(i+1,n,p-s[i]);
//		printf("%d\n",cal(i+1,n,p-s[i]));
	}
//	cout << ans << endl;
	for(int i=1;i<=n;i++){
		int u = s2[a[i].fir] + s2[a[i].sec];
		if(u >= p && u - rem[a[i]] < p){
			ans--;
			rem[a[i]] = 0;
		}
	}
	return ans;
}
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(x > y) swap(x,y);
		a[i] = mp(x,y);
		rem[a[i]]++;
		s[x]++,s[y]++;
	}
	cout << solve(n,p) << endl;
	return 0;
}

