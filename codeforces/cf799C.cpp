                                            
  //File Name: cf799C.cpp
  //Created Time: 2017年05月15日 星期一 12时29分21秒
                                   
#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
vector<pii> a,b;
int p[MAXN],ma[MAXN];
int N;
//给出一个pii数组(x,y)，从中找出y1 + y2 <= c ,max(x1 + x2)
//在100000范围内
int cal(const vector<pii> &a,const int c){
	int res(0);
	memset(p,0,sizeof p);
	for(auto cur:a){
		if(p[cur.sec] && cur.sec * 2 <= c) 
			res = max(res,p[cur.sec] + cur.fir);
		p[cur.sec] = max(p[cur.sec],cur.fir);
	}
	ma[0] = 0;
	for(int i(1);i<=c;++i)
		ma[i] = max(ma[i - 1],p[i]);
	for(int i(c);i>=0;--i){
		if(p[i] == 0) continue;
		int cur = min(c - i,i - 1);
		if(ma[cur])
			res = max(res,ma[cur] + p[i]);
	}
/*
	int res2(0);
	int x,y;
	for(int i=0;i<a.size();++i){
		for(int j=i+1;j<a.size();++j){
			pii u = a[i],v = a[j];
			if(u.sec + v.sec <= c && u.fir + v.fir > res2){
				res2 = u.fir + v.fir;
				x = u.sec;
				y = v.sec;
			}
		}
	}
	if(res2 != res){
		printf("x = %d y = %d\n",x,y);
		printf("px = %d py = %d\n",p[x],p[y]);
	}
*/
	return res;
}
int solve(const int n,const int c,const int d){
	N = n;
	int c1(0),d1(0);
	for(auto cur:a)
		c1 = max(c1,cur.fir);
	for(auto cur:b)
		d1 = max(d1,cur.fir);
	int res = c1 + d1;
	if(c1 == 0 || d1 == 0) res = 0;
	int c2 = cal(a,c);
	int d2 = cal(b,d);
	return max(res,max(c2,d2));
}
int main(){
	int n,c,d;
	char str[3];
	scanf("%d %d %d",&n,&c,&d);
	for(int i(0),u,v;i<n;++i){
		scanf("%d %d %s",&u,&v,str);
		if(str[0] == 'C' && v <= c)
			a.push_back(pii(u,v));
		else if(str[0] == 'D' && v <= d)
			b.push_back(pii(u,v));
	}
	printf("%d\n",solve(n,c,d));
	return 0;
}
