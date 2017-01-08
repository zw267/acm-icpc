                                            
  //File Name: cf617C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月24日 星期日 00时01分42秒

/*

题意：一个花园，给出n朵花的坐标，然后再给出2个喷洒水的点的坐标，
问这2个点的半径r0,r1至少为多少，才可以使得花至少被一个点覆盖到，
同时要使得r0^2 + r1^2 尽量少

思路：
排序花，按照到r0的距离小到大排序
先把所有的花分配给r0,此时r1=0
然后把花从最远的开始不断分配给r1,此时r0减少，r1增加
同时不断更新答案
直至所有的花都分配给了r1

注意：不用开方

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define x first
#define y second

using namespace std;

const int MAXN = 2005;

pair<LL,LL> dis[MAXN];
pair<LL,LL> s[MAXN];

LL get_dis(pair<LL,LL> a,LL b,LL c)
{
	return (a.x - b) * (a.x - b) + (a.y - c) * (a.y - c);
}

void solve(int n)
{
	sort(dis,dis+n);

	LL r0 = dis[n-1].x;
	LL r1 = 0LL;

	LL ans0 = r0,ans1 = r1;

	for(int i=n-1;i>=0;i--){
		if(i == 0)
			r0 = 0;
		else
			r0 = dis[i-1].x;

		if(dis[i].y <= r1)
			;
		else
			r1 = dis[i].y;

		if(r0 + r1 <= ans0 + ans1){
			ans0 = r0;
			ans1 = r1;
		}
	}

	cout << ans0 + ans1 << endl;
	return ;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<2;i++)
		cin >> s[i].x >> s[i].y;
	for(int i=0;i<n;i++){
		LL tmpa ,tmpb;
		cin >> tmpa >> tmpb;
		LL cnta,cntb;
		cnta = get_dis(s[0],tmpa,tmpb);
		cntb = get_dis(s[1],tmpa,tmpb);
		dis[i] = make_pair(cnta,cntb);
	}

	solve(n);

	return 0;
}
