                                            
  //File Name: cf225E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月19日 星期一 17时50分07秒
                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int table[]={
    1,
    2,
    3,
    5,
    7,
    13,
    17,
    19,
    31,
    61,
    89,
    107,
    127,
    521,
    607,
    1279,
    2203,
    2281,
    3217,
    4253,
    4423,
    9689,
    9941,
    11213,
    19937,
    21701,
    23209,
    44497,
    86243,
    110503,
    132049,
    216091,
    756839,
    859433,
    1257787,
    1398269,
    2976221,
    3021377,
    6972593,
    13466917,
    20996011,
    24036583
};

const int P = (int)1e9 + 7;
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	int t = table[n] - 1;
	LL ans = qp(2,t);
	cout << (ans - 1 + P) % P << endl;
	return 0;
}
