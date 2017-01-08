                                            
  //File Name: cf45C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月21日 星期四 23时04分34秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>

#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 200000 + 3;

struct Node{
	int l,r,dif;
	Node(int _l = 0,int _r = 0,int _dif = 0){
		l = _l,r = _r,dif = _dif;
	}
	bool operator < (const Node &a)const{
		if(a.dif == dif)
			return a.l < l;
		return a.dif < dif;
	}
};
priority_queue<Node> que;
int a[MAXN];
int is[MAXN];
int L[MAXN];
int R[MAXN];
int use[MAXN];
pair<int,int> ans[MAXN];
char ch[MAXN];

inline int fab(int x,int y){
	if(x > y)
		return x - y;
	return y - x;
}

void solve(int n){
	int tot = 0;
	for(int i=1;i<=n;i++){
		L[i] = i - 1;
		R[i] = i + 1;
	}
	while(!que.empty())
		que.pop();
	memset(use,0,sizeof use);
	Node now;
	for(int i=1;i<n;i++){
		if(is[i] + is[i + 1] == 1){
			now = Node(i,i + 1,fab(a[i],a[i + 1]));
			que.push(now);
		}
	}
	while(!que.empty()){
		now = que.top();
		que.pop();
		if(!use[now.l] && !use[now.r]){
			ans[tot++] = mp(now.l,now.r);
			use[now.l] = use[now.r] = 1;
			while(use[L[now.l]]){
				L[now.l] = L[L[now.l]];
			}
			L[now.r] = L[now.l];
			while(use[R[now.r]]){
				R[now.r] = R[R[now.r]];
			}
			R[now.l] = R[now.r];
			if(L[now.l] == 0 || R[now.r] == n + 1)
				continue;
			if(is[L[now.l]] + is[R[now.r]] != 1)
				continue;
			now = Node(L[now.l],R[now.r],fab(a[L[now.l]],a[R[now.r]]));
			que.push(now);
		}
	}
	printf("%d\n",tot);
	for(int i=0;i<tot;i++){
		printf("%d %d\n",ans[i].fir,ans[i].sec);
	}
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",ch + 1);
	memset(is,0,sizeof is);
	for(int i=1;i<=n;i++){
		if(ch[i] == 'B')
			is[i] = 1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
