                                            
  //File Name: hdu3727.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月04日 星期一 13时43分03秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define hash hashhash

using namespace std;

const int MAXN = 100005;

struct Node{
	int ls,rs,w;
	Node(){
		ls = rs = w = 0;
	}
};
struct Que{
	int op,s,t,k;
	Que(){
		op = s = t = k = 0;
	}
};
Que que[400000];
Node node[MAXN * 18];
int root[MAXN];
int num[MAXN];
int hash[MAXN];
int tot,top,sz;
int bit[MAXN];
LL ans[4];

inline int lb(int x){
	return x & (-x);
}

void update_bit(int p,int add){
	while(p <= tot){
		bit[p] += add;
		p += lb(p);
	}
}

int query_bit(int p){
	int res = 0;
	while(p > 0){
		res += bit[p];
		p -= lb(p);
	}
	return res;
}

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
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

void update(int &rt,int l,int r,int p){
	node[++sz] = node[rt];
	rt = sz;
	node[sz].w++;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(node[rt].ls,l,mid,p);
	else
		update(node[rt].rs,mid+1,r,p);
}

int query(int L,int R,int l,int r,int k){
	if(l == r){
		return l;
	}
	int cur = node[node[R].ls].w - node[node[L].ls].w;
	int mid = (l + r) >> 1;
	if(cur >= k)
		return query(node[L].ls,node[R].ls,l,mid,k);
	else
		return query(node[L].rs,node[R].rs,mid+1,r,k-cur);
}

void solve(int n){
	memset(bit,0,sizeof bit);
	hash_init();
	for(int i=1;i<=3;i++)
		ans[i] = 0;
	sz = 0;
	root[0] = 0;
	int ma = 0;
	for(int i=1;i<=n;i++){
		if(que[i].op == 0){
			ma++;
			int pos = hash_find(que[i].s);
			root[ma] = root[ma - 1];
			update(root[ma],1,tot,pos);
			update_bit(pos,1);
		}
		else if(que[i].op == 1){
			ans[1] += (LL)hash[query(root[que[i].s-1],root[que[i].t],1,tot,que[i].k)];
		}
		else if(que[i].op == 2){
			ans[2] += (LL)query_bit(hash_find(que[i].s));
		}
		else{
			ans[3] += (LL)hash[query(root[0],root[ma],1,tot,que[i].s)];
		}
	}
	for(int i=1;i<=3;i++)
		printf("%lld\n",ans[i]);
	return ;
}

char str[20];

int main(){
	int n;
	int cas = 1;
	while(~scanf("%d",&n)){
		printf("Case %d:\n",cas++);
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%s",str);
			if(str[0] == 'I'){
				que[i].op = 0;
				scanf("%d",&que[i].s);
				num[++top] = que[i].s;
			}
			else if(str[6] == '1'){
				que[i].op = 1;
				scanf("%d %d %d",&que[i].s,&que[i].t,&que[i].k);
			}
			else if(str[6] == '2'){
				que[i].op = 2;
				scanf("%d",&que[i].s);
			}
			else{
				que[i].op = 3;
				scanf("%d",&que[i].s);
			}
		}
		solve(n);
	}
	return 0;
}
