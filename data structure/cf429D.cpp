                                            
  //File Name: cf429D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年03月22日 星期二 20时38分38秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#define LL long long
#define fir first
#define sec second
#define P pair<LL,LL>
#define mp make_pair

using namespace std;

const int MAXN = 100000+5;
const LL INF = 0x3f3f3f3f3f3f3f;

P p[MAXN];
P b[MAXN];
int a[MAXN];

bool cmp_y(P x,P y){
	return x.sec < y.sec;
}

LL cp(P *ds,int n){
	if(n <= 1)
		return INF;
	int m = n / 2;
	LL  x = ds[m].fir;
	LL d = min(cp(ds,m),cp(ds + m,n - m));
	inplace_merge(ds,ds + m,ds + n,cmp_y);

	int tot = 0;
	for(int i=0;i<n;i++){
		if(fabs(ds[i].fir - x) >= d)
			continue;
		for(int j=0;j<tot && j < 7;j++){
			LL dx = ds[i].fir - b[tot - 1 - j].fir;
			LL dy = ds[i].sec - b[tot - 1 - j].sec;
			if(dy >= d)
				break;
			d = min(d,dx * dx + dy * dy);
		}
		b[tot++] = ds[i];
	}
	return d;
}

void solve(int n){
	LL cur = 0;
	for(int i=0;i<n;i++){
		cur = cur + a[i];
		p[i] = mp(i,cur);
	}
	//sort(p,p+n);
	printf("%I64d\n",cp(p,n));
	return ;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	solve(n);
	return 0;
}
