                                            
  //File Name: cf660F.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月04日 星期日 12时37分42秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
const int MAXN = 200000 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int a[MAXN],K[MAXN],st[MAXN<<2],en[MAXN<<2],q[MAXN * 20],top,tmp[MAXN];
LL s[MAXN],sum[MAXN],B[MAXN],X,res;
LL pos(int x,int y){
	return (B[y] - B[x]) / (K[x] - K[y]);
}
bool cmp(int x,int y){
	if(K[x] == K[y]) return B[x] < B[y];
	return K[x] > K[y];
}
void build(int l,int r,int rt){
	st[rt] = top;
	int t = 0;
	for(int i=l;i<=r;i++) tmp[t++] = i;
	sort(tmp,tmp+t,cmp);
	q[top++] = tmp[0];
	for(int i=1;i<t;i++){
		if(K[i] != K[i-1]){
			while(top-2>= st[rt] && pos(q[top-2],tmp[i])<=pos(q[top-1],q[top-2]))
				--top;
			q[top++] = tmp[i];
		}
	}
	en[rt] = top - 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}
LL cal(int l,int r){
	int mid,t = l++;
	while(l <= r){
		mid = (l + r) >> 1;
		if(pos(q[mid],q[mid-1]) <= X) 
			l = (t = mid) + 1;
		else 
			r = mid - 1;
	}
	return K[q[t]] * X + B[q[t]];
}
void query(int L,int R,int l,int r,int rt){
	if(L <= l && R >= r){
		res = min(res,cal(st[rt],en[rt]));
		return ;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) query(L,R,lson);
	if(R > mid) query(L,R,rson);
}
LL solve(int n){
	build(1,n,1);	
	LL ans = 0;	
	for(int i=1;i<=n;i++){
		res = INF,X = s[i];
		query(1,i,1,n,1);
		res = min(res,0LL);
		//printf("i = %d  %lld  %lld\n",i,res,sum[i]-res);
		ans = max(ans,sum[i] - res);
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i] = s[i-1] + a[i];
		sum[i] = sum[i-1] + 1LL * a[i] * i;
		K[i] = i;
		B[i] = sum[i] - 1LL * s[i] * i;
	}
	cout << solve(n) << endl;
	return 0;
}
