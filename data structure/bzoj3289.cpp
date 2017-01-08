                                            
  //File Name: bzoj3289.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月08日 星期五 22时51分57秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long
#define ql(i) que[(i)].ql
#define qr(i) que[(i)].qr
#define id(i) que[(i)].id
#define hash hashhash

using namespace std;

const int MAXN = 50010;

struct Query{
	int ql,qr,id;
};
Query que[MAXN];
int a[MAXN];
int bit[MAXN];
int num[MAXN];
int hash[MAXN];
LL ans[MAXN];
int bel[MAXN];
int cur_l,cur_r;
LL cur_ans;
int tot,top;

inline int lb(int x){
	return x & (-x);
}

void update(int x,int add){
	while(x <= tot){
		bit[x] += add;
		x += lb(x);
	}
}

int query(int x){
	int res = 0;
	while(x > 0){
		res += bit[x];
		x -= lb(x);
	}
	return res;
}

bool cmp(Query x ,Query y){
	if(bel[x.ql] == bel[y.ql])
		return x.qr < y.qr;
	return bel[x.ql] < bel[y.qr];
}

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

void update_r(int &u,int v){
	while(u < v){
		u++;
		cur_ans += (LL)query(tot) - (LL)query(a[u]);
		update(a[u],1);
	}
	while(u > v){
		cur_ans -= (LL)query(tot) - (LL)query(a[u]);
		update(a[u],-1);
		u--;
	}
}

void update_l(int &u,int v){
	while(u > v){
		u--;
		cur_ans += (LL)query(a[u]-1);
		update(a[u],1);
	}
	while(u < v){
		cur_ans -= (LL)query(a[u]-1);
		update(a[u],-1);
		u++;
	}
}

void solve(int n,int q){
	hash_init();
	for(int i=1;i<=n;i++){
		a[i] = hash_find(a[i]);
	}
	memset(bit,0,sizeof bit);
	cur_l = cur_r = 1;
	update(a[1],1);
	cur_ans = 0;
	int s = (int)sqrt(n + 0.5);
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / s;
	}
	sort(que+1,que+q+1,cmp);
	for(int i=1;i<=q;i++){	
		if(ql(i) == qr(i)){
			ans[id(i)] = 0;
			continue;
		}
		update_r(cur_r,qr(i));
		update_l(cur_l,ql(i));
		ans[id(i)] = cur_ans;
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d %d",&ql(i),&qr(i));
			id(i) = i;
		}
		solve(n,q);
	}
	return 0;
}
