                                            
  //File Name: hdu5618.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年07月29日 星期五 17时42分21秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>

#define LL long long

using namespace std;

const int MAXN = 100000 + 3;

struct Query{
	int t,x,y,z;
	Query(int _t=0,int _x=0,int _y=0,int _z=0){
		t = _t,x = _x,y = _y,z = _z;
	}
	bool operator<(const Query &a)const{
		if(y == a.y) return t < a.t;
		return y < a.y;
	}
}que[MAXN],q1[MAXN],q2[MAXN];

int ans[MAXN],bit[MAXN],N;

void update(int x,int add){
	while(x <= N){
		bit[x] += add;
		x += x & (-x);
	}
}

int query(int x){
	int res = 0;
	while(x){
		res += bit[x];
		x -= x & (-x);
	}
	return res;
}

bool cmp(Query &a,Query &b){
	if(a.x == b.x){
		if(a.y == b.y){
			if(a.z == b.z) return ans[a.t] < ans[b.t];
			return a.z < b.z;
		}
		return a.y < b.y;
	}
	return a.x < b.x;
}

void cdq(int l,int r){
	if(l >= r) return ;
	int mid = (l + r) >> 1;
	cdq(l,mid);
	cdq(mid+1,r);
	int s1 = 0,s2 = 0;
	for(int i=l;i<=mid;i++)
		q1[s1++] = que[i];
	for(int i=mid+1;i<=r;i++)
		q2[s2++] = que[i];
	sort(q1,q1+s1);
	sort(q2,q2+s2);
	int u = 0;
	for(int i=0;i<s2;i++){
		while(u < s1 && q1[u].y <= q2[i].y){
			update(q1[u].z,1);
			u++;
		}
		ans[q2[i].t] += query(q2[i].z);
	}
	for(int i=0;i<u;i++){
		update(q1[i].z,-1);
	}
}

void solve(int n){
	memset(ans,0,sizeof(ans));
	sort(que+1,que+n+1,cmp);
	cdq(1,n);
	//for(int i=1;i<=n;i++)
	//	printf("%d\n",ans[i]);
	sort(que+1,que+n+1,cmp);
	for(int i=n-1;i>0;i--){
		if(que[i].x == que[i+1].x && 
		   que[i].y == que[i+1].y &&
		   que[i].z == que[i+1].z)
			ans[que[i].t] = max(ans[que[i].t],ans[que[i+1].t]);
	}
	for(int i=1;i<n;i++){
		if(que[i].x == que[i+1].x &&
		   que[i].y == que[i+1].y &&
		   que[i].z == que[i+1].z)
			ans[que[i].t] = max(ans[que[i].t],ans[que[i+1].t]);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}

int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		N = 0;
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%d %d %d",&x,&y,&z);
			que[i] = (Query){i,x,y,z};
			if(z > N) N = z;
		}
		solve(n);
	}
	return 0;
}
