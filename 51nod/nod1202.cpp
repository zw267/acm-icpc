                                            
  //File Name: nod1202.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月13日 星期一 20时47分16秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN = 100000 + 5;
const int MOD = (int)1e9 + 7;

LL seg[MAXN << 2];
LL f[MAXN];
int a[MAXN];
int pre[MAXN];

void pushup(int rt){
	seg[rt] = (seg[rt<<1] + seg[rt<<1|1]) % MOD;;
}

void update(int p,LL add,int l,int r,int rt){
	if(l == r){
		seg[rt] = add;
		return ;
	}
	int m = (l + r) >> 1;
	if(p <= m)
		update(p,add,lson);
	else
		update(p,add,rson);
	pushup(rt);
}

LL query(int L,int R,int l,int r,int rt){
	if(R < L) return 0;
	if(L <= l && R >= r)
		return seg[rt];
	int m = (l + r) >> 1;
	LL res = 0;
	if(L <= m) 
		res += query(L,R,lson);
	if(R > m)
		res += query(L,R,rson);
	return res % MOD;
}

void solve(int n){
	memset(seg,0,sizeof seg);
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=n;i++){
		if(pre[a[i]] == -1){
			f[i] = query(1,i-1,1,n,1);
			f[i]++;
			f[i] %= MOD;
			update(i,f[i],1,n,1);	
			pre[a[i]] = i;
		}
		else{
			f[i] = query(pre[a[i]],i-1,1,n,1);
			f[i] %= MOD;
			update(i,f[i],1,n,1);
			pre[a[i]] = i;
		}
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve(n);
		printf("%lld\n",seg[1]);
	}
	return 0;
}
