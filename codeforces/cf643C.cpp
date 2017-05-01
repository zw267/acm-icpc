                                            
  //File Name: cf643C.cpp
  //Created Time: 2017年05月01日 星期一 17时18分42秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
const double INF = 1e14;
double t[MAXN],sum[MAXN],pre[MAXN],rev[MAXN];
double f[51][MAXN];
int que[MAXN];
int p;
void init(const int n){
	for(int i=1;i<=n;++i){
		sum[i] = sum[i - 1] + t[i];
		f[1][i] = pre[i] = pre[i - 1] + sum[i] / t[i];
		rev[i] = rev[i - 1] + 1.0 / t[i];
	}
}
double cal_b(const int u){
	return -pre[u] + f[p][u] + sum[u] * rev[u];
}
double cal_k(const int u){
	return sum[u];
}
double cal_f(int u,double x){
	double k = cal_k(u);
	double b = cal_b(u);
	return k * x + b;
}
double check(const int v,const int u){
	if(v <= u) puts("gggggggggggggggggggggggg");
	return (cal_b(v) - cal_b(u)) / (cal_k(v) - cal_k(u));
}
double solve(const int n,const int m){
	init(n);
	for(int i=2;i<=m;++i){
		p = i - 1;
		int head(0),tail(0);
		que[tail++] = 0;
		for(int j=1;j<=n;++j){
			while(head + 1 < tail && check(que[head+1],que[head])<=rev[j])
				++head;
			f[i][j] = pre[j] + cal_f(que[head],-rev[j]);
			while(head + 1 < tail && check(que[tail-1],que[tail-2]) >= check(j,que[tail-1]))
				--tail;
			que[tail++] = j;
		}
	}
	return f[m][n];
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lf",t + i);
	printf("%.15f\n",solve(n,m));
	return 0;
}
