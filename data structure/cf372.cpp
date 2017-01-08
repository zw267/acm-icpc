                                            
  //File Name: cf372.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月31日 星期四 20时27分01秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

const int MAXN = 150000 + 5;
const int MAXM = 305;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Node{
	int t,a,b;
};
Node node[MAXM];
LL f[MAXN];
LL deqv[MAXN];
int deq[MAXN];

LL fab(LL x){
	if(x < 0)
		return -x;
	return x;
}

void solve(int n,int m,int d){
	memset(f,0,sizeof f);
	node[0].t = node[1].t;
	for(int i=1;i<=m;i++){
		int s = 0,t = 0;
		int pos = 1;
		LL dis = (LL)d * (node[i].t - node[i-1].t);
		for(int j=1;j<=n;j++){
			while(pos <= n && j + dis >= pos){
				while(s < t && deqv[t - 1] <= f[pos])
					t--;
				deqv[t] = f[pos];
				deq[t++] =  pos;
				pos++;
			}
			f[j] = deqv[s] + node[i].b - fab(node[i].a - j);
			if(deq[s] + dis == j)
				s++;
		}
	}
	LL ans = -INF;
	for(int i=1;i<=n;i++){
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return ;
}

int main(){
	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&node[i].a,&node[i].b,&node[i].t);
	}
	solve(n,m,d);
	return 0;
}

