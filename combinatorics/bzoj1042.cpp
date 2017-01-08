                                            
  //File Name: bzoj1042.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年04月16日 星期六 10时12分44秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long

using namespace std;

const int MAXN = 100000 + 2;

LL f[MAXN];
int c[4],d[4];

void init(){
	memset(f,0,sizeof f);
	f[0] = 1;
	for(int i=0;i<4;i++){
		for(int j=c[i];j<MAXN;j++){
			f[j] += f[j - c[i]];
		}
	}
}

void solve(int s){
	LL ans = f[s];
	int num;
	LL now;
	for(int i=1;i<16;i++){
		num = 0;
		now = 0;
		for(int j=0;j<4;j++){
			if(i & (1 << j)){
				num++;
				now += (LL)c[j] * (d[j] + 1);
			}
		}
		num %= 2;
		if(num && s >= now)
			ans = ans - f[s - now];
		else if(!num && s >= now)
			ans = ans + f[s - now];
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	for(int i=0;i<4;i++){
		scanf("%d",&c[i]);
	}
	init();
	int q,s;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		for(int j=0;j<4;j++)
			scanf("%d",&d[j]);
		scanf("%d",&s);
		solve(s);
	}
	return 0;
}
