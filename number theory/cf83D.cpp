                                            
  //File Name: cf83D.cpp
  //Created Time: 2017年01月04日 星期三 22时48分56秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 30000000 + 1;
bool check[MAXN];
int prime[2000000],fir[MAXN],tot;
LL ans,n;
int ma;
void init(){
	tot = 0;
	memset(check,false,sizeof(check));
	for(int i=2;i<MAXN;++i){
		if(!check[i]){
			prime[tot++] = i;
			fir[i] = i;
		}
		for(int j=0;j<tot;++j){
			if((LL)i * prime[j] >= MAXN) break;
			check[i * prime[j]] = true;
			fir[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
//	printf("tot = %d\n",tot);
}
bool is_prime(LL k){
	if(k < MAXN)
		return fir[k] == k;
	for(int i=0;i<tot;++i){
		if(1LL * prime[i] * prime[i] > k) break;
		if(k % prime[i] == 0) return false;
	}
	return true;
}
void dfs(int p,LL now,LL f){
	if(now > n) return ;
	if(p > ma){
		ans += f * (n / now);
		return ;
	}
	dfs(p+1,now,f);
	dfs(p+1,now * prime[p],-f);
}
LL cal(LL r,LL k){
	ans = 0;
	n = r / k;
	if(n < MAXN){
		for(int i=1;i<=n;++i){
			if(i == 1 || fir[i] >= k) 
				++ans;
		}
		return ans;
	}
	else{
		ma = 0;
		for(;ma<tot;++ma){
			if(prime[ma] == k)
				break;
		}
		--ma;
		dfs(0,1,1);
		return ans;
	}
}
LL solve(LL l,LL r,LL k){
	if(!is_prime(k)) return 0;
	return cal(r,k) - cal(l - 1,k);
}
int main(){
	init();
//	while(cin >> n){
//		cout << fir[n] << endl;
//	}
	LL l,r,k;
	cin >> l >> r >> k;
	cout << solve(l,r,k) << endl;
	return 0;
}
