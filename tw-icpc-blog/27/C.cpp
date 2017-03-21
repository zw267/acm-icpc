                                            
  //File Name: C.cpp
  //Created Time: 2017年03月21日 星期二 15时36分51秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define fir first
#define sec second
using namespace std;
const LL NA = 100000000000000007;
const int MAXN = 100000 + 3;
set<pair<LL,int>> rem;
LL add[333400],r[MAXN];
vector<pair<LL,int>> que[333400];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",r + i);
		if(i > 1)
			rem.insert(pair<LL,int>(r[i],i));
	}
	for(int i=1,num,p,d;i<=m;++i){
		scanf("%d",&num);
		while(num--){
			scanf("%d %d",&p,&d);
			if(p == 1) add[i] = d;
			else que[i].push_back(pair<LL,int>(d,p));
		}
	}
	for(int i=0;i<=m;++i){
		r[1] += add[i];
		for(auto u:que[i]){
			if(r[u.sec] == NA) continue;
			rem.erase(pair<LL,int>(r[u.sec],u.sec));
			r[u.sec] += u.fir;
			rem.insert(pair<LL,int>(r[u.sec],u.sec));
		}
		while(!rem.empty()){
			auto u = *rem.begin();
			if(u.fir < r[1]){
				r[u.sec] = NA;
				rem.erase(rem.begin());
			}
			else
				break;
		}
//		printf("i = %d size = %d\n",i,rem.size());
	}
	printf("%d\n",rem.size());
	return 0;
}
