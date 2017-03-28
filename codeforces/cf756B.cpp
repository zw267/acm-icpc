                                            
  //File Name: cf756B.cpp
  //Created Time: 2017年03月27日 星期一 13时45分16秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
const int INF = 0X3f3f3f3f;
int t[MAXN];
int f[MAXN];
void solve(int n){
	f[0] = 0,f[1] = 20;
	int a[3] = {1,90,1440};
	int b[3] = {20,50,120};
	for(int i=2;i<=n;++i){
		f[i] = INF;
		for(int j=0;j<3;++j){
			int p = lower_bound(t,t + i,t[i] - a[j] + 1) - t;
			if(p == 0) 
				f[i] = min(f[i],b[j]);
			else
				f[i] = min(f[i],f[p - 1] + b[j]);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",t + i);
	solve(n);
	for(int i=1;i<=n;++i)
		printf("%d\n",f[i] - f[i - 1]);
	return 0;
}
