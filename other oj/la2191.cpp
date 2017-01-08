                                            
  //File Name: la2191.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月15日 星期五 15时19分25秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 200000+5;

int sum[MAXN << 2];

void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if(l == r){
		scanf("%d",&sum[rt]);
		return ;
	}
	int m =(l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p,int add,int l,int r,int rt)
{
	if(l == r){
		sum[rt] = add;
		return ;
	}
	int m=(l+r)>>1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L <= l && R >= r){
		return sum[rt];
	}
	int m=(l+r)>>1;
	int res = 0;
	if(L<=m)
		res += query(L,R,lson);
	if(R>m)
		res += query(L,R,rson);
	return res;
}

void solve(int n)
{
	build(1,n,1);

	char op[5];
	while(scanf("%s",op)){
		if(op[0] == 'E')
			return ;
		int a,b;
		scanf("%d %d",&a,&b);
		if(op[0] == 'S'){
			update(a,b,1,n,1);
		}
		else{
			printf("%d\n",query(a,b,1,n,1));
		}
	}
}

int main()
{
	int cas = 1;
	int n;
	while(~scanf("%d",&n)){
		if(!n)
			break;
		if(cas > 1)
			puts("");
		printf("Case %d:\n",cas++);
		solve(n);
	}
	return 0;
}
