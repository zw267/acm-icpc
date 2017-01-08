                                            
  //File Name: nbut1457.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月08日 星期五 23时42分39秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long
#define ql(i) que[(i)].ql
#define qr(i) que[(i)].qr
#define id(i) que[(i)].id
#define hash hashhash

using namespace std;

const int MAXN = 100000 + 3;

struct Query{
	int ql,qr,id;
};
Query que[MAXN];
int a[MAXN];
int num[MAXN];
int hash[MAXN];
int bel[MAXN];
int sum[MAXN];
int tot,top;
int cur_l,cur_r;
LL ans;
LL out[MAXN];

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
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

inline LL sqr(LL x){
	return x * x * x;
}

bool cmp(Query x ,Query y){
	if(bel[x.ql] == bel[y.ql])
		return x.qr < y.qr;
	return bel[x.ql] < bel[y.ql];
}

void update_r(int &u,int v){
	while(u < v){
		u++;
		ans = ans - sqr(sum[a[u]]) + sqr(sum[a[u]] + 1);
		sum[a[u]]++;
	}
	while(u > v){
		ans = ans - sqr(sum[a[u]]) + sqr(sum[a[u]] - 1);
		sum[a[u]]--;
		u--;
	}
}

void update_l(int &u,int v){
	while(u < v){
		ans = ans - sqr(sum[a[u]]) + sqr(sum[a[u]] - 1);
		sum[a[u]]--;
		u++;
	}
	while(u > v){
		u--;
		ans = ans - sqr(sum[a[u]]) + sqr(sum[a[u]] + 1);
		sum[a[u]]++;
	}
}

void solve(int n,int q){
	hash_init();
	for(int i=0;i<n;i++){
		a[i] = hash_find(a[i]);
	}
	int s = (int)sqrt(n + 0.5);
	for(int i=0;i<n;i++){
		bel[i] = i / s;
	}
	memset(sum,0,sizeof sum);
	cur_l = cur_r = 1;
	ans = 1;
	sum[a[1]] = 1;
	sort(que,que+q,cmp);
	for(int i=0;i<q;i++){
		if(ql(i) == qr(i)){
			out[id(i)] = 1;
			continue;
		}
		update_r(cur_r,qr(i));
		update_l(cur_l,ql(i));
		//printf("l = %d r = %d\n",ql(i),qr(i));
		//for(int j=1;j<=tot;j++){
		//	printf("%d  ",sum[j]);
		//}
		//printf("\n%lld\n",ans);
		out[id(i)] = ans;
	}
	for(int i=0;i<q;i++){
		printf("%lld\n",out[i]);
	}
	return ;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		top = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			num[++top] = a[i];
		}
		int q;
		scanf("%d",&q);
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
