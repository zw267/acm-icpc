                                            
  //File Name: cf314C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月20日 星期日 23时58分59秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define hash hashhash

using namespace std;

const int MAXN = 100000+5;
const int N = (int)1e6+5;
const int MOD = (int)1e9+7;

struct Node{
	int ls,rs;
	LL w;
	Node(){
		ls = rs = w = 0;
	}
};

Node node[MAXN * 20];
int root[MAXN];
int sz;
int a[MAXN];
LL f[MAXN];
int pre[N];
int num[MAXN];
int hash[MAXN];
int tot,top;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++){
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
	}
}

int hash_find(int x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

void update(int &i,int l,int r,int p,int add){
	node[++sz] = node[i];
	i = sz;
	(node[sz].w += add) %= MOD;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(node[sz].ls,l,mid,p,add);
	else
		update(node[sz].rs,mid+1,r,p,add);
}

LL query(int L,int R,int l,int r,int x){
	if(l == r)
		return (node[R].w - node[L].w + MOD ) % MOD;
	int mid = (l + r) >> 1;
	LL res = 0;
	if(x <= mid){
		res = query(node[L].ls,node[R].ls,l,mid,x);
	}
	else{
		LL cur = (node[node[R].ls].w - node[node[L].ls].w + MOD ) % MOD;
		res = (cur + query(node[L].rs,node[R].rs,mid+1,r,x)) % MOD;
	}
	return res;
}

void solve(int n){
	hash_init();
	memset(pre,-1,sizeof pre);
	sz = 0;
	root[0] = 0;
	for(int i=1;i<=n;i++){
		int cur = hash_find(a[i]);
		if(pre[a[i]] == -1){
			f[i] = (query(root[0],root[i-1],1,tot,cur - 1) + 1) * a[i] % MOD;
			pre[a[i]] = i;
			root[i] = root[i-1];
			update(root[i],1,tot,cur,f[i]);
		}
		else{
			int l = pre[a[i]];
			f[i] = (query(root[l-1],root[i-1],1,tot,cur)) * a[i] % MOD;
			pre[a[i]] = i;
			root[i] = root[i-1];
			update(root[i],1,tot,cur,f[i]);
		}
	}
	//for(int i=1;i<=n;i++){
	//	printf("%lld\n",f[i]);
	//}
	LL ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans + f[i]) % MOD;
	}
	printf("%d\n",(int)ans);
	return ;
}

int main(){
	int n;
	top = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[++top] = a[i];
	}
	solve(n);
	return 0;
}

