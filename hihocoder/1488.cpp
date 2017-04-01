                                            
  //File Name: 1488.cpp
  //Created Time: 2017年04月01日 星期六 21时41分02秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 20000;
const int N = 200;
int bit[MAXN + 3];
int bit2[MAXN + 3];
int a[MAXN + 3];
LL ans[MAXN + 3];
LL cur_ans;
int cur_l,cur_r;
struct Node{
	int l,r,id;
	bool operator <(const Node &a) const{
		if((l - 1) / N == (a.l - 1) / N) 
			return r < a.r;
		return (l - 1) / N < (a.l - 1) / N;
	}
};
Node que[MAXN + 3];
int query(int x,int *bit){
	int res = 0;
	for(;x;x-=x&-x)
		res += bit[x];
	return res;
}
void update(int x,int add,int *bit){
	for(;x<=MAXN;x+=x&-x)
		bit[x] += add;
}
void update_r(const int r){
	while(cur_r < r){
		++cur_r;
		int more = query(MAXN,bit) - query(a[cur_r] - 1,bit);
	   	cur_ans += (LL)(more + 1) * a[cur_r] + query(a[cur_r] - 1,bit2);
		update(a[cur_r],1,bit);
		update(a[cur_r],a[cur_r],bit2);
	}
	while(cur_r > r){
		int more = query(MAXN,bit)- query(a[cur_r] - 1,bit);
		cur_ans -= (LL)more * a[cur_r] + query(a[cur_r] - 1,bit2);
		update(a[cur_r],-1,bit);
		update(a[cur_r],-a[cur_r],bit2);
		--cur_r;
	}
}
void update_l(const int l){
	while(cur_l < l){
		int more = query(MAXN,bit) - query(a[cur_l] - 1,bit);
		cur_ans -= (LL)more * a[cur_l] + query(a[cur_l] - 1,bit2);
		update(a[cur_l],-1,bit);
		update(a[cur_l],-a[cur_l],bit2);
		++cur_l;
	}
	while(cur_l > l){
		--cur_l;
		int more = query(MAXN,bit) - query(a[cur_l] - 1,bit);
		cur_ans += (LL)(more + 1) * a[cur_l] + query(a[cur_l] - 1,bit2);
		update(a[cur_l],1,bit);
		update(a[cur_l],a[cur_l],bit2);
	}
}
void solve(int n,int m){
	memset(bit,0,sizeof(bit));
	memset(bit2,0,sizeof(bit2));
	sort(que + 1,que + m + 1);
	cur_ans = a[1],cur_l = cur_r = 1;
	update(a[1],1,bit);
	update(a[1],a[1],bit2);
	for(int i=1;i<=m;++i){
		update_r(que[i].r);
		update_l(que[i].l);
//		printf("l = %d r = %d bit = %d\n",cur_l,cur_r,query(MAXN,bit));
//		printf("bit2 = %d\n",query(MAXN,bit2));
		ans[que[i].id] = cur_ans;
	}
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",a + i);
		for(int i=1;i<=m;++i){
			scanf("%d %d",&que[i].l,&que[i].r);
			if(que[i].l > que[i].r)
				swap(que[i].l,que[i].r);
			que[i].id = i;
		}
		solve(n,m);
		for(int i=1;i<=m;++i)
			printf("%lld\n",ans[i]);
	}
	return 0;
}
