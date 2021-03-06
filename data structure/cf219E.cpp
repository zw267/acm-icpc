                                            
  //File Name: cf219E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年08月05日 星期五 14时01分16秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#define LL long long
using namespace std;

const int MAXN = 200000 + 3;
int n;
struct Node{
	int l,r,v;
	bool operator < (const Node& b)const{
		if(v == b.v) return l < b.l;
		return v > b.v;
	}
	Node(){}
	Node(int _l,int _r,int _v){
		l = _l,r = _r,v = _v;
	}
};
Node cal(int l,int r){
	if(l == 0 && r == n + 1)
		return Node(l,r,n);
	if(l == 0) 
		return Node(l,r,r-1);
	if(r == n + 1)
		return Node(l,r,n-l);
	return Node(l,r,(r - l) >> 1);
}
void solve(){
	int m;
	scanf("%d %d",&n,&m);
	set<int> pos;
	set<Node>st;
	map<int,int> mp;
	pos.insert(0);
	pos.insert(n+1);
	st.insert(cal(0,n+1));
	Node now;
	for(int i=0,op,id,p;i<m;i++){
		scanf("%d %d",&op,&id);
		if(op == 1){
			set<Node>::iterator it = st.begin();
			st.erase(it);
			now = *it;
			if(now.l == 0) p = 1;
			else if(now.r == n + 1) p = n;
			else p = (now.l + now.r) >> 1;
			st.insert(cal(now.l,p));
			st.insert(cal(p,now.r));
			pos.insert(p);
			mp[id] = p;
			printf("%d\n",p);
		}
		else{
			p = mp[id];
			set<int>::iterator it = pos.find(p);
			set<int>::iterator prev = (--it)++;
			set<int>::iterator next = (++it)--;
			st.erase(cal(*prev,p));
			st.erase(cal(p,*next));
			st.insert(cal(*prev,*next));
			pos.erase(it);
			mp.erase(id);
		}
	}	
}
int main(){
	solve();
	return 0;
}

