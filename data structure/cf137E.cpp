                                            
  //File Name: cf137E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年06月03日 星期五 13时52分54秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define left _left
#define hash _hash
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int MAXN = 200000 + 3;
const int INF = 0x3f3f3f3f;

char str[MAXN];
int sum[MAXN],b[MAXN];
int num[MAXN],hash[MAXN],tot,top;
int seg[MAXN << 2];
int left[MAXN];

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
		if(hash[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void build(int l,int r,int rt){
	seg[rt] = INF;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int p,int add,int l,int r,int rt){
	if(l == r){
		seg[rt] = min(seg[rt],add);
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) update(p,add,lson);
	else update(p,add,rson);
	seg[rt] = min(seg[rt<<1],seg[rt<<1|1]);
}

int query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r) 
		return seg[rt];
	int mid = (l + r) >> 1;
	int res = INF;
	if(L <= mid) res = min(res,query(L,R,lson));
	if(R > mid) res = min(res,query(L,R,rson));
	return res;
}

bool is(char ch){
	int now = ch - '0';
	if(now >= 17 && now <= 42) ch += 32;
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

void solve(){
	int n = strlen(str + 1);
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		if(is(str[i])) sum[i] = 1;
		else sum[i] = 0;
	}
	for(int i=1;i<=n;i++)
		sum[i] += sum[i-1];
	top = 0;
	for(int i=0;i<=n;i++){
		b[i] = 2 * i - 3 * sum[i];
		num[++top] = b[i];
	}
	hash_init();
	for(int i=0;i<=n;i++)
		b[i] = hash_find(b[i]);
	build(1,tot,1);
	update(b[0],0,1,tot,1);
	for(int i=1;i<=n;i++){
		left[i] = query(1,b[i],1,tot,1);
		update(b[i],i,1,tot,1);
	}
	int ans_len = -1;
	for(int i=1;i<=n;i++){
		ans_len = max(ans_len,i - left[i]);
	}
	if(ans_len == -1)
		puts("No solution");
	else{
		int ans_num = 0;
		for(int i=1;i<=n;i++){
			if(i - left[i] == ans_len)
				ans_num++;
		}
		printf("%d %d\n",ans_len,ans_num);
	}
}

int main(){
	//printf("%d %d %d %d\n",'A'-'0','Z'-'0','a'-'0','z'-'0');
	while(~scanf("%s",str+1)){
		solve();
	}
	return 0;
}
