                                            
  //File Name: cf777E.cpp
  //Created Time: 2017年03月23日 星期四 17时32分03秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
struct Node{
	LL a,b,h;
	Node(){}
	Node(LL _a,LL _b,LL _h):a(_a),b(_b),h(_h){}
	bool operator<(const Node& u) const{
		if(b == u.b) return a < u.a;
		else return b > u.b;
	}
};
Node node[MAXN],tmp[MAXN];
multiset<pll> seta;
multiset<LL> setf;
LL f[MAXN];
LL solve(int tot){
	sort(tmp + 1,tmp + tot + 1);
	int n = 0;
	for(int i=1;i<=tot;++i){
		if(tmp[i].b == tmp[i - 1].b)
			node[n].h += tmp[i].h;
		else
			node[++n] = tmp[i];
	}
//	for(int i=1;i<=n;++i)
//		printf("%lld %lld %lld\n",node[i].a,node[i].b,node[i].h);
	seta.insert(pll(0,0));
	setf.insert(0);
	for(int i=1;i<=n;++i){
		while((!seta.empty()) && -(seta.begin()->fir) >= node[i].b){
			auto u = *seta.begin();
			seta.erase(seta.begin());
			auto it = setf.find(u.sec);
			setf.erase(it);
		}
		f[i] = (*setf.rbegin()) + node[i].h;
//		printf("i = %d f = %lld\n",i,f[i]);
		seta.insert(pll(-node[i].a,f[i]));
		setf.insert(f[i]);
	}
	LL res = 0;
	for(int i=1;i<=n;++i)
		res = max(res,f[i]);
	return res;
}
int main(){
	int m;
	LL a,b,h;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%lld %lld %lld",&a,&b,&h);
		tmp[i] = Node(a,b,h);
	}
	printf("%lld\n",solve(m));
	return 0;
}
