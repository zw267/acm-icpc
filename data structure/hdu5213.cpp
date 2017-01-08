                                            
  //File Name: hdu5213.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月09日 星期六 12时35分49秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <map>

#define LL long long
#define ql(i) que[(i)].ql
#define qr(i) que[(i)].qr
#define id(i) que[(i)].id

using namespace std;

const int MAXN = 30000 + 3;

struct Que{
	int ql,qr,id;
};
Que que[MAXN];
int a[MAXN];
int bit[MAXN];
int K,cur_l,cur_r,ans,tot;
int out[MAXN];
int quer[MAXN][4];
int bel[MAXN];
int dx[] = {0,0,1,1};
int dy[] = {3,2,3,2};

inline int lb(int x){
	return x & (-x);
}

void update(int p,int add){
	while(p <= tot){
		bit[p] += add;
		p += lb(p);
	}
}

int query(int p){
	int res = 0;
	while(p <= tot && p > 0){
		res += bit[p];
		p -= lb(p);
	}
	return res;
}

bool cmp(Que x,Que y){
	if(bel[x.ql] == bel[y.ql])
		return x.qr < y.qr;
	return bel[x.ql] < bel[y.ql];
}

void update_r(int &u,int v){
	while(u < v){
		u++;
		if(0 < K - a[u] && K - a[u] <= tot)
			ans += bit[K-a[u]],bit[a[u]]++;
	}
	while(u > v){
		if(0 < K - a[u] && K - a[u] <= tot)
			ans -= bit[K-a[u]],bit[a[u]]--;
		u--;
	}
}

void update_l(int &u,int v){
	while(u > v){
		u--;
		if(0 < K - a[u] && K - a[u] <= tot)
			ans += bit[K - a[u]],bit[a[u]]++;
	}
	while(u < v){
		if(0 < K - a[u] && K - a[u] <= tot)
			ans -= bit[K - a[u]],bit[a[u]]--;
		u++;
	}
}

void solve_sub(int n,int q,bool plus){
	sort(que,que+q,cmp);
	memset(bit,0,sizeof bit);
	cur_l = cur_r = 1;
	ans = 0;
	update(a[1],1);
	for(int i=0;i<q;i++){
		if(ql(i) >= qr(i) || ql(i) >= n || qr(i) < 0)
			continue;
		update_r(cur_r,qr(i));
		update_l(cur_l,ql(i));
		if(plus)
			out[id(i)] += ans;
		else
			out[id(i)] -= ans;
	}
	return ;
}

void solve(int n,int q){
	int s = (int)sqrt(n + 0.5);
	tot = n;
	for(int i=0;i<n;i++){
		bel[i] = i / s;
	}
	memset(out,0,sizeof out);
	for(int j=0;j<4;j++){
		for(int i=0;i<q;i++){
			ql(i) = quer[i][dx[j]];
			qr(i) = quer[i][dy[j]];
			id(i) = i;
			if(j == 1){
				qr(i)--;
			}
			else if(j == 2){
				ql(i)++;
			}
			else if(j == 3){
				ql(i)++;
				qr(i)--;
			}
		}
		solve_sub(n,q,(dx[j] + dy[j]) % 2);
		//for(int i=0;i<q;i++){
		//	printf("%d\n",out[i]);
		//}
	}
	for(int i=0;i<q;i++){
		printf("%d\n",out[i]);
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		scanf("%d",&K);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d %d %d %d",&quer[i][0],&quer[i][1],&quer[i][2],&quer[i][3]);
			quer[i][0]--;
			quer[i][1]--;
			quer[i][2]--;
			quer[i][3]--;
		}
		solve(n,q);
	}
	return 0;
}
