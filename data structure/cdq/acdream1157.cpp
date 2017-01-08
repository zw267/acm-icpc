                                            
  //File Name: acdream1157.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月29日 星期五 12时56分21秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long
#define hash _hash_

using namespace std;

const int MAXN = 100000 + 3;

int h_num[MAXN << 1],hash[MAXN << 1],tot,top;

void hash_init(){
	sort(h_num+1,h_num+top+1);
	tot = 0;
	hash[++tot] = h_num[1];
	for(int i=2;i<=top;i++){
		if(h_num[i] != h_num[i-1])
			hash[++tot] = h_num[i];
	}
}

int hash_find(int x){
	int l = 1, r = tot ,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

struct Query{
	int t,op,l,r,ans;
	Query(int _t = 0,int _op = 0,int _l = 0,int _r = 0){
		t = _t,op = _op,l = _l,r = _r;
	}
	bool operator < (const Query &a) const{
		if(l == a.l) return op < a.op;
		return l < a.l;
	}
}que[MAXN],q1[MAXN],q2[MAXN];

int bit[MAXN << 1];
int ans[MAXN];

void update(int x,int add){
	while(x <= tot){
		bit[x] += add;
		x += x & (-x);
	}
}

int query(int x){
	int res = 0;
	while(x){
		res += bit[x];
		x -= x & (-x);
	}
	return res;
}

bool cmp(Query &a,Query &b){
	return a.t < b.t;
}

void cdq(int l,int r){
	if(r <= l) return ;
	int mid = (l + r) >> 1;
	cdq(l,mid);
	cdq(mid+1,r);
	int s1 = 0,s2 = 0;
	for(int i=l;i<=mid;i++){
		if(que[i].op != 2)
			q1[s1++] = que[i];
	}
	for(int i=mid+1;i<=r;i++){
		if(que[i].op == 2)
			q2[s2++] = que[i];
	}
	sort(q1,q1+s1);
	sort(q2,q2+s2);
	int u = 0;
	for(int i=0;i<s2;i++){
		while(u < s1 && q1[u].l <= q2[i].l){
			if(q1[u].op == 0)  update(q1[u].r,1);
			else update(q1[u].r,-1);
			u++;
		}
		ans[q2[i].t] += query(tot) - query(q2[i].r - 1);
	}
	for(int i=0;i<u;i++){
		if(q1[i].op == 0) update(q1[i].r,-1);
		else update(q1[i].r,1);
	}
}

void solve(int n){
	hash_init();
	for(int i=1;i<=n;i++){
		que[i].l = hash_find(que[i].l);
		que[i].r = hash_find(que[i].r);
	}
	memset(ans,0,sizeof(ans));
	cdq(1,n);
	//printf("bit = %d\n",query(tot));
	sort(que+1,que+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(que[i].op == 2){
			printf("%d\n",ans[que[i].t]);
		}
	}
}

int tmp[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int op,l,r;
		top = 0,tot = 0;
		char ch[3];
		for(int i=1;i<=n;i++){
			scanf("%s",ch);
			if(ch[0] == 'C'){
				scanf("%d",&l);
				que[i] = (Query){i,1,que[tmp[l]].l,que[tmp[l]].r};
			}
			else{
				scanf("%d %d",&l,&r);
				h_num[++top] = l;
				h_num[++top] = r;
				if(ch[0] == 'D'){
					tmp[++tot] = i;
					que[i] = (Query){i,0,l,r};
				}
				else
					que[i] = (Query){i,2,l,r};
			}
		}
		solve(n);
	}
	return 0;
}
