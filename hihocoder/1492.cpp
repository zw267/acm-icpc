                                            
  //File Name: 1492.cpp
  //Created Time: 2017年04月01日 星期六 15时57分36秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN  =1005;
const int P = (int)1e9 + 7;
LL f[MAXN][MAXN];
int g[MAXN][MAXN];
char str[MAXN];
int need[MAXN];
char a[MAXN];
void add(LL &x,LL y){
	x += y;
	if(x >= P)
		x -= P;
}
LL cal(int n,int s){
	if(!n) return 1;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[0][s] = 1;
	g[0][s] = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<=s;++j){
			if(!f[i][s]) continue;
			if(a[i + 1] == ')'){
				if(g[i][j]){
					add(f[i+1][j],f[i][j]);
					g[i+1][j] = g[i][j] - 1;
				}
			}
			else{
				add(f[i+1][j],f[i][j]);
				g[i+1][j] = g[i][j] + 1;
				for(int k=1;k<=min(g[i+1][j],j);++k){
					add(f[i+1][j-k],f[i][j]);
					g[i+1][j-k] = g[i+1][j] - k;
				}
			}
		}
	}
	return f[n][0];
}
void solve(){
	int n = strlen(str + 1),cur = 0,s1 = 0,s2 = 0;
	for(int i=1;i<=n;++i){
		if(str[i] == '(') 
			++cur;
		else
			--cur;
		if(cur < 0){
			need[i] = 1;
			++s2;
			cur = 0;
		}
	}
	cur = 0;
	for(int i=n;i;--i){
		if(str[i] == ')')
			++cur;
		else
			--cur;
		if(cur < 0){
			need[i] = 2;
			++s1;
			cur = 0;
		}
	}
	int p = 1,len = 0;
	while(p <= n && need[p] != 2)
		++p;
	for(int i=p;i<=n;++i)
		a[++len] = str[i];
	LL ans1 = cal(len,s1);
	p = n,len = 0;
	while(p && need[p] != 1)
		--p;
	for(int i=p;i;--i){
		a[++len] = (str[i] == '(') ? ')' : '(';
	}
	LL ans2 = cal(len,s2);
//	printf("ans1 = %lld ans2 = %lld\n",ans1,ans2);
	ans1 = ans1 * ans2 % P;
	if(s1 + s2 == 0) 
		ans1 = 1;
	printf("%d %lld\n",s1 + s2,ans1);
}
int main(){
	scanf("%s",str + 1);
	solve();
	return 0;
}
