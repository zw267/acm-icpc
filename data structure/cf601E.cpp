                                            
  //File Name: cf601E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月31日 星期三 20时43分11秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int MOD = (int)1e9 + 7;
const int P = (int)1e7 + 19;
const int N = 30000 + 10;
vector<int> t[N << 2];
int st[N],ed[N],v[N],w[N],K;
void update(int L,int R,int add,int l,int r,int rt){
	if(L <= l && R >= r){
		t[rt].push_back(add);
		return ;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) update(L,R,add,lson);
	if(R > mid) update(L,R,add,rson);
}
void query(int l,int r,int rt,vector<int> f){
	for(int i=0,j;i<t[rt].size();i++){
		j = t[rt][i];
		int V = v[j],W = w[j];
		for(int i=K;i>=W;i--)
			f[i] = max(f[i],f[i-W]+V);
	}
	if(l == r){
		LL res = 0;
		for(int i=K;i>0;i--)
			res = (res * P + f[i]) % MOD;
		cout << res << endl;
	}	
	else{
		int mid = (l + r) >> 1;
		query(lson,f);
		query(rson,f);
	}
}
void solve(int n,int tot){
	for(int i=1;i<=n;i++){
		if(st[i] <= ed[i])
			update(st[i],ed[i],i,1,tot,1);
	}
	vector<int> f(K + 1);
	query(1,tot,1,f);
}
int main(){
	int n,tot = 0,q;
	scanf("%d %d",&n,&K);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&v[i],&w[i]);
		st[i] = 1,ed[i] = N;
	}
	scanf("%d",&q);
	for(int i=1,op,a;i<=q;i++){
		scanf("%d",&op);
		if(op == 3)
			tot++;
		else if(op == 1){
			n++;
			scanf("%d %d",&v[n],&w[n]);
			st[n] = tot + 1,ed[n] = N;
		}
		else{
			scanf("%d",&a);
			ed[a] = tot;
		}
	}
	for(int i=1;i<=n;i++) 
		if(ed[i] == N)
			ed[i] = tot;
	solve(n,tot);
	return 0;
}
