                                            
  //File Name: hdu5145.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月09日 星期六 01时30分46秒
                                   

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

const int MAXN = 30000 + 100;
const int N = 1000000;
const int MOD = (int)1e9 + 7;

struct Query{
	int ql,qr,id;
};
Query que[MAXN];
int a[MAXN];
int num[MAXN];
int bel[MAXN];
LL inv[N];
LL jie[MAXN];
int cur_l,cur_r,sum;
LL ans;
LL out[MAXN];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1)
			res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++){
		jie[i] = jie[i-1] * i % MOD;
	}
	for(int i=0;i<N;i++){
		inv[i] = qp(i,MOD - 2);
	}
}

LL get_inv(LL x){
	if(x < N)
		return inv[x];
	return qp(x,MOD - 2);
}

bool cmp(Query x,Query y){
	if(bel[x.ql] == bel[y.ql])
		return x.qr < y.qr;
	return bel[x.ql] < bel[y.ql];
}

void update_r(int &u,int v){
	while(u < v){
		u++;
		ans = ans * (sum + 1) % MOD * jie[num[a[u]]] % MOD * get_inv(jie[num[a[u]] + 1]) % MOD;
		num[a[u]]++;
		sum++;
	}
	while(u > v){
		ans = ans * jie[num[a[u]]] % MOD * get_inv(jie[num[a[u]] - 1] * sum % MOD) % MOD;
		num[a[u]]--;
		u--;
		sum--;
	}
}

void update_l(int &u,int v){
	while(u < v){
		ans = ans * jie[num[a[u]]] % MOD * get_inv(jie[num[a[u]] - 1] * sum % MOD) % MOD;
		num[a[u]]--;
		sum--;
		u++;
	}
	while(u > v){
		u--;
		ans = ans * (sum + 1) % MOD * jie[num[a[u]]] % MOD * get_inv(jie[num[a[u]] + 1]) % MOD;
		num[a[u]]++;
		sum++;
	}
}

void solve(int n,int q){
	memset(num,0,sizeof num);
	int s = (int)sqrt(n + 0.5);
	for(int i=0;i<n;i++){
		bel[i] = i / s;
	}
	sort(que,que+q,cmp);
	memset(num,0,sizeof num);
	cur_l = cur_r = 0;
	ans = sum = 1;
	num[a[0]]++;

	for(int i=0;i<q;i++){
		if(ql(i) == qr(i)){
			out[id(i)] = 1;
			continue;
		}
		update_r(cur_r,qr(i));
		update_l(cur_l,ql(i));
		out[id(i)] = ans;
	}
	for(int i=0;i<q;i++){
		printf("%lld\n",out[i]);
	}
	return ;
}

int main(){
	init();
	int test;
	scanf("%d",&test);
	while(test--){
		int n,q;
		scanf("%d %d",&n,&q);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<q;i++){
			scanf("%d %d",&ql(i),&qr(i));
			ql(i)--;
			qr(i)--;
			id(i) = i;
		}
		solve(n,q);
	}
	return 0;
}
