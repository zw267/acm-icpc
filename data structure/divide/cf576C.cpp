                                            
  //File Name: cf576C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月17日 星期四 11时56分06秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000000 + 1;
const int N = 1000;
struct Node{
	int x,y,t;
	bool operator<(const Node & a) const{
		return y < a.y;
	}
}node[MAXN];
vector<Node> bel[N + 2];
int ans[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&node[i].x,&node[i].y);
		node[i].t = i;
		bel[node[i].x / N].push_back(node[i]);
	}
	bool dir = 0;
	for(int i=0;i<=N;i++){
		if(!bel[i].size()) continue;
		sort(bel[i].begin(),bel[i].end());
		if(!dir){
			for(int j=0;j<bel[i].size();j++)
				printf("%d ",bel[i][j].t);
		}
		else{
			for(int j=bel[i].size()-1;j>=0;j--)
				printf("%d ",bel[i][j].t);
		}
		dir ^= 1;
	}
	return 0;
}
