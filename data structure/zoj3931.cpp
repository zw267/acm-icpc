                                            
  //File Name: zoj3931.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月16日 星期六 19时11分58秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

const int MAXN = 500;
const int NN = 128000 + 5;

struct Node{
	int w,l,r,id;
	Node(int _w = 0,int _l = 0,int _r = 0,int _id = 0){
		w = _w, l = _l, r = _r, id = _id;
	}
	bool operator <(const Node &x) const{
		return x.w < w;
	}
};

Node node[MAXN];
int ans,tot,root,N,sum;
int f[NN];
int a[130],b[130];
priority_queue<Node> que;

void build(int &E){
	Node x,y;
	while(que.size() > 1){
		x = que.top();
		que.pop();
		y = que.top();
		que.pop();
		a[N] = x.w;
		b[N] = y.w;
		sum += b[N] - a[N];
		N++;
		E -= x.w;
		node[++tot] = Node(x.w + y.w,x.id,y.id,tot);
		que.push(node[tot]);
	}
	root = que.top().id;
	return ;
}

void solve(int n){
	tot = ans = N = sum = 0;
	while(!que.empty())
		que.pop();
	for(int i=1,w;i<=n;i++){
		scanf("%d",&w);
		node[++tot] = Node(w,0,0,tot);
		que.push(node[tot]);
	}
	int E;
	scanf("%d",&E);
	build(E);
	if(E < 0 || E > sum){
		puts("No");
		return ;
	}
	memset(f,0,sizeof f);
	f[0] = 1;
	for(int i=0,now;i<N;i++){
		now = b[i] - a[i];
		for(int j=E;j>=now;j--){
			if(f[j - now])
				f[j] = 1;
		}
	}
	if(f[E])
		puts("Yes");
	else
		puts("No");
	return ;
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}


