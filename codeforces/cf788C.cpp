                                          
  //File Name: cf788C.cpp
  //Created Time: 2017年04月21日 星期五 15时23分39秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2000 + 5;
const int BASE = 1000;
const int INF = 0x3f3f3f3f;
int can[MAXN];
set<int> rem;
vector<int> a;
queue<int> que;
void solve(int n){
	for(int i=0;i<MAXN;++i)
		can[i] = INF;
	for(auto u:rem){
		a.push_back(u - n);
		can[u - n + BASE] = 1;
		que.push(u - n);
	}
	while(!que.empty()){
		int u = que.front();
		que.pop();
		if(u == 0) break;
		for(auto v:a){
			if(u +  v < 0 || u + v > BASE) continue;
			if(can[u + v + BASE] > can[u + BASE] + 1){
				can[u + v + BASE] = can[u + BASE] + 1;
				que.push(u + v);
			}
		}
	}
}
int main(){	
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1,u;i<=m;++i){
		scanf("%d",&u);
		rem.insert(u);
	}
	solve(n);
	if(can[BASE] >= INF) can[BASE] = -1;
	printf("%d\n",can[BASE]);
	return 0;
}
