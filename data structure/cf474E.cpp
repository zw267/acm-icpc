                                            
  //File Name: cf474E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月20日 星期日 21时29分34秒
                                   

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long
#define hash hashhash
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 5;

int seg[MAXN * 12];
LL h[MAXN];
int f[MAXN];
int pre[MAXN];
int res[MAXN];
LL num[MAXN * 3];
LL hash[MAXN * 3];
int top,tot;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++){
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
	}
}

int hash_find(LL x){
	int l = 1,r = tot, mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

void build(){
	memset(seg,0,sizeof seg);
}

void pushup(int rt){
	int l = seg[rt<<1];
	int r = seg[rt<<1|1];
	if(f[l] >= f[r])
		seg[rt] = l;
	else
		seg[rt] = r;
}

void update(int p,int add,int l,int r,int rt){
	if(l == r){
		if(f[add] > f[seg[rt]])
			seg[rt] = add;
		return ;
	}
	int m = (l + r) >> 1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r)
		return seg[rt];
	int m = (l + r) >> 1;
	int res = 0, cur;
	if(L <= m){
		cur = query(L,R,lson);
		if(f[cur] > f[res])
			res = cur;
	}
	if(R > m){
		cur = query(L,R,rson);
		if(f[cur] > f[res])
			res = cur;
	}
	return res;
}

void solve(int n,LL d){
	hash_init();
	build();
	f[0] = 0;
	for(int i=1,cur;i<=n;i++){
		f[i] = 1;
		pre[i] = -1;
		cur = hash_find(h[i] + d);
		cur = query(cur,tot,1,tot,1);
		if(f[cur] + 1 > f[i]){
			f[i] = f[cur] + 1;
			pre[i] = cur;
		}
		if(h[i] - d > 0){
			cur = hash_find(h[i] - d);
			cur = query(1,cur,1,tot,1);
			if(f[cur] + 1 > f[i]){
				f[i] = f[cur] + 1;
				pre[i] = cur;
			}
		}
		update(hash_find(h[i]),i,1,tot,1);
	}
	int ans = 1;
	for(int i=2;i<=n;i++){
		if(f[i] > f[ans])
			ans = i;
	}
	tot = 0;
	for(int i=ans;i!=-1;i=pre[i]){
		res[tot++] = i;
	}
	printf("%d\n",tot);
	for(int i=tot-1;i>0;i--){
		printf("%d ",res[i]);
	}
	printf("%d\n",res[0]);

	return ;
}

int main(){
	int n;
	LL d;
	cin >> n >> d;
	top = 0;
	for(int i=1;i<=n;i++){
		cin >> h[i];
		num[++top] = h[i];
		num[++top] = h[i] + d;
		if(h[i] > d)
			num[++top] = h[i] - d;
	}
	solve(n,d);
	return 0;
}
