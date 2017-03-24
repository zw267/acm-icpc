                                            
  //File Name: cf785E.cpp
  //Created Time: 2017年03月24日 星期五 23时32分54秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
const int N = 500;
int p[MAXN],b[MAXN];
//在[L,R]中查找x，改为y，再重新排序
void update(int L,int R,int x,int y){
	int pos = lower_bound(b + L,b + R + 1,x) - (b + L);
	if(b[L + pos] != x) while(1);
	b[L + pos] = y;
//	bool flag = false;
//	for(int i=L;i<=R;++i){
//		if(b[i] == x){
//			b[i] = y;
//			flag = true;
//			break;
//		}
//	}
//	if(!flag) while(1);
	sort(b + L,b + R + 1);
}
int query_same(int x,int L,int R){
	int res = 0;
	for(int i=L;i<=R;++i)
		res += (x > p[i]);
	return res;
}
//在[L,R]中查找比x小的数的个数
int query(int x,int L,int R,int n){
	if(L > R) 
		return 0;
	if(L / N == R / N)
		return query_same(x,L,R);
	int res = 0;
	res += query_same(x,L,L / N * N + N - 1);
	res += query_same(x,R / N * N,R);
	for(int i = L / N * N + N;i < R / N * N;i += N){
		int tmp;
		if(b[i + N - 1] < x) tmp = N;
		else tmp = lower_bound(b + i,b + i + N,x) - (b + i);
		res += tmp;
	}
	return res;
}
void solve(int n,int q){
	LL ans = 0;
	while(q--){
		int l,r,u,v;
		scanf("%d %d",&l,&r);
		--l,--r;
		if(l > r) swap(l,r);
		u = query(p[l],l + 1,r - 1,n);
		v = query(p[r],l + 1,r - 1,n);
//		printf("l = %d r = %d u = %d v = %d\n",l,r,u,v);
		ans= ans + 2 * v - 2 * u;
		if(p[l] < p[r]) ++ans;
		else if(p[l] > p[r]) --ans;
		printf("%lld\n",ans);
		if(l / N != r / N){
			update(l / N * N,min(l / N * N + N - 1,n),p[l],p[r]);
			update(r / N * N,min(r / N * N + N - 1,n),p[r],p[l]);
		}
		swap(p[l],p[r]);
//		for(int i=0;i<n;++i)
//			printf("%d ",p[i]);
//		puts("");
	}
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i)
		p[i] = b[i] = i;
	solve(n,q);
	return 0;
}
