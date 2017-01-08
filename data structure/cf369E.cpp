                                            
  //File Name: cf369E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月14日 星期四 22时36分22秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 300000 + 3;
const int N = 1000000;

struct Line{
	int l,r,id;
};
Line p[MAXN];
Line q[N * 10];
int ans[MAXN];
int bit[N + 5];
int tot;

inline int lb(int x){
	return x & (-x);
}

void update(int x,int add){
	while(x <= N){
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

bool cmp(Line x,Line y){
	if(x.r == y.r)
		return x.l < y.l;
	return x.r < y.r;
}

void solve(int n,int m){
	sort(p,p + n,cmp);
	sort(q,q + tot,cmp);
	memset(ans,0,sizeof ans);
	int pos = 0;
	for(int i=0;i<tot;i++){
		while(pos < n && p[pos].r <= q[i].r){
			update(p[pos].l,1);
			pos++;
		}
		ans[q[i].id] += query(q[i].r) - query(q[i].l - 1);
	}
	
	for(int i=0;i<m;i++){
		printf("%d\n",n - ans[i]);
	}
	return ;
}

int main(){
	int n,m;
	tot = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i].l,&p[i].r);
	}
	for(int i=0,num,pre,x;i<m;i++){
		scanf("%d",&num);
		pre = 0;
		while(num--){
			scanf("%d",&x);
			if(pre + 1 <= x - 1){
				q[tot].l = pre + 1;
				q[tot].r = x - 1;
				q[tot++].id = i;
			}
			pre = x;
		}
		if(pre + 1 <= N){
			q[tot].l = pre + 1;
			q[tot].r = N;
			q[tot++].id = i;
		}
	}
	solve(n,m);
	return 0;
}

