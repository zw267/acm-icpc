                                            
  //File Name: cf387E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月20日 星期三 16时27分49秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 1000000 + 3;

int bit1[MAXN];
int bit2[MAXN];
int p[MAXN];
int at[MAXN];
bool is[MAXN];

inline int lb(int x){
	return x & (-x);
}

void update(int x,int add,int n,int *bit){
	while(x <= n){
		bit[x] += add;
		x += lb(x);
	}
}

int query(int x,int n,int *bit){
	int res = 0;
	while(x > 0 && x <= n){
		res += bit[x];
		x -= lb(x);
	}
	return res;
}

int bs_l(int x,int n){
	int l = 0,r = x,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(query(x,n,bit1) - query(mid - 1,n,bit1) == 0)
			r = mid;
		else
			l = mid;
	}
	return r;
}

int bs_r(int x,int n){
	int l = x,r = n + 1,mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(query(mid,n,bit1) - query(x - 1,n,bit1) == 0)
			l = mid;
		else
			r = mid;
	}
	return l;
}

void solve(int n,int k){
	memset(bit1,0,sizeof bit1);
	memset(bit2,0,sizeof bit2);
	LL ans = 0;
	for(int i=1,l,r;i<=n;i++){
		if(is[i]){
			update(at[i],1,n,bit1);
		}
		else{
			l = bs_l(at[i],n);
			r = bs_r(at[i],n);
			ans += (LL)(r - l + 1) - query(r,n,bit2) + query(l - 1,n,bit2);
			update(at[i],1,n,bit2);
			//cout << l << " " << r << " " << ans << endl;
		}
	}
	//printf("%lld\n",ans);
	cout << ans << endl;
}

int main(){
	memset(is,false,sizeof is);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		at[p[i]] = i;
	}
	for(int i=1,u;i<=k;i++){
		scanf("%d",&u);
		is[u] = true;
	}
	solve(n,k);
	return 0;
}
