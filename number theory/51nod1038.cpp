                                            
  //File Name: 51nod1038.cpp
  //Created Time: 2017年01月31日 星期二 21时16分24秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000;
int ans[100000];
struct Edge{
	int to,w,next;
}edge[MAXN];
int head[MAXN],top;
void ins(int x,int y){
	int k = x % MAXN;
	edge[top].to = x,edge[top].w = y,edge[top].next = head[k];
	head[k] = top++;
}
int query(int x){
	int k = x % MAXN;
	for(int i=head[k];i!=-1;i=edge[i].next){
		if(edge[i].to == x)
			return edge[i].w;
	}
	return -1;
}
LL qp(LL x,LL y,LL p){
	x %= p;
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
int primitive_root(int p){
	vector<int> fact;
	int tmp = p - 1;
	for(int i=2;i*i<=tmp;++i){
		if(tmp % i == 0){
			fact.push_back(i);
			while(tmp % i == 0)
				tmp /= i;
		}
	}
	if(tmp > 1) fact.push_back(tmp);
	for(int root=1;;++root){
		bool flag = true;
		for(int i=0;i<fact.size();++i){
			if(qp(root,(p-1)/fact[i],p) == 1){
				flag = false;
				break;
			}
		}
		if(flag) return root;
	}
}
LL ext_gcd(LL a,LL b,LL &x,LL &y){
	if(a == 0 && b == 0) return -1;
	if(!b){
		x = 1,y = 0;
		return a;
	}
	LL d = ext_gcd(b,a % b,y,x);
	y -= a / b * x;
	return d;
}
LL inv(LL a,LL n){
	LL x,y;
	LL d = ext_gcd(a,n,x,y);
	if(d == 1) return (x % n + n) % n;
	else return -1;
}
LL bsgs(LL a,LL b,LL p){
	if(b == 1) return 0;
	memset(head,-1,sizeof(head));
	top = 0;
	LL u = 1,v = 1;
	LL m = (int)ceil((double)sqrt(p + 0.0));
	for(int i=0;i<m;++i){
		LL tmp = b * u % p;
		ins(tmp,i);
		u = u * a % p;
	}
	for(int i=m,j;;i+=m){
		v = v * u % p;
		if((j = query(v)) != -1)
			return i - j;
		if(i > p) break;
	}
	return -1;
}
int solve(LL a,LL b,LL p){
	int tot = 0;
	LL g = primitive_root(p);
	LL v = bsgs(g,b,p);
	LL m = p - 1;
	LL x,y;
	LL d = ext_gcd(a,m,x,y);
	if(v % d) return 0;
	a /= d,v /= d,m /= d;
	LL u = v * inv(a,m) % m;
	u = qp(g,u,p);
	LL tmp = qp(g,m,p);
	LL now = 1;
	for(int i=0;i<d;++i){
		ans[tot++] = u * now % p;
		now = now * tmp % p;
	}
	sort(ans,ans + tot);
	return tot;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		LL a,b,p;
		scanf("%lld %lld %lld",&p,&a,&b);
		int tot = solve(a,b,p);
		if(!tot)
			puts("No Solution");
		else{
			for(int i=0;i<tot;++i)
				printf("%d%c",ans[i],i == tot - 1 ? '\n':' ');
		}
	}
	return 0;
}
