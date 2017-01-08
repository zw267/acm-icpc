                                            
  //File Name: nod1060.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年12月17日 星期六 19时39分21秒
                                   
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL INF = 1000000000000000000 + 1;
LL n,ans,num;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void dfs(int i,int limit,LL now,LL now_num){
	if(i >= 16) return ;
	if(now > n) return ;
	if(now_num > num){
		num = now_num;
		ans = now;
	}
	if(now_num == num && ans > now)
		ans = now;
	for(int j=1;j<=limit;j++){
//		LL pre = now;
//		now *= p[i];
//		if(now > n || now <= pre) break;
		double cur = (double)now;
		if(cur * p[i] > n) break;
		now *= p[i];
		dfs(i+1,j,now,now_num * (j + 1));
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ans = INF,num = 0;
		dfs(0,60,1,1);
		cout << ans << " " << num << endl;
	}
	return 0;
}
