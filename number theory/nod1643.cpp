                                            
  //File Name: nod1643.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月22日 星期四 17时15分27秒
                                   
#include <bits/stdc++.h>
#define LL long long
const int MAXN = 10000000 + 1;
const int N = 664579 + 1;
const int P = (int)1e9 + 7;
int fir[MAXN],prime[MAXN],num[MAXN];
LL g,m,x,a,b,c;
int tot,C;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1){
		   	res = res * x;
			if(res >= P)
				res %= P;
		}
		x = x * x;
		if(x >= P) x %= P;
	}
	return res;
}
void init(){
	memset(fir,-1,sizeof(fir));
	tot = 0;
	for(int i=2,j;i<MAXN;++i){
		if(fir[i] == -1){
			prime[tot++] = i;
			fir[i] = tot - 1;
		}
		for(j=0;j<tot;++j){
			if((LL)i * prime[j] >= MAXN) break;
			fir[i * prime[j]] = j;
			if(i % prime[j] == 0) break;
		}
	}
}
void cal_num(){
//	memset(prime,0,sizeof(prime));
	prime[x] = 1,num[x] = 1,fir[1] = x;
	C = x;
	g *= x;
	LL l = 0,r = 0,len = 1;
	for(LL i=2;i<=m;++i){
		x = (a * x + b) % c + 1;
		if(x > C) C = x;
//		printf("i = %d x = %lld\n",i,x);
		if(!prime[x]){
			++num[x];
			prime[x] = i;
			fir[i] = x;
			g = g * x;
			if(g >= P) g %= P;
		}
		else{
			l = prime[x],r = i;
			len = r - l;
			break;
		}
	}
	if(r){
		int rest = (m - r + 1) % len + l - 1;
		LL dive = (m - r + 1) / len;
		LL u = 1,v = 1,w = dive % P,tmp;
		for(LL i=l,now;i<r;++i){
			now = w;
			v = fir[i];
			u = u * v;
			if(u >= P) u %= P;
			if(i <= rest){
		   		++now;
				g = g * v;
				if(g >= P) g %= P;
			}
			tmp = num[v] + now;
			if(tmp >= P) tmp -= P;
			num[v] = tmp;
		}
		g = g * qp(u,dive);
		if(g >= P) g %= P;
	}
}
void cal_sum(LL c){
	for(LL i=c,id,p,u;i>1;--i){
		if(!num[i]) continue;
		if(prime[fir[i]] == i){
			g = g * (num[i] + 1LL);
			if(g >= P) g %= P;
		}
		else{
			id = fir[i];
			p = prime[id];
			u = num[p] + num[i];
			if(u >= P) u -= P;
			num[p] = u;
			u = num[i / p] + num[i];
			if(u >= P) u -= P;
			num[i / p] = u;
		}
	}
}
void solve(){
	g = 1;
	cal_num();
	init();
	cal_sum(C);
}
int main(){
	scanf("%lld %lld %lld %lld %lld",&m,&x,&a,&b,&c);
	solve();
	printf("%lld\n",g);
	return 0;
}
