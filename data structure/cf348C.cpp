                                            
  //File Name: cf348C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月13日 星期三 00时51分19秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <map>

#define LL long long
#define pb push_back

using namespace std;

const int MAXN = 100000 + 3;

LL a[MAXN];
LL all,sum;
vector<int> s[MAXN];
int s_com[MAXN][400];
int len[MAXN];
bool vis[MAXN];
int sz;
char ch[3];
int que[400];
int tot;

void init_s_com(int n,int m){
	for(int k=0,i;k<tot;k++){
		i = que[k];
		memset(vis,false,sizeof vis);
		for(int j=0;j<len[i];j++){
			vis[s[i][j]] = true;
		}
		int l = 0;
		for(int j=1;j<=n;j++){
			if(!vis[j])
				s_com[i][l++] = j;
		}
	}
	return ;
}

void update(int k,LL x,int n){
	if(len[k] <= sz){
		for(int i=0;i<len[k];i++){
			a[s[k][i]] += x;
		}
		sum += (LL)x * len[k];
	}
	else{
		int ma = n - len[k];
		for(int i=0;i<ma;i++){
			a[s_com[k][i]] -= x;
		}
		sum += (LL)x * len[k];
		all += x;
	}
}

LL query(int k,int n){
	LL res = 0LL;
	if(len[k] <= sz){
		for(int i=0;i<len[k];i++){
			res += a[s[k][i]];
		}
		res += len[k] * all;
	}
	else{
		int ma = n - len[k];
		for(int i=0;i<ma;i++){
			res += a[s_com[k][i]];
		}
		res += all * ma;
		res = sum - res;
	}
	return res;
}

void solve(int n,int m,int q){
	//sz = (int)sqrt(n + 0.0);
	init_s_com(n,m);
	sum = all = 0LL;
	for(int i=1;i<=n;i++)
		sum += a[i];
	for(int i=1,k,x;i<=q;i++){
		scanf("%s",ch);
		if(ch[0] == '+'){
			scanf("%d %d",&k,&x);
			update(k,x,n);
		}
		else{
			scanf("%d",&k);
			printf("%I64d\n",query(k,n));
		}
	}
	return ;
}

int main(){
	int n,m,q;
	while(~scanf("%d %d %d",&n,&m,&q)){
		tot = 0;
		sz = (int)sqrt(n + 0.0);
		for(int i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
		}
		for(int i=1,u;i<=m;i++){
			scanf("%d",&len[i]);
			if(len[i] > sz)
				que[tot++] = i;
			s[i].resize(len[i]);
			for(int j=0;j<len[i];j++){
				scanf("%d",&s[i][j]);
			}
		}
		solve(n,m,q);
	}
	return 0;
}
