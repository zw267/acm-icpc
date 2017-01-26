                                            
  //File Name: cf223B.cpp
  //Created Time: 2017年01月17日 星期二 20时59分50秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 2;
char s[MAXN],t[MAXN];
int f[MAXN],g[MAXN];
int sum[MAXN][26];
bool solve(){
	int sl = strlen(s + 1);
	int tl = strlen(t + 1);
	f[0] = 0;
	for(int i=1;i<=sl;++i){
		if(s[i] == t[f[i-1] + 1])
			f[i] = f[i - 1] + 1;
		else 
			f[i] = f[i - 1];
	}
	g[sl+1] = tl + 1;
	for(int i=sl;i>=1;--i){
		if(s[i] == t[g[i + 1] - 1])
			g[i] = g[i + 1] - 1;
		else
			g[i] = g[i + 1];
	}
	for(int i=1;i<=tl;++i){
		int u = t[i] - 'a';
		for(int j=0;j<26;++j){
			if(j == u)
				sum[i][j] = sum[i-1][j] + 1;
			else
				sum[i][j] = sum[i-1][j];
		}
	}
	for(int i=1;i<=sl;++i){
		int l = max(g[i+1] - 1,1),r = min(f[i-1] + 1,tl);
		if(l > r) return false;
		if(sum[r][s[i]-'a'] - sum[l-1][s[i]-'a'] == 0)
			return false;
	}
	return true;
}
int main(){
	scanf("%s %s",s + 1,t + 1);
	if(solve())	puts("Yes");
	else puts("No");
	return 0;
}
