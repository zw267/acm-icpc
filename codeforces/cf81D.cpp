                                            
  //File Name: cf81D.cpp
  //Created Time: 2017年04月30日 星期日 15时30分39秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1005;
int a[41];
int ans[MAXN];
bool solve(const int n,const int m){
	int tot = 0;
	ans[0] = -1;
	while(tot < n){
		if(tot > 1 && tot < n - 1 && tot % 2 == 0 && a[ans[1]] > 0){
			ans[++tot] = ans[1];
			--a[ans[1]];
			continue ;
		}
		int pre = ans[tot],tmp = -1,nex = -1;
		if(tot == n - 1) nex = ans[1];
		for(int i=1;i<=m;++i){
			if(a[i] > 0 && i != pre && i != nex){
				if(tmp == -1 || a[tmp] < a[i])
					tmp = i;
			}
		}
		if(tmp == -1) return false;
		ans[++tot] = tmp;
		--a[tmp];
	}
	return true;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",a + i);
	bool can = solve(n,m);
	if(!can) puts("-1");
	else{
		for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
