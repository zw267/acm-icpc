                                            
  //File Name: cf594D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月20日 星期二 17时59分06秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 200000 + 5;
const int N = 1000000 + 5;
const int P = (int)1e9 + 7;
int prime[N / 2],fir[N],pre[N / 2],tot,node_tot;
LL inv[N / 2],ans[MAXN],bit[MAXN],pre_sum[MAXN];
int a[MAXN];
struct Query{
	int l,r,t;
	bool operator < (const Query & a) const{
		if(l == a.l) return r < a.r;
		return l < a.l;
	}
}que[MAXN];
struct Node{
	int pre,p,pos;
	Node(){}
	Node(int _pre,int _p,int _pos){
		pre = _pre,p = _p,pos = _pos;
	}
	bool operator < (const Node & a) const{
		if(pre == a.pre) return pos < a.pos;
		return pre < a.pre;
	}
}node[N << 1];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	memset(fir,-1,sizeof(fir));
	tot = 0;
	for(int i=2;i<N;++i){
		if(fir[i] == -1){
			prime[tot++] = i;
			fir[i] = tot - 1;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] >= N) break;
			fir[i * prime[j]] = j;
			if(i % prime[j] == 0) break;
		}
	}
//	for(int i=0;i<10;++i)
//		printf("%d\n",prime[i]);
	for(int i=0;i<tot;++i)
		inv[i] = qp(prime[i],P - 2),pre[i] = 0;
}
void cal(int x,int i){
	while(x > 1){
		int id = fir[x];
		int p = prime[id];
		node[node_tot++] = Node(pre[id],id,i);
		pre[id] = i;
		while(x % p == 0)
			x /= p;
	}
}
void update(int p,LL x,int n){
	for(;p<=n;p+=p&-p)
		bit[p] = bit[p] * x % P;
}
LL query(int p){
	LL res = 1;
	for(;p>0;p-=p&-p)
		res = res * bit[p] % P;
	return res;
}
void solve(int n,int q){
	sort(que+1,que+q+1);
	pre_sum[0] = 1;
	for(int i=1;i<=n;++i)
		pre_sum[i] = pre_sum[i - 1] * a[i] % P;
	for(int i=1;i<=n;++i)
		bit[i] = 1;
	node_tot = 0;
	for(int i=1;i<=n;++i)
		cal(a[i],i);	
	sort(node,node+node_tot);
	int u = 0;
	for(int i=1;i<=q;++i){
		while(u < node_tot && node[u].pre < que[i].l){
			int id = node[u].p;
			update(node[u].pos,(prime[id] - 1) * inv[id] % P,n);
			++u;
		}
		ans[que[i].t] = query(que[i].r) * qp(query(que[i].l-1),P-2) % P;
	}
	for(int i=1;i<=q;++i){
		ans[que[i].t] = pre_sum[que[i].r] * qp(pre_sum[que[i].l-1],P-2) % P * ans[que[i].t] % P;
	}
}
int main(){
	init();
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a + i);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d %d",&que[i].l,&que[i].r);
		que[i].t = i;
	}
	solve(n,q);
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}
