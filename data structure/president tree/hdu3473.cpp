                                            
  //File Name: hdu3473.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月04日 星期一 00时43分43秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

#define hash hashhash
#define LL long long
#define sum(i) node[(i)].sum
#define w(i) node[(i)].w
#define ls(i) node[(i)].ls
#define rs(i) node[(i)].rs

using namespace std;

const int MAXN = 100000 + 3;

struct Node{
	int ls,rs,w;
	LL sum;
	Node(){
		ls = rs = w = sum = 0;
	}
};
Node node[MAXN * 18];
int root[MAXN];
int a[MAXN];
int num[MAXN];
int hash[MAXN];
int tot,top,sz;

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

void update(int &rt,int l,int r,int pos,int add){
	node[++sz] = node[rt];
	rt = sz;
	w(sz) += 1;
	sum(sz) += (LL)add;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(ls(sz),l,mid,pos,add);
	else
		update(rs(sz),mid+1,r,pos,add);
}

int query_k(int L,int R,int l,int r,int k){
	if(l == r)
		return l;
	int cur = w(ls(R)) - w(ls(L));
	int mid = (l + r) >> 1;
	if(cur >= k)
		return query_k(ls(L),ls(R),l,mid,k);
	else
		return query_k(rs(L),rs(R),mid +1,r,k - cur);
}

LL query(int L,int R,int l,int r,int ql,int qr){
	if(l == r){
		return (sum(R) - sum(L)) / (w(R) - w(L)) * (qr - ql + 1);
	}
	int cur = w(ls(R)) - w(ls(L));
	int mid = (l + r) >> 1;
	if(cur >= qr)
		return query(ls(L),ls(R),l,mid,ql,qr);
	else if(cur < ql)
		return query(rs(L),rs(R),mid+1,r,ql-cur,qr-cur);
	else
		return query(ls(L),ls(R),l,mid,ql,cur) + query(rs(L),rs(R),mid+1,r,1,qr-cur);
}

void solve(int n){
	sz = 0;
	hash_init();
	root[0] = 0;
	for(int i=1;i<=n;i++){
		root[i] = root[i-1];
		update(root[i],1,tot,hash_find(a[i]),a[i]);
	}
	int q;
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++){
		scanf("%d %d",&l,&r);
		l++;
		r++;
		if(l == r){
			puts("0");
			continue;
		}
		int tmp = (r - l + 1) / 2;
		int cnt = tmp + l;
		LL mid = query_k(root[l-1],root[r],1,tot,tmp + 1);
		//printf("mid = %lld\n",mid);
		LL ans = hash[mid] * tmp - hash[mid] * (r - cnt + 1);
		//cout << ans << endl;
		if(tmp >= 1)
			ans = ans - query(root[l-1],root[r],1,tot,1,tmp);
		//cout << ans << endl;
		if(tmp + 1 <= r-l+1)
			ans = ans + query(root[l-1],root[r],1,tot,tmp + 1,r-l+1);
		printf("%d\n",ans);
	}
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	int cas = 1;
	while(test--){
		if(cas > 1)
			puts("");
		printf("Case #%d:\n",cas++);
		int n;
		scanf("%d",&n);
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		solve(n);
	}
	return 0;
}

