                                            
  //File Name: nod1315.cpp
  //Created Time: 2017年01月01日 星期日 23时23分23秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[50][31];
int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=0,u;i<n;++i){
		scanf("%d",&u);
		if((u | x) != x) continue;
		for(int j=0;j<31;++j){
			if(u & (1 << j)) 
				a[i][j] = 1;
		}
	}
	int ans = n;
	for(int j=0;j<31;++j){
		if(x & (1 << j)){
			int now = 0;
			for(int i=0;i<n;++i){
				if(a[i][j])
					++now;
			}
			ans = min(ans,now);
		}
	}
	printf("%d\n",ans);
	return 0;
}
