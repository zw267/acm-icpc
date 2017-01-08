                                            
  //File Name: nod1208.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年09月16日 星期五 20时11分21秒
                                   
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <set>
#define hash _hash_
using namespace std;
const int MAXN = 50000 + 10;
int bit[MAXN*2],W,H,n;
int hash[MAXN*2]num[MAXN*2],tot,top;
struct Node{
	int x,y,v;
	bool operator<(const Node&a)const{
		if(x == a.x) return y > a.y;
		return x > a.x;
	}
}node[MAXN];
void update(int x,int add){
	for(int i=x;i<=tot;i+=i&-i)
		bit[i] += add;
}
int query(int x){
	int res = 0;
	for(int i=x;i>0;i-=i&-i)
		res += bit[i];
	return res;
}
void hash_init(){
	sort(num+1,num+top+1);
	tot = 0;
	hash[++tot] =  num[1];
	for(int i=2;i<=top;i++)
		if(num[i] != num[i-1])
			hash[++tot] = num[i];
}
int hash_find(int x){
	int l = 1,r = tot,m;
	while(l <= r){
		m = l + r >> 1;
		if(hash[m] < x) l = m + 1;
		else r = m - 1;
	}
	return l;
}
int solve(){
	hash_init();
	memset(bit,0,sizeof bit);
	sort(node+1,node+n+1);
	int res = 0;
	multiset<int> rem;
	rem.clear();
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	while(~scanf("%d %d %d",&n,&W,&H)){
		top = 0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].v);
			num[++top] = node[i].y;
			num[++top] = node[i].y + H;
		}
		printf("%d\n",solve());
	}
	return 0;
}

