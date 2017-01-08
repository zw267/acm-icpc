                                            
  //File Name: cf645E.cpp
  //Created Time: 2017年01月05日 星期四 13时53分24秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
const int MAXN = 2000000 + 2;
const int P = (int)1e9 + 7;
LL f[MAXN],g[MAXN];
char str[MAXN];
int pre[26];
set<pii> rem;
LL solve(int n,int k){
	int m = strlen(str + 1);
	memset(pre,0,sizeof(pre));
	f[0] = g[0] = 1;
	for(int i=1;i<=m;++i){
		int v = str[i] - 'a';
		if(pre[v] == 0)
			f[i] = g[i - 1];
		else
			f[i] = (g[i - 1] - g[pre[v] - 1] + P) % P;
		g[i] = (g[i - 1] + f[i]) % P;
		pre[v] = i;
//		printf("i = %d f = %lld g = %lld\n",i,f[i],g[i]);
	}
	rem.clear();
	for(int i=0;i<k;++i)
		rem.insert(pii(pre[i],i));
	for(int i=m+1;i<=m+n;++i){
//		puts("ffff");
		pii now = *rem.begin();
		int pos = now.fir,v = now.sec;
		if(pos == 0)
			f[i] = g[i - 1];
		else
			f[i] = (g[i - 1] - g[pos - 1] + P) % P;
		g[i] = (g[i - 1] + f[i]) % P;
		pre[v] = i;
		rem.erase(rem.begin());
		rem.insert(pii(i,v));
	}
//	for(int i=0;i<=m+n;++i)
//		printf("i = %d f = %lld\n",i,f[i]);
	return g[m + n];
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",str + 1);
	printf("%lld\n",solve(n,k));
	return 0;
}
