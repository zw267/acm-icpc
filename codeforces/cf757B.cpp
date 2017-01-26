                                            
  //File Name: cf757B.cpp
  //Created Time: 2017年01月15日 星期日 16时37分24秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 5;
int a[MAXN];
int main(){
	int n,ans = 1;
	scanf("%d",&n);
	for(int i=0,u;i<n;++i){
		scanf("%d",&u);
		++a[u];
	}
	for(int i=2;i<MAXN;++i){
		int now = 0;
		for(int j=i;j<MAXN;j+=i)
			now += a[j];
		ans = max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
