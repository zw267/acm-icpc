                                            
  //File Name: cf617D.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年01月24日 星期日 00时32分03秒
                                   


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#define LL long long
#define x first
#define y second

using namespace std;

pair<LL,LL> node[3];

int solve()
{
	if(node[0].x == node[1].x && node[0].x == node[2].x)
		return 1;
	if(node[0].y == node[1].y && node[0].y == node[2].y)
		return 1;

	if(node[0].x == node[1].x || node[0].x == node[2].x || node[1].x == node[2].x){
		if(node[0].x == node[2].x){
			swap(node[1],node[2]);
		}
		else if(node[1].x == node[2].x){
			swap(node[0],node[2]);
		}

		if(node[0].y > node[1].y)
			swap(node[0],node[1]);

		if(node[2].y >= node[1].y || node[2].y <= node[0].y)
			return 2;
		else
			return 3;
	}

	if(node[0].y == node[1].y || node[0].y == node[2].y || node[1].y == node[2].y){
		if(node[0].y == node[2].y){
			swap(node[1],node[2]);
		}
		else if(node[1].y == node[2].y){
			swap(node[0],node[2]);
		}

		if(node[0].x > node[1].x)
			swap(node[0],node[1]);

		if(node[2].x >= node[1].x || node[2].x <= node[0].x)
			return 2;
		else
			return 3;
	}

	return 3;
}

int main()
{
	for(int i=0;i<3;i++){
		cin >> node[i].x >> node[i].y;
	}

	cout << solve() << endl;

	return 0;
}
