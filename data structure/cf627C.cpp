                                            
  //File Name: cf627C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月06日 星期三 13时21分50秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

#define LL long long
#define p(i) node[(i)].p
#define x(i) node[(i)].x
#define id(i) node[(i)].id

using namespace std;

const int MAXN = 200000 + 3;
const int INF = 0x3f3f3f3f;

struct Node{
	int p,x,id;
	bool operator < (const Node & a) const{
		if(a.p == p)
			return a.x < x;
		return a.p < p;
	}
};
Node node[MAXN];

bool cmp(Node a,Node b){
	return a.x < b.x;
}

void solve(int dis,int n,int m){
	sort(node+1,node+m+1,cmp);
	for(int i=1;i<=m;i++)
		id(i) = i;
	m++;
	p(0) = INF,x(0) = 0,id(0) = 0;
	p(m) = 0,x(m) = dis,id(m) = m;
	LL ans = 0;
	int rest = n,pos = 0,point = 1;
	priority_queue<Node> que;
	while(!que.empty())
		que.pop();
	while(x(pos) < dis){
		while(!que.empty() && que.top().x <= x(pos))
			que.pop();
		while(point <= m && x(point) - x(pos) <= n){
			que.push(node[point]);
			point++;
			if(que.top().p <= p(pos))
				break;
		}
		if(que.empty())
			break;
		Node cur = que.top();
		if(cur.p <= p(pos)){
			if(cur.x - x(pos) <= rest){
				rest -= cur.x - x(pos);
				pos = cur.id;
			}
			else{
				ans += (LL)(cur.x - x(pos) - rest) * p(pos);
				rest = 0;
				pos = cur.id;
			}
		}
		else{
			ans += (LL)(n - rest) * p(pos);
			rest = n - cur.x + x(pos);
			pos = cur.id;
		}
	}
	if(x(pos) < dis)
		puts("-1");
	else
		cout << ans << endl;
	return ;
}

int main(){
	int dis,n,m;
	scanf("%d %d %d",&dis,&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x(i),&p(i));
	}
	solve(dis,n,m);
	return 0;
}
