                                            
  //File Name: cf364D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月19日 星期六 01时08分46秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 10;
LL a[MAXN],d[100000];
int s[100000];
LL gcd(LL x,LL y){
	return (!y) ? x :gcd(y,x % y);
}
int cal(LL x,int n){
	return lower_bound(d,d+n,x) - d;
}
LL solve(int n){
	LL ans = 1;
	random_shuffle(a,a+n);
	for(int t=0;t < n && clock() <= 3000;t++){
		LL p = a[t];
		int tot = 0;
		for(LL j=1;j*j<=p;j++){
			if(p % j == 0){
				d[tot++] = j;
				if(j * j != p)
					d[tot++] = p / j;
			}
		}
		sort(d,d+tot);
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++){
			s[lower_bound(d,d+tot,__gcd(a[i],p)) - d]++;
		}
		for(int i=0;i<tot;i++){
			LL g = d[i];
			for(int j=i+1;j<tot;j++){
				if(d[j] % g == 0)
					s[i] += s[j]; 
			}			
			if(s[i] * 2 >= n && g > ans)
				ans = g;
		}
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",a + i);
	printf("%lld\n",solve(n));
	return 0;
}
