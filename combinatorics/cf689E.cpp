                                            
  //File Name: cf689E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月11日 星期一 18时44分40秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>

#define LL long long

using namespace std;

const int MAXN = 200000 + 3;
const int MAXN2 = 800000 + 3;
const int MOD = (int)1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Line{
	int l,r;
	bool operator<(const Line &a)const{
		if(a.r == r) return a.l < l;
		return a.r < r;
	}
}line[MAXN];

int g[MAXN2],s[MAXN2];
LL jie[MAXN2];

void init(){
	jie[0] = 1;
	for(int i=1;i<MAXN2;i++)
		jie[i] = jie[i-1] * i % MOD;
	memset(g,0,sizeof g);
	memset(s,0,sizeof s);
}

LL qp(LL x,LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

LL get_C(int x,int y){
	if(x < 0 || x < y) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x - y] % MOD,MOD - 2) % MOD;
}

bool cmp(Line x,Line y){
	if(x.l == y.l)
		return x.r < y.r;
	return x.l < y.l;
}

LL solve(int N,int K){
	sort(line,line+N,cmp);
	line[N].l = INF;
	int tot = 0,sum = 0,now = line[0].l;
	int iter = 0;
	priority_queue<Line> que;
	while(!que.empty()) que.pop();
	while(!(iter == N && que.empty())){
		while(iter < N && line[iter].l <= now){
			que.push(line[iter]);
			sum++;
			iter++;
		}
		int now_r = que.top().r;
		//printf("now_r = %d sum = %d iter = %d\n",now_r,sum,iter);
		if(now_r < line[iter].l){
			g[++tot] = now_r - now + 1;
			s[tot] = sum;
			now = now_r + 1;
			//puts("1111111");
		}
		else{
			g[++tot] = line[iter].l - now;
			s[tot] = sum;
			now = line[iter].l;
			//puts("222222222222");
		}
		while(sum && que.top().r < now){
			que.pop();
			sum--;
		}
		if(que.empty())
			now = line[iter].l;
	}
	LL ans = 0;
	for(int i=1;i<=tot;i++){
		ans = (ans + get_C(s[i],K) * g[i] % MOD) % MOD;
	}
	return ans;
}

int main(){
	init();
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&line[i].l,&line[i].r);
		}
		printf("%d\n",(int)solve(n,k));
	}
	return 0;
}
