                                            
  //File Name: cf120J.cpp
  //Created Time: 2017年04月30日 星期日 19时05分45秒
                                   
#include <bits/stdc++.h>
#define Point pair<double,double>
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 100000 + 5;
const double INF = 1e12;
Point a[MAXN];
map<Point,int> id;
map<int,int> dir;
int cal_dir(int x,int y){
	if(x == y) return 1;
	if(x == 1) return y;
	if(y == 1) return x;
	if(x == 2){
		if(y == 3) return 4;
		if(y == 4) return 3;
	}
	if(x == 3){
		if(y == 2) return 4;
		if(y == 4) return 2;
	}
	if(x == 4){
		if(y == 2) return 3;
		if(y == 3) return 2;
	}
	return 0;
}
bool compare_y(Point x,Point y){
	return x.sec < y.sec;
}
vector<Point> b;
pair<double,pii> closest_pair(Point *a,int n){
	if(n <= 1) return make_pair(INF,pii(-1,-1));
	int m = n / 2;
	double x = a[m].fir;
	pair<double,pii> res = min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a + m,a + n,compare_y);
//	printf("n = %d\n",n);
//	for(int i=0;i<n;++i){
//		printf("%lf %lf\n",a[i].fir,a[i].sec);
//	}
//	puts("");
	b.clear();
	for(int i=0;i<n;++i){
		if(fabs(a[i].fir - x) >= res.fir) continue;
		for(int j=0;j<b.size() && j < 7;++j){
			Point cur = b[b.size() - j - 1];
			double dx = a[i].fir - cur.fir;
			double dy = a[i].sec - cur.sec;
			if(dy >= res.fir) break;
			double dis = sqrt(dx * dx + dy * dy);
			if(dis < res.fir){
				int u = id[a[i]];
				int v = id[cur];
				if(u > v) swap(u,v);
				res = pair<double,pii>(dis,pii(u,v));
			}
		}
		b.push_back(a[i]);
	}
	return res;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	double x,y;
	int u(-1),v(-1);
	for(int i=0;i<n;++i){
		scanf("%lf %lf",&x,&y);
		if(x >= 0 && y >= 0) dir[i] = 1;
		else if(x >= 0 && y < 0) dir[i] = 3;
		else if(x < 0 && y >= 0) dir[i] = 2;
		else dir[i] = 4;
		a[i] = make_pair(fabs(x),fabs(y));
		if(id.count(a[i])){
			u = id[a[i]];
			v = i;
			break;
		}
		id[a[i]] = i;
	}
	if(u == -1){
		sort(a,a + n);
		pair<double,pii> ans = closest_pair(a,n);
		u = ans.sec.fir;
		v = ans.sec.sec;
	}
	printf("%d %d %d %d\n",u + 1,cal_dir(dir[u],1),v + 1,cal_dir(dir[v],4));
	return 0;
}
