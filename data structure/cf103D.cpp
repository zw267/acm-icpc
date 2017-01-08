                                            
  //File Name: cf103D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月06日 星期三 23时45分41秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

#define LL long long
#define x(i) query[(i)].x
#define y(i) query[(i)].y
#define id(i) query[(i)].id

using namespace std;

const int MAXN = 300000 + 3;

struct Query{
	int x,y,id;
	Query(int _x = 0,int _y = 0,int _id = 0){
		x = _x,y = _y,id = _id;
	}
	bool operator < (const Query& t) const{
		return y < t.y;
	}
};
Query query[MAXN];
int a[MAXN];
LL f[MAXN];
LL ans[MAXN];

void solve(int n,int m){
	int s = sqrt(n + 0.5);
	sort(query+1,query+m+1);
	memset(f,-1,sizeof f);
	int pre = -1;
	for(int i=1;i<=m;i++){
		if(y(i) >= s){
			ans[id(i)] = 0;
			for(int j=x(i);j<=n;j+=y(i)){
				ans[id(i)] += a[j];
			}
		}
		else{
			if(y(i) != pre){
				for(int j=n;j>0;j--){
					if(j + y(i) > n)
						f[j] = a[j];
					else
						f[j] = f[j+y(i)] + a[j];
				}
			}
			ans[id(i)] = f[x(i)];
			pre = y(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << endl;
	}
	return ;
}

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x(i),&y(i));
		id(i) = i;
	}
	//puts("eeeeeeeeeeee");
	solve(n,m);
	return 0;
}
