                                            
  //File Name: cf191E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月05日 星期五 15时00分55秒
                                   

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
#define hash _hash_
using namespace std;
const int MAXN = 100000 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL num[MAXN],hash[MAXN],sum[MAXN];
int tot,top,to[MAXN],bit[MAXN];
LL mi,ma;

void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}
int hash_find(LL x){
	int l = 1,r = tot,mid;
	while(l <= r){
		mid = l + r >> 1;
		if(hash[mid] < x) l = mid + 1;
		else  r = mid - 1;
	}
	return l;
}
void update(int x,int add){
	for(;x<=tot;x+=x & (-x))
		bit[x] += add;
}
int query(int x){
	int res = 0;
	for(;x>0;x-= x & (-x))
		res += bit[x];
	return res;
}
LL cal(int n,LL x){
	LL res = 0,u;
	int v;
	memset(bit,0,sizeof bit);
	update(to[0],1);
	for(int j=1;j<=n;j++){
		u = sum[j] - x;
		if(u < mi){
			update(to[j],1);
			continue;
		}
		v = hash_find(u);
		if(hash[v] >= u) v--;
		//printf("u = %lld v = %d\n",u,v);
		res += query(v);
		update(to[j],1);
	}
	return res;
}
LL solve(const int n,LL K){
	mi = -100000000000000;
	ma = 100000000000000;
	num[++top] = mi;
	num[++top] = ma;
	hash_init();
	//for(int i=0;i<=n;i++) cout << "i = " << i << "sum = " << sum[i] << endl;
	for(int i=0;i<=n;i++) to[i] = hash_find(sum[i]);
	LL l = mi,r = ma,mid;
	while(r - l > 1){
		mid = l + r >> 1;
		if(cal(n,mid) < K) r = mid;
		else l = mid;
	}
	if(cal(n,l) < K) return l;
	return r;
}
int main(){
	int n;
	LL K;
	top = 0;
	cin >> n >> K;
	for(int i=1;i<=n;i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
		num[++top] = sum[i];
	}
	num[++top] = 0;
	//num[++top] = mi - 1;
	//num[++top] = ma + 1;
	cout << solve(n,K) << endl;
	return 0;
}


