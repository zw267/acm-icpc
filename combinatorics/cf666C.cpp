                                            
  //File Name: cf666C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月20日 星期五 14时28分15秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;
const int MOD = (int)1e9 + 7;

LL jie[MAXN], p25[MAXN],inv[MAXN];
LL f[MAXN],ans[MAXN];

struct Query{
	int len,n,t;
	Query(int _len = 0,int _n = 0,int _t = 0){
		len = _len,n = _n,t = _t;
	}
	bool operator < (const Query & a) const{
		if(len == a.len)
			return n < a.n;
		return len < a.len;
	}
}q[MAXN];

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++)
		jie[i] = jie[i-1] * i % MOD;
	p25[0] = 1;
	for(int i=1;i<MAXN;i++){
		p25[i] = p25[i-1] * 25 % MOD;
	}
	for(int i=0;i<MAXN;i++)
		inv[i] = qp(jie[i],MOD - 2);
}

LL get_c(LL x,LL y){
	if(x < 0 || x < y) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * inv[y] % MOD * inv[x-y] % MOD;
}

char str[MAXN];

void update(int len,int N){
	for(int i=0;i<len;i++)
		f[i] = 0;
	f[len] = 1;
	for(int i=len+1;i<=N;i++){
		f[i] = f[i-1] * 26 % MOD + get_c(i-1,len-1) * p25[i-len] % MOD;
		f[i] %= MOD;
	}
}

void solve(int tot){
	init();
	sort(q,q+tot);
	int pre = -1;
	for(int i=0;i<tot;i++){
		if(q[i].len == pre){
			ans[q[i].t] = f[q[i].n];
		}
		else{
			pre = q[i].len;
			int now = i;
			while(now < tot - 1 && q[now+1].len == q[now].len){
				now++;
			}
			update(pre,q[now].n);
			ans[q[i].t] = f[q[i].n];
		}
	}
	for(int i=0;i<tot;i++)
		printf("%d\n",(int)ans[i]);
}

int main(){
	int op,len,tot = 0;
	scanf("%d",&op);
	scanf("%s",str);
	len = strlen(str);
	for(int i=1,u,n;i<=op;i++){
		scanf("%d",&u);
		if(u == 1){
			scanf("%s",str);
			len = strlen(str);
		}
		else{
			scanf("%d",&n);
			q[tot] = Query(len,n,tot);
			tot++;
		}
	}
	solve(tot);
	return 0;
}
