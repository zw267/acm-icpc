                                            
  //File Name: 24.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月03日 星期四 10时52分12秒
                                   
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 11;
bool use[MAXN];
int p[MAXN],n,jie[MAXN];
int cal(int i,int x){
	int u = 0;
	for(int j=1;j<i;j++)
		if(p[j] < x) u++;
	u = x - 1 - u;
	int res = u * jie[n - i];
	return res;
}
void solve(){
	memset(use,false,sizeof(use));
	int less = 1000000;
	for(int i=1;i<=10;i++){
		for(int j=10;j>0;j--){
			if(use[j]) continue;
			int now = cal(i,j);
			if(now < less){
				p[i] = j;
				less -= now;
				break;
			}
		}
	}
}
int main(){
	jie[0] = 1;
	for(int i=1;i<MAXN;i++) jie[i] = jie[i-1] * i;
	n = 10;
	solve();
	for(int i=1;i<=10;i++)
		cout << p[i] - 1;
	return 0;
}
