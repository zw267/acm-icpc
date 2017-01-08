                                            
  //File Name: cf436E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月14日 星期三 15时19分55秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <stdlib.h>
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int MAXN = 300000 + 10;
const int INF = 2000000005;
struct Node{
	int a,b,id;
}node[MAXN];
int ans[MAXN];
set<pii> rema,remb;
void solve(int n,int w){
	LL res = 0LL;
	for(int i=1;i<=n;i++){
		rema.insert(mp(node[i].a,node[i].id));
		remb.insert(mp(node[i].b,node[i].id));
	}
	pii it1,it2,it3;
	while(w){
		if(w > 1 && !remb.empty() && rema.size() > 1){
			it1 = *rema.begin();
			rema.erase(it1);
			it2 = *rema.begin();
			rema.erase(it2);
			it3 = *remb.begin();
			if(it3.fir < it1.fir + it2.fir){
				remb.erase(it3);
				res += node[it3.sec].a;
				ans[it3.sec] = 1;
				w -= 1;
				rema.insert(it1);
				rema.insert(it2);
				rema.erase(mp(node[it3.sec].a,it3.sec));
				rema.insert(mp(node[it3.sec].b -node[it3.sec].a,it3.sec));
				continue;
			}
			rema.insert(it1);
			rema.insert(it2);
		}
		it1 = *rema.begin();
		rema.erase(it1);
		res += it1.fir;
		ans[it1.sec]++;
		w--;
		if(ans[it1.sec] == 1){
			remb.erase(mp(node[it1.sec].b,it1.sec));
			rema.insert(mp(node[it1.sec].b - node[it1.sec].a,it1.sec));
		}
	}
	cout << res << endl;
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	puts("");
}
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&node[i].a,&node[i].b);
		node[i].id = i;
	}
	solve(n,w);
	return 0;
}
