                                            
  //File Name: zoj2112.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月01日 星期五 14时43分20秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

#define LL long long
#define hash hashhash

using namespace std;

const int MAXN = 60000 + 5;
const int N = 1500000 + 5;
struct Node{
	int ls,rs,w;
	Node(){
		ls = rs = w = 0;
	}
};
struct Que{
	char ch[2];
	int a,b,c;
};
Que que[10000 + 5];
Node node[N];
Node basenode[MAXN * 20 - 200000];
int baseroot[MAXN - 10000];
int root[MAXN - 10000];
int a[MAXN - 10000];
int basesz,sz;
int L[30],R[30],L_tot,R_tot;
int num[MAXN];
int hash[MAXN];
int tot,top;

inline int lb(int x){
	return x & (-x);
}

void hash_init(){
	tot = 0;
	sort(num+1,num+top+1);
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

void update(int &rt,int l,int r,int pos,int add){
	node[++sz] = node[rt];
	rt = sz;
	node[sz].w += add;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(pos  <= mid)
		update(node[sz].ls,l,mid,pos,add);
	else
		update(node[sz].rs,mid+1,r,pos,add);
}

void update_base(int &rt,int l,int r,int pos){
	basenode[++basesz] = basenode[rt];
	rt = basesz;
	basenode[rt].w += 1;
	if(l == r)
		return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update_base(basenode[rt].ls,l,mid,pos);
	else
		update_base(basenode[rt].rs,mid+1,r,pos);
}

int query(int bl,int br,int l,int r,int k){
	if(l == r)
		return l;
	int mid = (l + r) >> 1;
	int suml = basenode[basenode[bl].ls].w;
	int sumr = basenode[basenode[br].ls].w;
	for(int i=0;i<L_tot;i++){
		suml += node[node[L[i]].ls].w;
	}
	for(int i=0;i<R_tot;i++){
		sumr += node[node[R[i]].ls].w;
	}

	if(sumr - suml >= k){
		for(int i=0;i<L_tot;i++)
			L[i] = node[L[i]].ls;
		for(int i=0;i<R_tot;i++)
			R[i] = node[R[i]].ls;
		return query(basenode[bl].ls,basenode[br].ls,l,mid,k);
	}
	else{
		for(int i=0;i<L_tot;i++)
			L[i] = node[L[i]].rs;
		for(int i=0;i<R_tot;i++)
			R[i] = node[R[i]].rs;
		return query(basenode[bl].rs,basenode[br].rs,mid+1,r,k - sumr + suml);
	}
}

void solve(int n,int q){
	hash_init();
	basesz = sz = 0;
	baseroot[0] = 0;
	for(int i=1;i<=n;i++){
		baseroot[i] = baseroot[i-1];
		update_base(baseroot[i],1,tot,hash_find(a[i]));
	}
	memset(root,0,sizeof root);
	for(int j=1;j<=q;j++){
		if(que[j].ch[0] == 'Q'){
			int l = que[j].a;
			int r = que[j].b;
			int k = que[j].c;
			L_tot = R_tot = 0;
			for(int i=l-1;i>0;i-=lb(i)){
				L[L_tot++] = root[i];
			}
			for(int i=r;i>0;i-=lb(i)){
				R[R_tot++] = root[i];
			}
			printf("%d\n",hash[query(baseroot[l-1],baseroot[r],1,tot,k)]);
		}
		else{
			int pos = que[j].a;
			int u = hash_find(a[pos]);
			for(int i=pos;i<=n;i+=lb(i)){
				update(root[i],1,tot,u,-1);
			}
			a[pos] = que[j].b;
			u = hash_find(a[pos]);
			for(int i=pos;i<=n;i+=lb(i)){
				update(root[i],1,tot,u,1);
			}
		}
	} 
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,q;
		scanf("%d %d",&n,&q);
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		for(int i=1;i<=q;i++){
			scanf("%s",que[i].ch);
			if(que[i].ch[0] == 'Q'){
				scanf("%d %d %d",&que[i].a,&que[i].b,&que[i].c);
			}
			else{
				scanf("%d %d",&que[i].a,&que[i].b);
				num[++top] = que[i].b;
			}
		}
		solve(n,q);
	}
	return 0;
}

