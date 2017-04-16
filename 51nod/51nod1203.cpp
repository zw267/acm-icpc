                                            
  //File Name: 51nod1203.cpp
  //Created Time: 2017年04月14日 星期五 16时54分15秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 50000 + 5;
const int P = (int)1e9 + 7;
struct Que{
	int r,x,id,f;
	Que(){};
	Que(int _r,int _x,int _id,int _f):r(_r),x(_x),id(_id),f(_f){}
	bool operator<(const Que &a) const{
		return r < a.r;
	}
};
Que que[MAXN << 1];
vector<pii> dive[MAXN];
int a[MAXN],ans[MAXN],pre[MAXN];
LL bit[MAXN];
int prime[MAXN];
bool check[MAXN];
void init(){
	memset(check,false,sizeof check);
	int tot = 0;
	for(int i=2;i<MAXN;++i){
		if(!check[i])
			prime[tot++] = i;
		for(int j=0;j<tot && (LL)prime[j] * i < MAXN;++j){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i=2;i<=50000;++i){
		int x = i;
		for(int j=0;j<tot;++j){
			if((LL)prime[j] * prime[j] > x) break;
			if(x % prime[j] == 0){
				int num = 0;
				while(x % prime[j] == 0){
					++num;
					x /= prime[j];
				}
				dive[i].push_back(pii(prime[j],num));
			}
		}
		if(x > 1) dive[i].push_back(pii(x,1));
	}
//	for(auto now:dive[345]){
//		printf("p = %d num = %d\n",now.fir,now.sec);
//	}
}
void update(int x,int add,int n){
	for(;x<=n;x+=x&-x)
		bit[x] = bit[x] * add % P;
}
LL query(int x){
	LL res = 1;
	for(;x>0;x-=x&-x)
		res = res * bit[x] % P;
	return res;
}
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void solve(int n,int q){
	sort(que + 1,que + q + 1);
	for(int i=1;i<=50000;++i)
		pre[i] = bit[i] = ans[i] = 1;
	int cur = 2;
	for(int i=1;i<=q;++i){
		while(cur <= que[i].r){
			for(auto now:dive[a[cur]]){
				int p = now.fir,num = now.sec,sum = 1;
				for(int j=1;j<=num;++j){
					sum *= p;
					update(pre[sum],p,n);
					pre[sum] = cur;
				}
			}
			++cur;
		}
		LL tmp = query(que[i].x);
//		printf("r = %d tmp = %lld\n",que[i].r,tmp);
		int id = que[i].id;
		if(que[i].f == -1)
			ans[id] = ans[id] * qp(tmp,P - 2) % P;
		else
			ans[id] = ans[id] * tmp % P;
	}
}
int main(){
	init();
	int n,q;
	scanf("%d %d",&n,&q);
	++n;
	for(int i=2;i<=n;++i)
		scanf("%d",a + i);
	for(int i=1,l,r;i<=q;++i){
		scanf("%d %d",&l,&r);
		++l,++r;
		que[i] = Que(l - 1,l - 1,i,-1);
		que[i + q] = Que(r,l - 1,i,1);
	}
	solve(n,q + q);
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}
