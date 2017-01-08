                                            
  //File Name: cf633E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月06日 星期五 23时58分54秒
                                   

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdlib.h>

#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 1000000 + 5;

int v[MAXN];
int c[MAXN];
pii p[MAXN];
double g[MAXN];

void solve(int n,int k){
	if(v[n] <= c[n])
		p[n] = mp(v[n],1);
	else
		p[n] = mp(c[n],0); 
	for(int i=n-1;i>0;i--){
		if(c[i] < v[i])
			p[i] = mp(c[i],0);
		else if(p[i + 1].fir <= v[i])
			p[i] = mp(v[i],1);
		else{
			if(p[i + 1].fir > c[i])
				p[i] = mp(c[i],0);
			else
				p[i] = p[i + 1];
		}
	}
	sort(p + 1,p + n + 1);
	//for(int i=1;i<=n;i++)
	//	printf("%d %d\n",p[i].fir,p[i].sec);
	g[1] = (k + 0.0) / (n + 0.0);
	for(int i=2;i<=n -k + 1;i++){
		g[i] = g[i - 1] * (n - k - i + 2.0) / (n - i + 1.0);
	}
	//for(int i=1;i<=n - k + 1;i++)
	//	printf("%.6f\n",g[i]);
	double ans = 0.0;
	for(int i=1;i<=n - k + 1;i++){
		ans += g[i] * p[i].fir;
	}
	printf("%.10f\n",ans);
	return ;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		v[i] *= 100;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	solve(n,k);
	return 0;
}
