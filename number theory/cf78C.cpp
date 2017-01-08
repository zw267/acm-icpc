                                            
  //File Name: cf78C.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月18日 星期日 18时52分50秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> cal(LL x){
	vector<LL> res;
	for(LL i = 1;i * i <= x;++i){
		if(x % i == 0){
			res.push_back(i);
			if(x / i != i)
				res.push_back(x / i);
		}
	}
	return res;
}
bool solve(LL n,LL m,LL k){
	if(!(n & 1)) return false;
	vector<LL> dive = cal(m);
	for(int i=0;i<dive.size();++i){
		if(k <= dive[i] && m / dive[i] > 1) 
			return true;
	}
	return false;
}
int main(){
	LL n,m,k;
	cin >> n >> m >> k;
	if(solve(n,m,k)) puts("Timur");
	else puts("Marsel");
	return 0;
}
