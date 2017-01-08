                                            
  //File Name: bzoj2038.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月08日 星期五 19时59分19秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <math.h>

#define LL long long
#define ql(i) que[(i)].ql
#define qr(i) que[(i)].qr
#define id(i) que[(i)].id

using namespace std;

const int MAXN = 50010;

struct Query{
	int ql,qr,id;
};

Query que[MAXN];
int col[MAXN];
LL sum[MAXN];
int curl,curr;
LL ans;
int bel[MAXN];
LL ret_1[MAXN];
LL ret_2[MAXN];

bool cmp(Query x,Query y){
	if(bel[x.ql] == bel[y.ql])
		return x.qr < y.qr;
	return bel[x.ql] < bel[y.ql];
}

LL sqr(LL x){
	return x * x;
}

LL gcd(LL x,LL y){
	if(y == 0)
		return x;
	return gcd(y,x % y);
}

void update_l(int &from,int to){
	while(from < to){
		ans = ans + sqr(sum[col[from]] - 1) - sqr(sum[col[from]]);
		sum[col[from]]--;
		from++;
	}
	while(from > to){
		from--;
		ans = ans + sqr(sum[col[from]] + 1) - sqr(sum[col[from]]);
		sum[col[from]]++;
	}
}

void update_r(int &from,int to){
	while(from < to){
		from++;
		ans = ans + sqr(sum[col[from]] + 1) - sqr(sum[col[from]]);;
		sum[col[from]]++;
	}
	while(from > to){
		ans = ans + sqr(sum[col[from]] - 1) - sqr(sum[col[from]]);
		sum[col[from]]--;
		from--;
	}
}

void solve(int n,int q){
	int s = (int)sqrt(n + 0.5);
	int num = n / s;
	if(n % s)
		num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / s;
	}
	sort(que+1,que+q+1,cmp);
	memset(sum,0,sizeof sum);
	curl = curr = 1;
	ans = 1;
	sum[col[1]] = 1;
	for(int i=1;i<=q;i++){
		if(ql(i) == qr(i)){
			ret_1[id(i)] = 0;
			ret_2[id(i)] = 1;
			continue;
		}
		//printf("l = %d  r = %d\n",ql(i),qr(i));
		update_r(curr,qr(i));
		update_l(curl,ql(i));
		//printf("ans = %d\n",ans);
		ret_1[id(i)] = (ans - qr(i) + ql(i) - 1);
		ret_2[id(i)] = (qr(i) - ql(i) + 1LL) * (qr(i) - ql(i) + 0LL);
		LL g = gcd(ret_1[id(i)],ret_2[id(i)]);
		ret_1[id(i)] /= g;
		ret_2[id(i)] /= g;
	}
	for(int i=1;i<=q;i++){
		printf("%lld/%lld\n",ret_1[i],ret_2[i]);
	}
	return ;
}

int main(){
	int n,q;
	while(~scanf("%d %d",&n,&q)){
		for(int i=1;i<=n;i++){
			scanf("%d",&col[i]);
		}
		for(int i=1;i<=q;i++){
			scanf("%d %d",&ql(i),&qr(i));
			id(i) = i;
		}
		solve(n,q);
	}
	return 0;
}
