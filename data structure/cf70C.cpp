                                            
  //File Name: cf70C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年05月03日 星期二 23时09分43秒
                                   

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>

#define LL long long
#define fir first
#define sec second
#define mp make_pair

using namespace std;

const int MAXN = 100000 + 5;

map< pair<int,int>,int > remx,remy;
int d[MAXN];
int rev[MAXN];

int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x % y);
}

int get_rev(int x){
	int res = 0,a;
	while(x){
		a = x % 10;
		res = res * 10 + a;
		x /= 10;
	}
	return res;
}

void init(int ma){
	remx.clear(), remy.clear();
	for(int i=1;i<=ma;i++)
		rev[i] = get_rev(i);
	for(int i=1;i<=ma;i++){
		d[i] = gcd(i,rev[i]);
		remy[mp(i / d[i],rev[i] / d[i])]++;
	}
}

void solve(int max_x,int max_y,int W){
	bool flag = false;
	if(max_x > max_y){
		swap(max_x,max_y);
		flag = true;
	}
	init(max_y);
	int x = 1,y = max_y;
	int now = remy[mp(1,1)];
	remx[mp(1,1)]++;
	int ans_x = -1,ans_y = -1;
	while(x <= y){
		while(x < y && x < max_x && now < W){
			x++;
			remx[mp(rev[x] / d[x],x / d[x])]++;
			now += remy[mp(rev[x] / d[x],x / d[x])];
		}
		if(now < W) break;
		//printf("x = %d y = %d now = %d W = %d\n",x,y,now,W);
		if(ans_x == -1 || (LL)x * y < (LL)ans_x * ans_y){
			ans_x = x,ans_y = y;
		}
		remy[mp(y / d[y],rev[y] / d[y])]--;
		now -= remx[mp(y / d[y],rev[y] / d[y])];
		y--;
	}
	if(flag)
		swap(ans_x,ans_y);
	if(ans_x == -1)
		puts("-1");
	else
		printf("%d %d\n",ans_x,ans_y);
	return ;
}

int main(){
	int max_x,max_y,W;
	while(~scanf("%d %d %d",&max_x,&max_y,&W)){
		solve(max_x,max_y,W);
	}
	return 0;
}

