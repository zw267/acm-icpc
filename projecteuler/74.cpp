                                            
  //File Name: 74.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 22时31分45秒
                                   
#include <iostream>
#include <set>
#include <map>
#define LL long long
using namespace std;
int solve(int n){
	int jie[10];
	jie[0] = 1;
	for(int i=1;i<10;i++) jie[i] = jie[i-1] * i;
	int res = 0,ma = 1000000;
	set<LL> rem;
	for(int i=1;i<ma;i++){
		rem.clear();
		LL x = i;
		while(1){
			if(rem.find(x) != rem.end()) break;
			rem.insert(x);	
			LL y = 0;
			while(x){
				y += jie[x % 10];
				x /= 10;
			}
			x = y;
		}
		if(rem.size() == n) res++;
	}
	return res;
}
int main(){
	cout << solve(60) << endl;
	return 0;
}
