                                            
  //File Name: nod1317.cpp
  //Created Time: 2017年01月11日 星期三 22时07分29秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int P = (int)1e9 + 7;
int p[1000],tot_p;
int dive[10000],tot_dive;
LL now;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void cal_dive(int n){
	tot_dive = 0;
	int ma = (int)sqrt(n + 0.5);
	for(int i=1;i<=ma;++i){
		if(n % i == 0){
			dive[tot_dive++] = i;
			if(n / i != i)
				dive[tot_dive++] = n / i;
		}
	}
	sort(dive,dive+tot_dive);
//	printf("tot_dive = %d\n",tot_dive);
}
void cal_fact(int n){
	tot_p = 0;
	int ma = (int)sqrt(n + 0.5);
	for(int i=2;i<=ma;++i){
		if(n % i == 0){
			p[tot_p++] = i;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1)
		p[tot_p++] = n;
//	printf("tot_p = %d\n",tot_p);
}
void dfs(int pos,int d,int u){
	if(pos == tot_p){
		now += d * u % P;
		now = (now + P) % P;
		return ;
	}
	dfs(pos+1,d,u);
	dfs(pos+1,d * p[pos],-u);
}
LL solve(int n,int A){
	LL res = 0;
	cal_dive(n);
	for(int i=0;i<tot_dive;++i){
		LL k = dive[i];
		LL tmp = qp(A,k) * k % P;
//		printf("n / k == %d\n",n / k);
		cal_fact(n / k);
		now = 0;
		dfs(0,1,1);
		tmp = tmp * now % P;
		res = (res + tmp + P) % P;
	}
	return res;
}
int main(){
	int n,A;
	cin >> n >> A;
	cout << solve(n,A) << endl;
	return 0;
}
 
