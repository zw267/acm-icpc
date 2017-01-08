                                            
  //File Name: cf220E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月20日 星期三 20时07分48秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define hash hashhash

using namespace std;

const int MAXN = 100000 + 3;

int a[MAXN];
int hash[MAXN];
int num[MAXN];
int top,tot;
LL f[MAXN];
LL g[MAXN];
int bit1[MAXN];
int bit2[MAXN];

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++){
		if(num[i] != num[i - 1])
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

inline int lb(int x){
	return x & (-x);
}

void update(int x,int add,int *bit){
	while(x <= tot){
		bit[x] += add;
		x += lb(x);
	}
}

int query(int x,int *bit){
	int res = 0;
	while(x > 0){
		res += bit[x];
		x -= lb(x);
	}
	return res;
}

void init(int n){
	f[0] = g[n + 1] = 0;
	for(int i=1;i<=n;i++){
		f[i] = f[i - 1] + query(tot,bit1) - query(a[i],bit1);
		update(a[i],1,bit1);
	}
	memset(bit1,0,sizeof bit1);
	for(int i=n;i>0;i--){
		g[i] = g[i + 1] + query(a[i] - 1,bit2);
		update(a[i],1,bit2);
	}
}

void solve(int n,LL K){
	hash_init();
	for(int i=1;i<=n;i++)
		a[i] = hash_find(a[i]);
	init(n);
	if(f[n] <= K){
		cout << (LL)(n - 1) * n / 2 << endl;
		return ;
	}	
	update(a[1],-1,bit2);
	update(a[1],1,bit1);
	LL ans = 0,now = query(a[1] - 1,bit2);
	int l = 1,r = 2;
	while(l < n){
		while(r <= n && f[l] + g[r] + now > K){
			now -= query(tot,bit1) - query(a[r],bit1);
			update(a[r],-1,bit2);
			r++;
		}
		if(r > n)
			break;
		//printf("l = %d r = %d\n",l,r);
		ans += n - r + 1;
		l++;
		update(a[l],1,bit1);
		now += query(a[l] - 1,bit2);
	}
	cout << ans << endl;
}

int main(){
	int n;
	LL K;
	scanf("%d",&n);
	cin >> K;
	top = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[++top] = a[i];
	}
	solve(n,K);
	return 0;
}
