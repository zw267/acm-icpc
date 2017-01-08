                                            
  //File Name: 301.cpp
  //Author: long
  //Mail: 736726758@qq.com
  //Created Time: 2016年11月04日 星期五 01时00分36秒
                                   
#include <iostream>
#define LL long long
using namespace std;
LL solve(){
	LL ma = (1LL << 30);
	LL res = 0;
	for(LL i=1;i<=ma;i++){
		LL now = i;
		now ^= (2 * i);
		now ^= (3 * i);
		if(now == 0)
			res++;
	}
	return res;
}
int main(){
	cout << solve() << endl;
}
