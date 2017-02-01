                                          
  //File Name: 51nod1195.cpp
  //Created Time: 2017年02月01日 星期三 16时09分39秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 100000;
const int N = 10000000;
bool check[MAXN];
int prime[MAXN],tot,P;
int rem[N] = {0,0,3,8,0,20};
struct matrix_t{
	LL x[3][3];
	matrix_t(int v = 0){
		memset(x,0,sizeof(x));
		x[1][1] = x[2][2] = v;
	}
	bool operator == (const matrix_t &a) const{
		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				if(x[i][j] != a.x[i][j])
					return false;
		return true;
	}
	matrix_t operator * (const matrix_t &a) const{
		matrix_t res(0);
		for(int i=1;i<=2;++i){
			for(int j=1;j<=2;++j){
				for(int k=1;k<=2;++k)
					res.x[i][j] += x[i][k] * a.x[k][j];
					res.x[i][j] %= P;
			}
		}
		return res;
	}
	matrix_t pow(int y) const{
		matrix_t res(1),x = *this;
		for(;y>0;y>>=1){
			if(y & 1) res = res * x;
			x = x * x;
		}
		return res;
	}
}A(0),I(1);
void init(){
	memset(check,false,sizeof(check));
	tot = 0;
	for(int i=2;i<MAXN;++i){
		if(!check[i])
			prime[tot++] = i;
		for(int j=0;j<tot&&(LL)prime[j]*i<MAXN;++j){
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	A.x[1][1] = A.x[1][2] = A.x[2][1] = 1;
}
LL qp(LL x,LL y,LL p){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % p;
		x = x * x % p;
	}
	return res;
}
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x % y);
}
int cal(const int p){
	if(p < N && rem[p]) return rem[p];
	LL res,n;
	P = p;
	if(qp(5,p - 1 >> 1,p) == 1) 
		res = n = p - 1;
	else
		res = n = (p + 1) * 2;
	for(int i=0;i<tot && (LL)prime[i]*prime[i]<=n;++i){
		if(n % prime[i] == 0){
			while(res % prime[i] == 0 && A.pow(res / prime[i]) == I)
				res /= prime[i];
			while(n % prime[i] == 0)
				n /= prime[i];
		}
	}
	if(n > 1 && res % n == 0 && A.pow(res / n) == I)
		res /= n;
	if(p < N) 
		rem[p] = res;
	return res;
}
LL solve(int n){
	LL res = 1,tmp;
	for(int i=0;i<tot && prime[i]*prime[i]<=n;++i){
		if(n % prime[i] == 0){
			tmp = cal(prime[i]);
			n /= prime[i];
			while(n % prime[i] == 0){
				n /= prime[i];
				tmp *= prime[i];
			}
			res = res / gcd(res,tmp) * tmp;
		}
	}	
	if(n > 1){
		tmp = cal(n);
		res = res / gcd(res,tmp) * tmp;
	}
	return res;	
}
int main(){
	init();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}
