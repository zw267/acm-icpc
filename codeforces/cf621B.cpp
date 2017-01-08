                                            
  //File Name: cf621B.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年02月01日 星期一 20时14分30秒
                                   
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define x first
#define y second
#define LL long long

using namespace std;

const int MAXN = 1005;

bool has[MAXN][MAXN];

void solve()
{
	LL ans = 0;
	for(int i=1;i<=1000;i++){
		int x = i;
		int y =1;
		LL cur = 0;
		while(x <= 1000 && y <= 1000){
			if(has[x][y])
				cur++;
			x++;
			y++;
		}
		ans += cur * (cur - 1) / 2;
	}
	//cout << ans << endl;
	for(int i=1;i<=1000;i++){
		int x = i;
		int y = 1000;
		LL cur = 0;
		while(x <= 1000 && y > 0){
			if(has[x][y])
				cur++;
			x++;
			y--;
		}
		ans += cur * (cur - 1) / 2;
	}
	//cout << ans << endl;

	for(int j=2;j<1000;j++){
		int x = 1;
		int y = j;
		LL cur = 0;
		while(x <= 1000 && y <= 1000){
			if(has[x][y])
				cur++;
			x++;
			y++;
		}
		ans += cur * (cur - 1) / 2;
		x = 1;
		y = j;
		cur = 0;
		while(x <= 1000 && y > 0){
			if(has[x][y])
				cur++;
			x++;
			y--;
		}
		ans += cur * (cur - 1) / 2;
	}

	cout << ans << endl;
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(has,false,sizeof has);
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		has[x][y] = true;
	}
	solve();

	return 0;
}
