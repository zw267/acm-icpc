                                            
  //File Name: nod1402.cpp
  //Created Time: 2017年01月02日 星期一 00时20分07秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000 + 1;
int s[MAXN];
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i)
			s[i] = i;
		for(int i=1,x,v;i<=m;++i){
			scanf("%d %d",&x,&v);
			--x;
			if(s[x] <= v) continue;
			for(int j=0;x-j>0;++j){
				s[x-j] = min(s[x-j],v+j);
			}
			for(int j=1;j+x<n;++j){
				s[j+x] = min(s[j+x],v+j);
			}
		}
		int ans = 0;
		for(int i=0;i<n;++i)
			ans = max(ans,s[i]);
		printf("%d\n",ans);
	}
	return 0;
}
