                                            
  //File Name: cf449C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月17日 星期六 17时21分32秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
const int MAXN = 100000 + 10;
int prime[MAXN],num[MAXN],tot;
bool check[MAXN],vis[MAXN];
pii ans[MAXN];
vector<int> a[MAXN];
void init(int n){
	tot = 0;
	memset(check,false,sizeof(check));
	for(int i=2;i<=n;i++){
		if(!check[i])
			prime[tot++] = i;
		for(int j=0;j<tot;j++){
			if((LL)i * prime[j] > n) break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	sort(prime,prime+tot);
}
bool cmp(int x,int y){
	if(num[x] == num[y]) return x < y;
	return num[x] < num[y];
}
int solve(int n){
	init(n);
	int len = 0;
	for(int i=0;i<tot;i++){
		int p = prime[i];
		for(int j=p;j<=n;j+=p){
			a[i].push_back(j);
			num[j]++;
		}
	}
	for(int i=tot-1;i>=0;--i){
		sort(a[i].begin(),a[i].end(),cmp);
		int pre = -1;
		for(int j=0;j<a[i].size();j++){
			int u = a[i][j];
			if(vis[u]) continue;
			if(pre == -1)
				pre = u;
			else{
				vis[pre] = vis[u] = true;
				ans[len++] = pii(pre,u);
				pre = -1;
			}
		}
	}
	return len;
}
int main(){
	int n;
	scanf("%d",&n);
	int len = solve(n);
	printf("%d\n",len);
	for(int i=0;i<len;i++)
		printf("%d %d\n",ans[i].fir,ans[i].sec);
	return 0;
}
