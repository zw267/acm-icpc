                                            
  //File Name: cf138C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月03日 星期三 15时25分37秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define hash _hash_

using namespace std;

const int MAXN = 100000 + 2;
const int MAXM = 10000 + 2;

int num[MAXN * 4 + MAXM],hash[MAXN * 4 + MAXM],tot,top;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1]) 
			hash[++tot] = num[i];
}

int hash_find(int x){
	int l = 1,r = tot ,mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

struct Line{
	int l,r;
	double p;
	Line(int _l = 0,int _r = 0,double _p = 0.0){
		l = _l,r = _r,p = _p;
	}
}line[MAXN << 1];

int b[MAXM],z[MAXM];
double ly[MAXN * 16 + MAXM * 4];

void pushdown(int rt){
	if(ly[rt] >= 0){
		if(ly[rt<<1] == -1) ly[rt<<1] = ly[rt];
		else ly[rt<<1] *= ly[rt];
		if(ly[rt<<1|1] == -1) ly[rt<<1|1] = ly[rt];
		else ly[rt<<1|1] *= ly[rt];
		ly[rt] = -1;
	}
}

void build(int l,int r,int rt){
	ly[rt] = -1.0;
	if(l == r){
		ly[rt] = 1.0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int L,int R,double add,int l,int r,int rt){
	if(L <= l && R >= r){
		if(ly[rt] == -1) ly[rt] = add;
		else ly[rt] = ly[rt] * add;
		return ;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) update(L,R,add,lson);
	if(R > mid) update(L,R,add,rson);
}

double query(int p,int l,int r,int rt){
	if(l == r) return ly[rt];
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(p <= mid) return query(p,lson);
	else return query(p,rson);
}

double solve(int n,int m){
	hash_init();
	build(1,tot,1);
	for(int i=0;i<n;i++){
		update(hash_find(line[i].l),hash_find(line[i].r),line[i].p,1,tot,1);
	}
	double ans = 0.0,tmp;
	for(int i=0;i<m;i++){
		tmp = query(hash_find(b[i]),1,tot,1);
		ans += tmp * z[i];
	}
	return ans;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		int len = 0,a,h,l,r;
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d %d",&a,&h,&l,&r);
			num[++top] = a - h;
			num[++top] = a - 1;
			num[++top] = a + 1;
			num[++top] = a + h;
			line[len++] = (Line){a-h,a-1,1.0 - (l + 0.0) / 100.0};
			line[len++] = (Line){a+1,a+h,1.0 - (r + 0.0) / 100.0};
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&b[i],&z[i]);
			num[++top] = b[i];
		}
		printf("%.12f\n",solve(len,m));
	}
	return 0;
}
