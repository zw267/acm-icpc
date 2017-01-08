                                            
  //File Name: nod1290.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月16日 星期五 17时22分07秒
                                   
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define LL long long
#define hash _hash_
using namespace std;
const int MAXN = 50010;
int hash[MAXN * 3],num[MAXN * 3],top,tot;
void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] = num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}
int hash_find(int x){
	int l = 1,r = tot,m;	
	while(l <= r){
		m = l + r >> 1;
		if(hash[m] < x) l = m + 1;
		else r = m - 1;
	}	
	return l;
}
int a[MAXN],b[MAXN],c[MAXN],bel[MAXN],bit[MAXN * 3],cur_l,cur_r,K;
LL ans[MAXN],cur_ans;
struct Query{
	int ql,qr,id;
}que[MAXN];
bool cmp(Query x,Query y){
	if(bel[x.ql] == bel[y.ql]) return x.qr < y.qr;
	return bel[x.ql] < bel[y.ql];
}
void update(int x,int add){
	for(int i=x;i<=tot;i+=i&-i)
		bit[i] += add;
}
int query(int x){
	int res = 0;
	for(int i=x;i>0;i-=i&-i)
		res += bit[i];
	return res;
}
int cal(int u){
	return query(c[u]) - query(b[u] - 1);
}
void update_l(int to_l){
	while(cur_l < to_l){
		update(a[cur_l],-1);
		cur_ans -= cal(cur_l);
		cur_l++;
	}
	while(cur_l > to_l){
		cur_l--;
		cur_ans += cal(cur_l);
		update(a[cur_l],1);
	}
}
void update_r(int to_r){
	while(cur_r < to_r){
		cur_r++;
		cur_ans += cal(cur_r);
		update(a[cur_r],1);
	}
	while(cur_r > to_r){
		update(a[cur_r],-1);
		cur_ans -= cal(cur_r);
		cur_r--;
	}
}
void solve(int n,int q){
	hash_init();
	for(int i=1;i<=n;i++){
		b[i] = hash_find(a[i] - K);
		c[i] = hash_find(a[i] + K);
		a[i] = hash_find(a[i]);
	}
	memset(ans,0,sizeof ans);
	int NUM = (int)sqrt(n + 0.5);
	for(int i=1;i<=n;i++) 
		bel[i] = (i - 1) / NUM;
	sort(que+1,que+q+1,cmp);
	memset(bit,0,sizeof bit);
	update(a[1],1);
	cur_l = cur_r = 1;
	cur_ans = 0;
	for(int i=1;i<=q;i++){
		update_r(que[i].qr);
		update_l(que[i].ql);
		ans[que[i].id] = cur_ans;
	}
}
int main(){
	int n,q;
	while(~scanf("%d %d %d",&n,&K,&q)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",a + i);
			num[++top] = a[i];
			num[++top] = a[i] - K;
			num[++top] = a[i] + K;
		}
		for(int i=1;i<=q;i++){
			scanf("%d %d",&que[i].ql,&que[i].qr);
			que[i].ql++,que[i].qr++,que[i].id = i;
		}
		solve(n,q);
		for(int i=1;i<=q;i++)
			printf("%lld\n",ans[i]);
	}
	return 0;
}
