                                            
  //File Name: cf27E.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月09日 星期三 21时28分09秒
                                   
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const LL MAXN= 1e18;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31};
LL res,n;
void dfs(LL now,LL sum,int p){
	if(now >= res || sum > n || p >= 11) return ;
	if(sum == n){
		res = now;
		return ;
	}
	for(int i=1;i<65;i++){
		if(now * prime[p] >= res) break;
		else
			dfs(now*=prime[p],sum * (i + 1),p + 1);
	}
}
int main(){
	cin >> n;
	res = MAXN;
	dfs(1,1,0);
	cout << res << endl;
	return 0;
}
