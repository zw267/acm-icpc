                                            
  //File Name: cf628E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月05日 星期一 19时09分08秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
using namespace std;
const int MAXN = 3010;
int n,m;
int a[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN],f[MAXN][MAXN];
int bit[MAXN << 1][MAXN];
char str[MAXN];
vector<pii > en[MAXN];
void update(int k,int x,int add){
	for(int i=x;i<=n;i+=i&-i){
		bit[k][i] += add;
	}
}
int query(int k,int x){
	int res = 0;
	for(int i=x;i;i-=i&-i){
		res += bit[k][i];
	}
	return res;
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]) 
				l[i][j] = l[i][j-1] + 1;
		}
	}	
	for(int i=n;i;i--){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				f[i][j] = 1;
				if(i+1<=n && j-1>0)
					f[i][j] = f[i+1][j-1] + 1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j;j--){
			if(a[i][j])
				r[i][j] = r[i][j+1] + 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				en[j+r[i][j]-1].push_back(mp(i,j));
			}
		}
	}
}
LL solve(){
	init();
	LL ans = 0;
	for(int j=m;j;--j){
		for(int i=0;i<en[j].size();i++){
			int &x = en[j][i].fir,&y = en[j][i].sec;
			update(x+y,x,1);
		}
		for(int i=1;i<=n;i++){
			if(a[i][j]){
				int len = min(l[i][j],f[i][j]);
				ans += query(i+j,i+len-1) - query(i+j,i-1);
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++){
			if(str[j] == 'z')
				a[i][j] = 1;
		}
	}
	cout << solve() << endl;
	return 0;
}
