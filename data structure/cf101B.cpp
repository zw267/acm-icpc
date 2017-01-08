                                            
  //File Name: cf101B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月23日 星期三 19时51分58秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define hash hashhash

using namespace std;

const int MAXN = (int)1e5 + 5;
const int MOD = (int)1e9 + 7;

pair<int,int> bus[MAXN];
LL f[MAXN << 1];
LL bit[MAXN << 1];
int num[MAXN << 1];
int hash[MAXN << 1];
int tot,top;

inline int lb(int x){
	return x & (-x);
}

void update(int x,LL add){
	while(x <= tot){
		bit[x] = (bit[x] + add) % MOD;
		x += lb(x);
	}
}

LL query(int x){
	LL res = 0;
	while(x > 0){
		res = (res + bit[x]) % MOD;
		x -= lb(x);
	}
	return res;
}

void hash_init(){
	tot = 0;
	sort(num+1,num+top+1);
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

void solve(int n,int m){
	hash_init();
	sort(bus,bus+m);
	memset(bit,0,sizeof bit);
	update(1,1);
	LL cur;
	for(int i=0,s,t;i<m;i++){
		s = hash_find(bus[i].sec);
		t = hash_find(bus[i].fir);
		cur = (query(t - 1) - query(s - 1) + MOD) % MOD;
		update(t,cur);
	}
	//int nn = hash_find(n);
	//for(int i=1;i<=nn;i++){
	//	printf("%d  ",(int)f[i]);
	//}
	n = hash_find(n);
	LL ans = (query(n) - query(n - 1) + MOD) % MOD;
	printf("%d\n",(int)ans);
	return ;
}

int main(){
	int n,m;
	top = 0;
	bool flag = false;
	scanf("%d %d",&n,&m);
	for(int i=0,s,t;i<m;i++){
		scanf("%d %d",&s,&t);
		bus[i] = mp(t,s);
		num[++top] = s;
		num[++top] = t;
		if(s == 0)
			flag = true;
	}
	num[++top] = n;
	if(!flag)
		puts("0");
	else
		solve(n,m);
	return 0;
}
