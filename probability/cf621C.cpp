                                            
  //File Name: cf621C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月12日 星期五 19时42分02秒
                                   

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000+5;

int l[MAXN];
int r[MAXN];
double pro[MAXN];

void solve(int n,int p)
{
	for(int i=0;i<n;i++){
		pro[i] = (r[i]/p - (l[i]-1)/p + 0.0) / (r[i]-l[i]+1.0);
	}
	double ans = 0.0;
	for(int i=0;i<n;i++){
		ans += 2000.0 * (pro[i] + pro[(i+1)%n] - pro[i] * pro[(i+1)%n]);
	}

	printf("%.8f\n",ans);
	return ;
}

int main()
{
	int n,p;
	while(~scanf("%d %d",&n,&p)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&l[i],&r[i]);
		}
		solve(n,p);
	}
	return 0;
}
