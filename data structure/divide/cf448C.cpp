                                            
  //File Name: cf448C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月17日 星期四 10时27分13秒
                                   
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int a[MAXN];
int dfs(int L,int R,int now){
	if(L > R) return 0;
	if(L == R) return a[L] <= now ? 0 : 1;
	int mi_p = L;
	for(int i=L+1;i<=R;i++){
		if(a[i] < a[mi_p]) 
			mi_p = i;
	}
	int u = a[mi_p] - now;
	return min(R-L+1,dfs(L,mi_p-1,now+u)+dfs(mi_p+1,R,now+u)+u);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a + i);
	printf("%d\n",dfs(1,n,0));
	return 0;
}

