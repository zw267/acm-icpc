                                            
  //File Name: C.cpp
  //Created Time: 2017年03月22日 星期三 16时38分57秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 300000 + 5;
int a[MAXN],tot;
map<pii,int> h;
set<double> st[MAXN];
int gcd(int x,int y){
	return y == 0 ? x : gcd(y,x % y);
}
int main(){
	int tot = 1,n,aa,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d %d",&aa,&b,&c);
		if(b == 0) ++a[0];
		else{
			int g = gcd(abs(aa),abs(b));
			aa /= g,b /= g;
			if(aa < 0 && b < 0)
				aa = -aa,b = -b;
			if(!h.count(pii(aa,b)))
				h[pii(aa,b)] = tot++;
			st[h[pii(aa,b)]].insert(c);
		}
	}
	for(auto u:h)
		a[u.second] = st[u.second].size();
	if(!a[0])
		a[0] = a[--tot];
//	printf("tot = %d\n",tot);
	if(tot < 3){
		puts("0");
		return 0;
	}
	LL s1 = 0,s2 = 0;
	for(int i=0;i<tot;++i){
		s1 += a[i];
		s2 += 1LL * a[i] * a[i];
	}
	LL ans = 0;
	for(int i=0;i<tot;++i){
		LL u = 1LL * a[i] * a[i];
		LL v = 1LL * (s1 - a[i]) * (s1 - a[i]);
		LL tmp = v * a[i] - (LL)a[i] * (s2 - u);
		ans += tmp;
	}
	ans /= 6;
	printf("%lld\n",ans);
	return 0;
}
