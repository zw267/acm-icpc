                                            
  //File Name: 1075.cpp
  //Created Time: 2017年04月02日 星期日 00时32分07秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 305;
double c[MAXN][MAXN];
double f[MAXN][MAXN];
int p[MAXN];
int loop[MAXN];
bool vis[MAXN];
void init(){
	for(int i=0;i<MAXN;++i){
		c[i][0] = 1;
		for(int j=1;j<=i;++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}
double solve(int n,int k){
	int tot = 0;
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int cur = i,num = 0;
			while(!vis[cur]){
				vis[cur] = true;
				++num;
				cur = p[cur];
			}
			loop[++tot] = num;
		}
	}	
	if(tot > k) 
		return 0.0000000;
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for(int i=1;i<=tot;++i){
		for(int j=i;j<=k;++j){
			for(int x=1;x<=min(j-i+1,loop[i]);++x){
				f[i][j] += f[i-1][j-x] * c[loop[i]][x];
			}
//			printf("i = %d j = %d f = %lld\n",i,j,f[i][j]);
		}
	}
	double ans = (double)f[tot][k] / c[n][k];
	return ans;
}
int main(){
	init();
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",p + i);
		printf("%.14f\n",solve(n,k));
	}
	return 0;
}
