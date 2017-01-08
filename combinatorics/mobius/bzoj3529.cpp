                                            
  //File Name: bzoj3529.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月19日 星期二 00时07分23秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define w first
#define id second

using namespace std;

const int MAXN = 100001;

pair<int,int> f[MAXN];
bool check[MAXN];
int mu[MAXN];
int prime[MAXN];
int bit[MAXN];
int ans[20000 + 3];

struct Query{
	int n,m,a,id;
};
Query que[20000 + 3];

bool cmp(Query x,Query y){
	return x.a < y.a;
}

inline int lb(int x){
	return x & (-x);
}

void update(int x,int add){
	while(x < MAXN){
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

void moebius(){
	memset(check,false,sizeof check);
	mu[1] = 1;
	int tot = 0;
	for(int i=2;i<MAXN;i++){
		if(!check[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<tot;j++){
			if(i * prime[j] >= MAXN)
				break;
			check[i * prime[j]] = true;
			if(i % prime[j] == 0){
				mu[i * prime[j]] = 0;
				break;
			}
			else
				mu[i * prime[j]] = -mu[i];
		}
	}
}

void init(){
	moebius();
	for(int i=1;i<MAXN;i++){
		f[i].id = i;
		for(int j=i;j<MAXN;j+=i){
			f[j].w += i;
		}
	}
}

int get(int n,int m){
	int res = 0;
	int ma = min(n,m),x,y,now;
	for(int i=1;i<=ma;){
		x = n / i;
		y = m / i;
		now = min(n / x,m / y);
		res += x * y * (query(now) - query(i - 1));
		i = now + 1;
	}
	//printf("%d\n",res);
	return res;
}

void solve(int q){
	sort(que,que + q,cmp);
	sort(f+1,f+MAXN);
	memset(bit,0,sizeof bit);
	int pos = 1;
	for(int i=0;i<q;i++){
		while(pos < MAXN && f[pos].w <= que[i].a){
			int d = f[pos].id, w = f[pos].w;
			for(int j=d;j<MAXN;j+=d){
				//printf("%d\n",w);
				update(j,w * mu[j/d]);
			}
			pos++;
		}
		ans[que[i].id] = get(que[i].n,que[i].m);
	}
	for(int i=0;i<q;i++){
		ans[i] = ans[i] & 0x7fffffff;
		printf("%d\n",ans[i]);
	}
	return ;
}

int main(){
	init();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d %d",&que[i].n,&que[i].m,&que[i].a);
		que[i].id = i;
	}
	solve(q);
	return 0;
}
