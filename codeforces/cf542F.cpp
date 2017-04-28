                                            
  //File Name: cf542F.cpp
  //Created Time: 2017年04月28日 星期五 16时34分24秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100;
const LL INF = 1e18;
LL p2[MAXN];
vector<int> dep[MAXN];
void init(){
	p2[0] = 1;
	for(int i=1;i<MAXN;++i){
		if(i <= 60) p2[i] = p2[i - 1] * 2;
		else p2[i] = INF;
	}
}
bool cmp(int x,int y){
	return x > y;
}
int solve(int n){
	for(int i=MAXN-1;i>0;--i){
		LL sum = p2[i];
		sort(dep[i].begin(),dep[i].end(),cmp);
		int j(0),m = dep[i].size();
		for(;j+1<m && sum>=2;j+=2){
			dep[i-1].push_back(dep[i][j] + dep[i][j + 1]);
			sum -= 2;
		}
		if(j == m - 1 && sum >= 2)
			dep[i-1].push_back(dep[i][j]);
	}
	if(dep[0].size() == 0) return -1;
	sort(dep[0].begin(),dep[0].end(),cmp);
	return dep[0][0];
}
int main(){
	init();
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i(0),u,v;i<n;++i){
		scanf("%d %d",&u,&v);
		dep[t - u].push_back(v);
	}
	printf("%d\n",solve(n));
	return 0;
}
