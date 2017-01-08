                                            
  //File Name: bzoj2957.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月09日 星期六 14时39分38秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

#define LL long long

using namespace std;

const int MAXN = 100000 + 5;
const double eps = 1e-11;
const int s = 500;

int a[MAXN];
int bel[MAXN];
double deq[210][s + 5];
int len[1000];
int num;

int sgn(double x){
	if(fabs(x) < eps)
		return 0;
	if(x < 0)
		return -1;
	return 1;
}

void update(int p,int add,int n){
	a[p] = add;
	int l = min(bel[p] * s + 1,n);
	int r = min(bel[p] * s + s,n);
	len[bel[p]] = 0;
	double pre = 0.0;
	for(int i=l;i<=r;i++){
		if(a[i] == 0)
			continue;
		double cur = (double )a[i] / i;
		if(cur > pre){
			deq[bel[p]][++len[bel[p]]] = cur;
			pre = cur;
		}
	}
}

int bs(double *ds,double cur,int p){
	if(len[p] == 0)
		return -1;
	ds[0] = 0.0;
	int l = 0,r = len[p],mid;
	if(ds[r] <= cur)
		return -1;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(ds[mid] > cur)
			r = mid;
		else
			l = mid;
	}
	return len[p] - r + 1;
}

int query(int n){
	int res = 0,cur;
	double pre = 0.0;
	for(int i=0;i<num;i++){
		cur = bs(deq[i],pre,i);			
		if(cur <= 0)
			continue;
		res += cur;
		pre = deq[i][len[i]];
	}
	return res;
}

void solve(int n,int q){
	memset(a,0,sizeof a);
	memset(len,0,sizeof len);
	//s = (int)sqrt(n + 0.5);
	//s = (int)pow(n + 0.0,2.0 / 3.0);
	num = n / s;
	if(n % s)
		num++;
	for(int i=1;i<=n;i++){
		bel[i] = (i - 1) / s;
	}
	for(int i=0,p,add;i<q;i++){
		scanf("%d %d",&p,&add);
		update(p,add,n);
		printf("%d\n",query(n));
	}
	return ;
}

int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		solve(n,m);
	}
	return 0;
}
